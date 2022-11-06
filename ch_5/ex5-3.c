#include <stdio.h>

void strcat2(char *s, char *t);

int main()
{
  char s[] = "testing";
  char t[] = "-andstilltesting";
  
  strcat2(s, t);
  printf("%s\n", s);
  return 0;
}

void strcat2(char *s, char *t)
{
  while (*s != '\0')
    s++;
  while ((*s++ = *t++))
    ;
} 
