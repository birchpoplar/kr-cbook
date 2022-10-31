
#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 20
#define STAR 42
#define NEWLINE 10
#define SPACE 32
#define DASH 45

/* count lengths of words in input */

main()
{
  int i, j, c, wl, state, max;
  int nword[MAX_WORD_LENGTH];
  
  state = wl = max = OUT;

  /* initialize word size array */
  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    nword[i] = 0;
  }
    
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
	state = OUT;
	++nword[wl];
	wl = 0;
      }
    }
    else {
      if (state == OUT)
	state = IN;
      ++wl;
    }
  }

  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    if (nword[i] > max)
      max = nword[i];
  }
  
  printf("word count:\n");
  for (i = 0; i < MAX_WORD_LENGTH; ++i)
    printf("%2d ",i);
  putchar(NEWLINE);
  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    if (i < 10) {
      putchar(SPACE);
      putchar(DASH);
      putchar(SPACE);
    }
    else {
      putchar(DASH);
      putchar(DASH);
      putchar(SPACE);
    }
  }
  putchar(NEWLINE);
  for (j = 0; j < max; ++j) {
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
      putchar(SPACE);
      if (nword[i] > j) {
	putchar(STAR);
      }
      else {
	putchar(SPACE);
      }
      putchar(SPACE);
    }
    putchar(NEWLINE);
  }
}
