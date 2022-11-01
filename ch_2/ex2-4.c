#include <stdio.h>

#define YES 1
#define NO 0

#define MAX 20

void squeeze(char s1[], char s2[]);
int check(char c, char s[]);

int main() {

  char s1[] = "scumblydumplyscrumptiousbeenieboop";
  char s2[] = "scyo";
  
  printf("%s :: %s\n", s1, s2);
  squeeze(s1,s2);
  printf("---> %s\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j;
  char tmp[MAX];

  for (i=j=0; s1[i] != '\0'; ++i) {
    if (check(s1[i], s2) == NO)
      tmp[j++] = s1[i]; 
  }
  for (i=0; i < j; ++i)
    s1[i] = tmp[i];
  s1[j] = '\0';
}

int check(char c, char s[])
{
  int i, ans;

  ans = NO;
  
  for (i=0; s[i] != '\0'; ++i)
    if (s[i] == c)
      ans = YES;

  return ans;
}
