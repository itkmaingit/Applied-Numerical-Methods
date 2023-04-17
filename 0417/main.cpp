#include <iostream>
#include <math.h>
#include <iomanip>

double f(double x)
{
  return exp(x) - (2 - pow(x, 2));
}

double g(double x)
{
  return exp(x) + 2 * x;
}

int main()
{
  double a;
  double error = 1e-7;
  std::cin >> a;

  while (true)
  {
    if (abs(f(a)) < error)
    {
      std::cout << std::setprecision(7) << std::fixed << a << std::endl;
      return 0;
    }

    a = a - f(a) / g(a);
  }
}