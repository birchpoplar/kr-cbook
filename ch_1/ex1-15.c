#include <stdio.h>

float c_to_f(int celsius);

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
    printf("%6.1f %3.0f\n", celsius, c_to_f(celsius));
    celsius = celsius + step;
  }
}

float c_to_f(int celsius)
{
  return celsius * (9.0/5.0) + 32.0;
}
