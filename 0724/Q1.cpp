#include <iostream>
#include <cmath>

const int N = 1000000; // 数値積分の分割数

double func(double x)
{
  return 1.0 / (1.0 + pow(x, 3));
}

double integrate(double a, double b)
{
  double h = (b - a) / N;
  double integral = 0.5 * (func(a) + func(b));

  for (int i = 1; i < N; i++)
  {
    double x = a + i * h;
    integral += func(x);
  }

  integral *= h;
  return integral;
}

int main()
{
  double precision = 1e-8;
  double a_min = 0.0;
  double a_max = 1.0;
  double a_mid;

  while ((a_max - a_min) > precision)
  {
    a_mid = (a_max + a_min) / 2.0;
    double left_integral = integrate(0, a_mid);
    double right_integral = integrate(a_mid, 1);

    if (std::fabs(left_integral - right_integral) < precision)
      break;

    if (left_integral < right_integral)
      a_min = a_mid;
    else
      a_max = a_mid;
  }

  // 𝑎 の値を小数点以下8桁の精度で表示
  std::cout.precision(8);
  std::cout << a_mid << std::endl;

  return 0;
}