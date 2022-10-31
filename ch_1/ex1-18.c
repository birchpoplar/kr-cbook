#include <stdio.h>
#include <string.h>

#define MAXLENGTH 150

void concat(char in1[], int len1, char in2[], int len2);

int main()
{
  int len, max, i, j, c, d = 0;
  char line[MAXLENGTH];
  char temp[MAXLENGTH];

  
  while ((c=getchar()) != EOF) {
    if (c == '\t' || c == ' ') {
      /* EAT TABS UNTIL \n OR OTHER */
      temp[j] = c;
      ++j;
      while ((c = getchar()) == '\t' || c == ' ') {
	temp[j] = c;
	++j;
      }
    
      if (c != '\n') {
	concat(line, i, temp, j);
	i = i+j;
      }
    }
    line[i] = c;
    ++i;
  }
  printf("%s", line);
  return 0;
}


void concat(char in1[], int len1, char in2[], int len2)
{
  int i = 0;

  while (i < len2) {
    in1[(len1)+i] = in2[i];
    ++i;
  }
}



