#include <stdio.h>

#define LIM 100

int main()
{
  int i, lim;
  char c;
  char s[LIM];

  /* Original for loop */
  
  for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;

  /* Rewritten without && or || */
  
  for (i=0; i<lim-1; ++i) {
    if ((c=getchar()) != '\n') {
      if (c != EOF)
	s[i] = c;
    }
  }
}
