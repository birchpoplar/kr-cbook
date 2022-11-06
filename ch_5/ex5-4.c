#include <stdio.h>

int strend(char *s, char *t);

int main()
{
  char s[] = "testing";
  char t[] = "ting";

  printf("1 = match, 0 = no match :: %d\n", strend(s, t));
  return 0;
}

int strend(char *s, char *t)
{
  while (*s != '\0') {
    for ( ; (*s != *t) && (*s != '\0'); s++)
      ;
    for ( ; (*s == *t) && (*s != '\0'); s++, t++)
      ;
  }
  if ((*s == '\0') && (*t == '\0'))
    return 1;
  return 0;  
}
