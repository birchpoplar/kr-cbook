#include <stdio.h>

/* print Celsius to Fahrenheit table */
main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 100;
  step = 5;

  celsius = lower;
  printf("Celsius Fahr\n");
  printf("=======-====\n");
  while (celsius <= upper) {
    fahr = celsius * (9.0/5.0) +32.0;
    printf("%6.1f %3.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
