#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {

  int v[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int x = 9;
  int n = 8;

  printf("1-%d :: find %d :: result %d\n", n, x, binsearch(x, v, n));

  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;

  mid = (low+high) / 2;

  while(low <= high && x != v[mid]) {
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
    mid = (low+high) / 2;
  }
  if (x == v[mid])
    return mid;
  else 
    return -1;
}
