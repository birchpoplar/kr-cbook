#include <stdio.h>

#define MAXSIZE 10

void strncpy2(char *s, char *ct, int n);

int main()
{
  char s[10]; 
  char ct[] = "testing";
  int n = 5;

  strncpy2(s, ct, n);
  
  printf("copy for %d: %s\nresult: %s\n", n, ct, s);
  return 0;
}

void strncpy2(char *s, char *ct, int n)
{
  for (int i=0; (*ct != '\0') && (i++ != n); *s++ = *ct++)
    ;  
  *s = '\0';  
  return;
}
