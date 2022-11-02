#include <stdio.h>
#include <ctype.h>

#define LINESIZE 100

int getline2(char s[], int lim);
void expand(char s1[], char s2[]);


int main()
{
  char s1[LINESIZE];
  char s2[LINESIZE];
  int len;

  len = getline2(s1,LINESIZE);
  expand(s1,s2);

  printf("strt:%soutp:%s", s1, s2);

  return 0; 
}


int getline2(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c== '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}


void expand(char s1[], char s2[])
{
  int i,j,k;
  char prev, curr;
  
  for (i=0, j=0; s1[i] != '\0'; ++i) {
    if (s1[i] != '-') {
      s2[j++] = s1[i];
    } else if (i == 0 || s1[i+1] == '\n') {
      s2[j++] = '-';
    } else {
      for (k=s1[i-1]+1; k < s1[i+1]; ++k) {
	s2[j++]=k;
      }
    }
  }
}
