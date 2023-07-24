#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Constants
const int N = 32;
const double dt = 1e-4;
const double dx = 2.0 / (double)N;
const int total_x_steps = N + 1;
const int total_t_steps = 1e4;
const double error_tolerance = 1e-15;
double lambda; // lambda の値を指定
double c, p, q;

// Function to solve the system using Gauss-Seidel method
void gaussSeidel(vector<double> &u_next, const vector<double> &u_current)
{
  double error = 1;
  while (error > error_tolerance)
  {
    error = 0;
    for (int i = 1; i < total_x_steps - 1; i++)
    {
      double temp = u_next[i];
      u_next[i] = (u_next[i + 1] + u_next[i - 1] + u_current[i - 1] + u_current[i + 1] - q * u_current[i]) / p;
      error = max(error, abs(temp - u_next[i]));
    }
  }
}

int main()
{
  int index = 0;
  double x = -1.0;
  lambda = 1.0;
  c = lambda * dt / (dx * dx);
  p = 2 * (1 + 1 / c);
  q = 2 * (1 - 1 / c);
  // Initial conditions
  vector<double> u_current(total_x_steps, 0);
  vector<double> u_next(total_x_steps, 0);
  for (int i = 0; i < total_x_steps; i++)
  {
    x = -1 + i * dx;
    u_current[i] = 1 - x * x;
    u_next[i] = 1 - x * x;
  }

  // Time iterations
  for (int n = 0; n < total_t_steps; n++)
  {
    u_current[0] = 0;
    u_current[total_x_steps - 1] = 0;
    u_next = u_current;

    // Solve system of equations
    gaussSeidel(u_next, u_current);
    u_current = u_next;
  }

  // Print results

  printf("%.8f\n", u_current[16]);

  return 0;
}
