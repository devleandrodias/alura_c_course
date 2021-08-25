#include <stdio.h>

int main()
{
  double x = 3;
  double y = 2;

  double score = (double)x / (double)y; // Casting

  printf("%.2f\n", score);

  double pi = 3.1415;
  int convertedPi = (int)pi;

  printf("%f\n%d\n", pi, convertedPi);

  return 0;
}