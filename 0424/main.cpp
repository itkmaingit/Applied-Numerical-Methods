#include <iostream>

int main()
{
  float arr[3][4];
  float x, y, z;

  for (int i = 0; i < 3; i++)
  {
    std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
  }

  float k_1 = arr[1][0] / arr[0][0];
  float k_2 = arr[2][0] / arr[0][0];

  for (int j = 0; j < 4; j++)
  {
    arr[1][j] -= arr[0][j] * k_1;
    arr[2][j] -= arr[0][j] * k_2;
  }

  float k_3 = arr[2][1] / arr[1][1];

  for (int j = 1; j < 4; j++)
  {
    arr[2][j] -= arr[1][j] * k_3;
  }

  z = arr[2][3] / arr[2][2];
  y = (arr[1][3] - arr[1][2] * z) / arr[1][1];
  x = (arr[0][3] - arr[0][2] * z - arr[0][1] * y) / arr[0][0];

  printf("%lf\n", x);
  printf("%lf\n", y);
  printf("%lf\n", z);
}