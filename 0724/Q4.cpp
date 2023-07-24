#include <iostream>
#include <cmath>

const double EPSILON = 1e-9;

// Function to normalize the vector to unity
void normalize(double eigenvector[3])
{
  double norm = 0.0;
  for (int i = 0; i < 3; i++)
  {
    norm += eigenvector[i] * eigenvector[i];
  }
  norm = sqrt(norm);

  for (int i = 0; i < 3; i++)
  {
    eigenvector[i] /= norm;
  }
}

int main()
{
  double A[3][3];
  double eigenvector[3] = {1.0, 0.0, 0.0}; // Initial guess for eigenvector

  // Input the matrix A
  for (int i = 0; i < 3; i++)
  {
    std::cin >> A[i][0] >> A[i][1] >> A[i][2];
  }

  double eigenvalue = 0.0;
  double prev_eigenvalue;

  // Power iteration method
  do
  {
    prev_eigenvalue = eigenvalue;

    // Calculate the new eigenvector by multiplying A with the previous eigenvector
    double new_eigenvector[3] = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        new_eigenvector[i] += A[i][j] * eigenvector[j];
      }
    }

    // Calculate the new eigenvalue
    eigenvalue = new_eigenvector[0] / eigenvector[0];

    // Normalize the new eigenvector
    normalize(new_eigenvector);

    // Update eigenvector for the next iteration
    for (int i = 0; i < 3; i++)
    {
      eigenvector[i] = new_eigenvector[i];
    }
  } while (std::abs(eigenvalue - prev_eigenvalue) > EPSILON);

  // Output the result
  printf("%lf\n", eigenvalue);
  if (eigenvector[0] < 0.0)
  {
    for (int i = 0; i < 3; i++)
    {
      eigenvector[i] *= -1.0;
    }
  }
  for (int i = 0; i < 3; i++)
  {
    printf("%lf\n", eigenvector[i]);
  }

  return 0;
}