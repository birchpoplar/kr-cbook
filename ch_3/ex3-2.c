#include <stdio.h>

#define LINESIZE 100

int escape(char s[], char t[]);
int getline2(char s[], int lim);

int main()
{
  char s[LINESIZE];
  char t[LINESIZE];
  int len, len2;
  
  len = getline2(t, LINESIZE);
  len2 = escape(s, t);
  
  printf("%s :: %s\n)", t, s);
  printf("%d :: %d\n)", len, len2);
  
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

int escape(char s[], char t[]) {
  int i, j;
  j = 0;
  
  for (i=0; t[i] != '\0'; ++i) {
    switch (t[i]) {
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
    default:
      s[j++] = t[i];
    }
    s[j] = '\0';
  }
  return j;
}
