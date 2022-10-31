#include <stdio.h>

#define OUTSIDE 0
#define IN_COMMENT 1
#define IN_CONST 2
#define IN_STRING 3
#define YES 1
#define NO 0

int main()
{
  int c = 0;
  int status = OUTSIDE;
  int just_after = NO;
  
  while ((c=getchar()) != EOF)
    {
      if (status == OUTSIDE) {
	if (c != '/' && c != '"' && c != '\'')
	  putchar(c);
	else if (c == '/') {
	  if ((c=getchar()) == '*')
	    status = IN_COMMENT;
	  else {
	    putchar(47);
	    putchar(c); 
	  }
	} else if (c == '"' || c == '\'') {
	  status = IN_STRING;
	  putchar(c);
	}
      } else if (status == IN_COMMENT) {
	while ((c=getchar()) != EOF && status == IN_COMMENT) {
	  if (c == '*') {
	    if ((c=getchar()) == '/') {
	      status = OUTSIDE;
	      just_after = YES;
	    }
	  } /* Eat chars in comment */
	}
      } else if (status == IN_STRING) {
	putchar(c);
	while ((c=getchar()) != EOF && status == IN_STRING) {
	  putchar(c);
	  if (c == '"' || c == '\'') {
	    status = OUTSIDE;
	    just_after = YES;
	  }
	} 
      }
      if (status == OUTSIDE && just_after == YES) {
	putchar(c);
	just_after = NO;
      }
    }
}
