#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
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
enum subcommands {NON, PRT, DUP, SWP, CLR, SIN, COS, TAN, EXP, POW};
enum commands {NUMBER, COMMAND, VARPUT, VARGET};

/* Reverse Polish Notation Calculator */
int main()
{
  int type;
  double op2, op3, op4;
  char s[MAXOP];
  double var[26];

  for (int i=0; i<=26; ++i)
    var[i] = 0;
  
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
      case SIN:
	if (sp > 0) {
	  op2 = pop();
	  op3 = sin(op2);
	  push(op3);
	  printf("\t%.8g\n", op3);
	  
	} else
	  printf("error: stack empty\n");
	break; /* break from command switch */
      case COS:
	if (sp > 0) {
	  op2 = pop();
	  op3 = cos(op2);
	  push(op3);
	  printf("\t%.8g\n", op3);
	  
	} else
	  printf("error: stack empty\n");
	break; /* break from command switch */
      case TAN:
	if (sp > 0) {
	  op2 = pop();
	  op3 = tan(op2);
	  push(op3);
	  printf("\t%.8g\n", op3);
	  
	} else
	  printf("error: stack empty\n");
	break; /* break from command switch */
      case EXP:
	if (sp > 0) {
	  op2 = pop();
	  op3 = exp(op2);
	  push(op3);
	  printf("\t%.8g\n", op3);
	  
	} else
	  printf("error: stack empty\n");
	break; /* break from command switch */
      case POW:
	if (sp > 1) {
	  op2 = pop();
	  op3 = pop();
	  op4 = pow(op2, op3);
	  push(op4);
	  printf("\t%.8g\n", op4);
	  
	} else
	  printf("error: stack empty\n");
	break; /* break from command switch */
      default:
	printf("error: unknown command %s\n", s);
	break;
      }
      break; /* break from op code switch */
    case VARPUT:
      var[s[0]-'a'+1] = pop();
      printf("\tvariable updated\n");
      break;
    case VARGET:
      push(var[s[0]-'a'+1]);
      printf("\tvariable retrieved\n");
      break;
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
  if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-' && c != '>' && c != '<') /* operator */
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
    else if (strcmp(s, "sin\n") == 0)
      cmd = SIN;
    else if (strcmp(s, "cos\n") == 0)
      cmd = COS;
    else if (strcmp(s, "tan\n") == 0)
      cmd = TAN;
    else if (strcmp(s, "exp\n") == 0)
      cmd = EXP;
    else if (strcmp(s, "pow\n") == 0)
      cmd = POW;
    return COMMAND;
  }
  if (c == '>') {
    while (i < 2) {
      s[i++] = getch();
    }
    return VARPUT;
  }
  if (c == '<') {
    while (i < 2) {
      s[i++] = getch();
    }
    return VARGET;
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
