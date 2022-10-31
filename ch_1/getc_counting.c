#include <stdio.h>

/* counting from getchar() */

main()
{
  int c, nl, nb, nt;

  nl = 0;
  nt = 0;
  nb = 0;
  
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;
    else if (c == '\t')
      ++nt;
    else if (c == ' ')
      ++nb;
  printf("Newlines: %d\n", nl);
  printf("Tabs: %d\n", nt);
  printf("Blanks: %d\n", nb);
}
