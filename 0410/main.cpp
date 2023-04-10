#include <iostream>
#include <math.h>
#include <iomanip>

double f(double x)
{
  return pow(x, 3) - 3 * pow(x, 2) + 9 * x - 8;
}

int main()
{
  double a, b, c;
  double error = 1e-7;
  bool flag = true;
  std::cin >> a >> b;

  if (f(a) * f(b) >= 0)
  {
    std::cout << "Choice other a or b." << std::endl;
    return 0;
  }

  else
  {
    while (flag)
    {
      c = (a + b) / 2;
      if (f(c) * f(b) >= 0)
      {
        b = c;
      }
      else
      {
        a = c;
      }

      if (abs(b - a) < error || abs(f((a + b) / 2)) < error)
      {
        std::cout << std::setprecision(7) << a << std::endl;
        return 0;
      }
    }
  }
}
