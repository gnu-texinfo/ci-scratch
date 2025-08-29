#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

void (*fooptr) (void);

char *shared_libs[] = {
  ".libs/lib1.so.0.0.0",
  /* OpenBSD */
  ".libs/lib1.so.0.0",
  /* on macos */
  ".libs/lib1.0.so",
  /* mingw on cygwin */
  ".libs/lib1-0.dll",
  /* cygwin */
  ".libs/cyg1-0.dll",
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

  char *shared_lib = 0;
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
  /* absolute path required on OpenBSD */
  char *absolute_library_name;
  asprintf (&absolute_library_name, "%s/%s", cwd, shared_lib);

  void *handle;

  char *library_names[2] = {shared_lib, absolute_library_name};
  char *errors[2] = {0, 0};

  for (i = 0; i < 2; i++)
    {
      char *library_name = library_names[i];
      handle = dlopen (library_name, RTLD_LAZY);

      if (!handle)
        {
          char *error = dlerror ();
          errors[i] = error;
        }
      else
        break;
    }
  if (!handle)
    {
      for (i = 0; i < 2; i++)
        {
          char *library_name = library_names[i];
          char *error = errors[i];
          if (errors[i])
            printf ("%s: dlopen error: %s\n", library_name, error);
          else
            printf ("%s: dlopen error\n", library_name);
        }
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
