#include <iostream>
#include <iomanip>

using namespace std;

double a = 0;
double b = 1.0;
double delta_x = (b - a) / 1024;

double f(double);
double simpson(double, double f(double));
int main()
{
  double sum;
  while (b - a > 0)
  {
    sum += simpson(a, f);
    a += 2 * delta_x;
  }
  cout << fixed << setprecision(10) << sum << endl;
}

double f(double x)
{
  return 1 / (1 + x * x);
}
double simpson(double a, double f(double))
{
  return delta_x * (f(a) + 4 * f(a + delta_x) + f(a + 2 * delta_x)) / 3;
}