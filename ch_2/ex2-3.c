#include <stdio.h>
#include <ctype.h>


int htoi(char h[]);

int main()
{
  char msg[] = "6F5ABefeb6";

  printf("Hex: %s\n", msg);
  printf("Int: %d\n", htoi(msg));
  
  return 0;
}

int htoi(char h[])
{
  int i, n, tmp, start, invalid;
  
  n = 0;
  start = 0;
  invalid = 0;

  if (h[0] == '0' && (h[1] == 'x' || h[1] == 'X'))
    start = 2;
  
  for (i=start; h[i] != '\0'; ++i) {
    if (isalpha(h[i])) {
      if (toupper(h[i]) > 'F'){
	printf("Invalid character %c at pos %d\n", h[i], i);
	invalid = 1;
	break;
      }
      tmp = (toupper(h[i]) - 'A' + 10);
    }
    else if (isdigit(h[i])) {
      tmp = h[i] - '0';
    }
    else {
      printf("Invalid character %c at pos %d\n", h[i], i);
      invalid = 1;
      break;
    }
    n = n * 16 + tmp;
  }
  if (invalid == 0)
    return n;
  else
    return 0;
}
