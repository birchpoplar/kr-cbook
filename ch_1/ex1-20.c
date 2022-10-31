#include <stdio.h>

#define TABLEN 8

int main()
{
  int c, pos, i;

  pos = 0;
  
  while ((c=getchar()) != EOF)
    {
      if (c != '\t' && c != '\n') {
	putchar(c);
	++pos;
	if (pos == TABLEN)
	  pos = 0;
      } else if (c == '\n') {
	putchar(c);
	pos = 0;
      } else {
	for (i = 0; i < (TABLEN - pos); ++i)
	  putchar('-');
	pos = 0;
      }
    }
}
