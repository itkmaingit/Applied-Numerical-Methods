#include <iostream>
#include <math.h>
#include <utility>
#include "rk4.h"

int main()
{
  double h = 0.1;
  double x = rk4(h);
  printf("%.15f\n", x);
}
