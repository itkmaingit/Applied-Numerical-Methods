#include <iostream>
#include <math.h>
#include <vector>
#include "rk4.h"
using namespace std;

// double f(double t, double x, double v)
// {
//   return -x;
// }

// double g(double t, double x, double v)
// {
//   return v;
// }
// double average(double h, double v_0, double v_1, double v_2, double v_3)
// {
//   return h * (v_0 + 2 * v_1 + 2 * v_2 + v_3) / 6;
// }

// pair<double, double> var_0(double h, double t, double x, double v)
// {
//   double k_0 = g(t, x, v);
//   double l_0 = f(t, x, v);

//   return make_pair(k_0, l_0);
// }

// pair<double, double> var_1(double h, double t, double x, double v, double k_0, double l_0)
// {
//   double k_1 = g(t + h / 2, x + k_0 * h / 2, v + l_0 * h / 2);
//   double l_1 = f(t + h / 2, x + k_0 * h / 2, v + l_0 * h / 2);

//   return make_pair(k_1, l_1);
// }
// pair<double, double> var_2(double h, double t, double x, double v, double k_1, double l_1)
// {
//   double k_2 = g(t + h / 2, x + k_1 * h / 2, v + l_1 * h / 2);
//   double l_2 = f(t + h / 2, x + k_1 * h / 2, v + l_1 * h / 2);

//   return make_pair(k_2, l_2);
// }
// pair<double, double> var_3(double h, double t, double x, double v, double k_2, double l_2)
// {
//   double k_3 = g(t + h, x + k_2 * h, v + l_2 * h);
//   double l_3 = f(t + h, x + k_2 * h, v + l_2 * h);

//   return make_pair(k_3, l_3);
// }

// double rk4(double h)
// {
//   double t = 0;
//   double x = 1;
//   double v = 0;
//   double k, l;
//   double e = 1e-9;

//   for (int i = 0; t < 10 - e; i++)
//   {
//     auto v_0 = var_0(h, t, x, v);
//     auto v_1 = var_1(h, t, x, v, v_0.first, v_0.second);
//     auto v_2 = var_2(h, t, x, v, v_1.first, v_1.second);
//     auto v_3 = var_3(h, t, x, v, v_2.first, v_2.second);

//     t += h;
//     x += average(h, v_0.first, v_1.first, v_2.first, v_3.first);
//     v += average(h, v_0.second, v_1.second, v_2.second, v_3.second);
//   }

//   return x;
// }

int main()
{
  double numerical_x = cos(10);
  double a, b, c, d, p, q;
  a = 5.0;
  vector<double> h_list = {0.1, 0.05, 0.025, 0.0125, 0.00625};
  for (auto h : h_list)
  {
    double x = rk4(h);
    double log_e = log(abs(numerical_x - x));
    double log_t = log(h);

    b += log_t;
    c += log_t;
    d += log_t * log_t;
    p += log_e;
    q += log_e * log_t;
  }

  double a_1 = (a * q - p * c) / (a * d - b * c);
  printf("%.15f", a_1);
}