#include <stdio.h>

#define TABLEN 8

int main()
{
  int c, pos, i, spcs, count, adj;
  pos = spcs = 0;
  adj = 1;
  
  while ((c=getchar()) != EOF)
    {
      if (c != ' ' && c != '\n') {
	putchar(c);
	++pos;
	if (pos == (TABLEN))
	  pos = 0;
      } else if (c == '\n') {
	putchar(c);
	pos = 0;
      } else {
	spcs = 1;
	while ((c=getchar()) == ' ' && c != EOF)
	  ++spcs;
	/* fill up to first tab stop */
	if (pos < (TABLEN - 1) && pos > 0) {
	  putchar('\t');
	  spcs = spcs - (TABLEN - pos);
	} else if (pos == (TABLEN - 1)) {
	  putchar (' ');
	  spcs = spcs - 1;
	}
	if (spcs > TABLEN) {
	  for (i=0; i < (spcs/TABLEN); ++i) {
	    putchar('\t');
	  }
	}
	/* printf("%d %d %d", spcs, TABLEN, spcs/TABLEN); */
	for (i=0; i< (spcs - TABLEN * (spcs/TABLEN)); ++i) {
	  putchar(' ');
	}
	putchar(c);
	pos = spcs - TABLEN * (spcs/TABLEN);
      }
    }
  return 0;
}
