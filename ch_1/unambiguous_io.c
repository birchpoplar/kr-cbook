#include <stdio.h>

#define ASC_BSLASH putchar(92)
#define ASC_T putchar(116)
#define ASC_B putchar(98)

main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      ASC_BSLASH;
      ASC_T;
    }
    else if (c == '\b') {
      ASC_BSLASH;
      ASC_B;
    }
    else if (c == '\\') {
      ASC_BSLASH;
      ASC_BSLASH;
    }
    else
      putchar(c);
  }
}
