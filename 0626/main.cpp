#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Constants
const double dt = 0.01;
const double dx = 0.1;
const int total_x_steps = 1.0 / dx + 1;
const int total_t_steps = 10;
const double error_tolerance = 1.0e-15;
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
  cin >> lambda;
  c = lambda * dt / (dx * dx);
  p = 2 * (1 + 1 / c);
  q = 2 * (1 - 1 / c);
  // Initial conditions
  vector<double> u_current(total_x_steps, 0);
  vector<double> u_next(total_x_steps, 0);
  u_current[total_x_steps - 1] = 1;

  // Time iterations
  for (int n = 0; n < total_t_steps; n++)
  {
    u_next = u_current;

    // Solve system of equations
    gaussSeidel(u_next, u_current);
    u_current = u_next;
  }

  // Print results
  for (int i = 0; i < total_x_steps; i++)
  {
    printf("%.15f\n", u_current[i]);
  }

  return 0;
}
