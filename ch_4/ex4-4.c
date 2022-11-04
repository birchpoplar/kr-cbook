#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define COMMAND '1'
#define MAXVAL 100
#define BUFSIZE 100
#define TRUE 1
#define FALSE 0
#define DEBUG 1

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;
int sp = 0;
double val[MAXVAL];
int cmd;
enum commands {NON, PRT, DUP, SWP, CLR};

/* Reverse Polish Notation Calculator */
int main()
{
  int type;
  double op2;
  double op3;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
	push(pop() / op2);
      else printf("error : zero divisor\n");
      break;
    case '%':
      op2 = (int) pop();
      op3 = (int) pop();
      if (op2 != 0)
	push(op3 / op2);
      else printf("error : zero divisor\n");
      push(op3 - ((int) pop()) * op2);
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    case COMMAND:
      switch (cmd) {
      case PRT:
	if (sp > 0) {
	  op2 = pop();
	  printf("\t%.8g printed\n", op2);
	  push(op2);
	} else
	  printf("error: stack empty\n");
	break;
      case DUP:
	if (sp > 0) {
	    op2 = pop();
	    push(op2);
	    push(op2);
	    printf("\t%.8g duplicated\n", op2);
	} else
	  printf("error: stack empty\n");
	break; /* break from command switch */
      case SWP:
	if (sp > 1) {
	  op2 = pop();
	  op3 = pop();
	  push(op2);
	  push(op3);
	  printf("\t%.8g swapped\n", op2);
	  printf("\t%.8g\n", op3);
	} else
	  printf("error: insufficient stack size for swap\n");
	break;
      case CLR:
	sp = 0;
	val[sp] = 0;
	printf("\tstack cleared\n");
	break;
      default:
	printf("error: unknown command %s\n", s);
	break;
      }
      break; /* break from op code switch */
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-') /* operator */
    return c;
  i = 0;
  if (isalpha(c)) {
    while (isalpha(s[++i] = c = getch()))
      ;
    if (strcmp(s, "prt\n") == 0)
      cmd = PRT;
    else if (strcmp(s, "dup\n") == 0)
      cmd = DUP;
    else if (strcmp(s, "swp\n") == 0)
      cmd = SWP;
    else if (strcmp(s, "clr\n") == 0)
      cmd = CLR;
    return COMMAND;
  }
  if (c == '-')
    s[++i] = c = getch();
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
