#include <stdio.h>

int atoi2(char s[]);

int main() {
  char msg[] = "13545676";

  printf("STR version: %s\n", msg);
  printf("INT version: %d\n", atoi2(msg));

  return 0;
}

int atoi2(char s[])
{
  int i, n;

  n = 0;

  for (i=0; s[i] >= '0' && s[i] <= '9'; ++i) {
    printf("%d  n curr: %d  s: %c\n", i, n, s[i]);
    n = 10 * n + (s[i] - '0');
    printf("%d  n now: %d\n", i, n);
  }
  return n;
}
