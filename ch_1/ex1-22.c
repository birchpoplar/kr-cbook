#include <stdio.h>

#define WRAP 20

int main()
{
  int c, pos, i, col, last_spc, word_sz;
  char word[WRAP];
  
  pos = col = last_spc = word_sz = 0;
  
  while ((c=getchar()) != EOF)
    {
      ++col;
      if (c != ' ' && c != '\n') {
	word[word_sz] = c;
	++word_sz;
      } else if (c == ' ') {
	if (col <= WRAP) {
	  for (i = 0; i < word_sz; ++i)
	    putchar(word[i]);
	  putchar(' ');
          word_sz = 0;
	  last_spc = col;
	} else if (col > WRAP) {
	  putchar('\n');
	  for (i = 0; i < word_sz; ++i)
	    putchar(word[i]);
	  putchar(' ');
	  col = word_sz;
	  word_sz = 0;
	  last_spc = 0;
	}
	
      } else if (c == '\n') {
	for (i = 0; i < word_sz; ++i)
	  putchar(word[i]);
	putchar(c);
	col = word_sz = last_spc = 0;
      }
    }
}
