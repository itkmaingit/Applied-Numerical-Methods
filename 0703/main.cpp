#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Constants
double dx;
int total_x_steps;
int N;
const double error_tolerance = 1.0e-15;
const double omega = 1.2;

double delta(int i)
{
  if (i == N / 2)
  {
    return 1.0;
  }
  else
  {
    return 0;
  }
}

void gauss_seidel(vector<double> &u)
{
  double error;
  do
  {
    error = 0;
    for (int i = 1; i < total_x_steps - 1; i++)
    {
      double prev_u = u[i];
      double star_u = (u[i + 1] + u[i - 1] + dx * delta(i)) / 2;
      u[i] = prev_u + omega * (star_u - prev_u);
      error += abs(u[i] - prev_u) / (N - 1);
    }
  } while (error > error_tolerance);
}

int main()
{
  cin >> N;
  total_x_steps = N + 1;
  dx = 2.0 / N;
  vector<double> u(total_x_steps, 0);
  gauss_seidel(u);
  for (auto u_x : u)
  {
    printf("%.15f\n", u_x);
  }
}