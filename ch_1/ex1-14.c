#include <stdio.h>

#define IN 1
#define OUT 0
#define STAR 42
#define NEWLINE 10
#define MIN_ASCII 32
#define MAX_ASCII 126

/* count lengths of words in input */

main()
{
  int i, j, c, wl, state;
  int nchar[MAX_ASCII];
  int ascii[MAX_ASCII];
  
  state = wl = OUT;

  /* initialize word size array */
  for (i = 0; i < MAX_ASCII; ++i)
    nchar[i] = 0;
    
  while ((c = getchar()) != EOF) {
    ++nchar[c];
  }

  printf("char count:\n");
  for (i = MIN_ASCII; i < MAX_ASCII; ++i) {
    if (nchar[i] != 0)
      printf("%c (%d) : %d\n", i, i, nchar[i]);
  }
}
