/* find-suffix.c: return a suffix. */

#include "types.h"
#include "find-suffix.h"
#include <string.h>


string
find_suffix (string name)
{
  string dot_pos = strrchr (name, '.');
#ifdef WIN32
  string slash_pos = strrchr (name, '\\');
#else
  string slash_pos = strrchr (name, '/');
#endif

  /* If the name is `foo' or `/foo.bar/baz', we have no extension.  */
  return
    dot_pos == NULL || dot_pos < slash_pos
    ? NULL
    : dot_pos + 1;
}

/* version 0.25 */
