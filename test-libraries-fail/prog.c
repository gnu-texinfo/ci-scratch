#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void (*fooptr) (void);

#define SHARED_LIB ".libs/lib1.so.0.0.0"

int
main (void)
{
  char *cwd = getcwd (0, 0);
  if (!cwd)
    {
      puts ("could not call cwd");
      exit (1);
    }

  char *library_name;
  asprintf (&library_name, "%s/%s", cwd, SHARED_LIB);

  void *handle;

  /* absolute path required on OpenBSD */
  handle = dlopen (library_name, RTLD_LAZY);

  if (!handle)
    {
      char *error = dlerror ();
      if (error)
        printf ("dlopen error: %s\n", error);
      else
        printf ("dlopen error\n");

      exit (1);
    }
  fooptr = dlsym (handle, "foo");
  char *error = dlerror ();
  if (error)
    {
      printf ("dlsym error: %s\n", error);
      exit (1);
    }
  fooptr ();
  exit (0);
}
