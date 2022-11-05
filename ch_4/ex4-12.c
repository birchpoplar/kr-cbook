#include <stdio.h>
#include <string.h>

#define MAXSIZE 20

void itoa(int n, char s[]);

int main()
{
  int n = -1999251645;
  char s[MAXSIZE];

  /* set s to zero length string to initialize */
  s[0] = '\0';
  
  printf("input: %d\n", n); 
  itoa(n, s);
  printf("result: %s\n", s);

  return 0;
}

void itoa(int n, char s[])
{
  char tmp[MAXSIZE];
  int i = 0;

  /* test for negative */
  if (n < 0) {
    tmp[i++] = '-';
    n = -n;
  }

  /* enter recursive loop */
  if (n / 10) {
    itoa(n / 10, s);
  }

  /* tmp contains char for current recursion */
  tmp[i++] = ('1' + (n % 10) - 1);
  tmp[i++] = '\0';

  /* concat the prior string to current recursion char */
  strcat(tmp, s);

  /* copy back into the main string */
  strcpy(s, tmp);

  /* set pointer for tmp string back to zero for next char */
  i = 0;
}
