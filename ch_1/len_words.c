#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 20
#define STAR 42
#define NEWLINE 10

/* count lengths of words in input */

main()
{
  int i, j, c, wl, state;
  int nword[MAX_WORD_LENGTH];
  char bin[MAX_WORD_LENGTH];
  
  state = wl = OUT;

  /* initialize word size array */
  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    nword[i] = 0;
    bin[i] = 0;
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

  printf("word count:\n");
  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    printf("%3d : ", i);
    for (j = 0; j < nword[i]; ++j) {
      putchar(STAR);
    }
    putchar(NEWLINE);
  }
}
