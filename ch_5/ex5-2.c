#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
double getdbl(double *pn);

char buf[BUFSIZE];
int bufp = 0;

int main()
{
  double a;

  getdbl(&a);  
  printf("--> %f\n", a);
  return 0;
}

double getdbl(double *pn)
{
  int c, sign;
  float n;
  double pt;
  
  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    if (!isdigit(c = getch())) {
	ungetch(c);
	return 0;
    }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if (c == '.') {
    c = getch();
    for (pt = 0, n = 0.1; isdigit(c); c = getch(), n *= 0.1) {
      pt += n * (c - '0');
    }
  }
  *pn += pt;
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
