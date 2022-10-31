#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
  float fl, fltest, last;
    double dbl, dbltest, dblast;

    printf("CHAR_BIT: %d\n", CHAR_BIT);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("LONG_MIN: %d\n", LONG_MIN);
    printf("LONG_MAX: %d\n", LONG_MAX);
    printf("SHRT_MIN: %d\n", SHRT_MIN);
    printf("SHRT_MAX: %d\n", SHRT_MAX);
    printf("USHRT_MAX: %u\n", USHRT_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);
    printf("ULONG_MAX: %u\n", ULONG_MAX);
    printf("UCHAR_MAX: %u\n", UCHAR_MAX);

    
    fl = 0.0;
    fltest = 0.0;
    while (fl == 0.0) {
        last = fltest;
        fltest = fltest + 1111e28;
        fl = (fl + fltest) - fltest;
    }
    printf("Maximum range of float variable: %e\n", last);

    dbl = 0.0;
    dbltest = 0.0;
    while (dbl == 0.0) {
        dblast = dbltest;
        dbltest = dbltest + 1111e297;
        dbl = (dbl + dbltest) - dbltest;
    }
    printf("Maximum range of double variable: %e\n", dblast);
    return 0;
}
