#include <stdio.h>

#define YES 1
#define NO 0

int check(char c, char s[]);
int any(char s1[], char s2[]);


int main()
{
  char s1[] = "scrumblydumptious";
  char s2[] = "ylb";
  char s3[] = "scrumblydumptious";
  char s4[] = "xzq";

  printf("%s :: %s\n", s1, s2);
  printf("first found := %d\n", any(s1,s2));
  printf("%s :: %s\n", s3, s4);
  printf("first found := %d\n", any(s3,s4));

  return 0;
}

int any(char s1[], char s2[])
{
  int i, pos;
  pos = -1;

  for (i=0; s1[i] != '\0' && pos < 0; ++i) {
    if (check(s1[i], s2) == YES) {
      pos = i;
    }
  }
  return pos;
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
