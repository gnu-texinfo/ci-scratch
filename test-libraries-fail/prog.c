#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

void (*fooptr) (void);

const char *shared_libs[3] = {
  ".libs/lib1.so.0.0.0",
  ".libs/lib1.so.0.0",
  NULL};

int
main (void)
{
  char *cwd = getcwd (0, 0);
  if (!cwd)
    {
      puts ("could not call cwd");
      exit (1);
    }

  const char *shared_lib = 0;
  int i;
  for (i = 0; shared_libs[i]; i++)
    {
      struct stat sb;
      if (stat (shared_libs[i], &sb) == 0)
        {
          shared_lib = shared_libs[i];
          break;
        }
    }
  char *library_name;
  asprintf (&library_name, "%s/%s", cwd, shared_lib);

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
