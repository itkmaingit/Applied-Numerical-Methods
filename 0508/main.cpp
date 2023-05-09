#include <iostream>
#include <tuple>
#include <vector>

void array_normalize(float array[3][3]);
int main()
{
  float A[3][3], B_1[3][3], B_2[3][3], B_3[3][3], L_1[3][3], L_2[3][3];

  array_normalize(B_1);
  array_normalize(B_2);
  array_normalize(B_3);

  for (int i = 0; i < 3; i++)
  {
    std::cin >> A[i][0] >> A[i][1] >> A[i][2];
  }

  // B1を作成
  for (int i = 0; i < 3; i++)
  {
    B_1[i][0] = A[i][0];
  }

  // A1を作成
  float k_0 = A[0][0];
  float k_1 = A[1][0];
  float k_2 = A[2][0];

  for (int j = 0; j < 3; j++)
  {
    A[0][j] /= k_0;
  }

  for (int j = 0; j < 3; j++)
  {
    A[1][j] -= k_1 * A[0][j];
  }
  for (int j = 0; j < 3; j++)
  {
    A[2][j] -= k_2 * A[0][j];
  }

  // B2を作成
  for (int i = 1; i < 3; i++)
  {
    B_2[i][1] = A[i][1];
  }

  // A2を作成
  float l_1 = A[1][1];
  float l_2 = A[2][1];

  for (int j = 0; j < 3; j++)
  {
    A[1][j] /= l_1;
  }
  for (int j = 0; j < 3; j++)
  {
    A[2][j] -= l_2 * A[1][j];
  }

  // B3を作成
  for (int i = 2; i < 3; i++)
  {
    B_3[i][2] = A[i][2];
  }

  // A3(=U)を作成
  float m_2 = A[2][2];
  for (int j = 0; j < 3; j++)
  {
    A[2][j] /= m_2;
  }

  // B1*B2*B3(=L)を計算
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      for (int k = 0; k < 3; ++k)
      {
        L_1[i][k] += B_1[i][j] * B_2[j][k];
      }
    }
  }

  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      for (int k = 0; k < 3; ++k)
      {
        L_2[i][k] += L_1[i][j] * B_3[j][k];
      }
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%lf\n", L_2[i][j]);
    }
  }
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%lf\n", A[i][j]);
    }
  }
}

void array_normalize(float array[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (i == j)
      {
        array[i][j] = 1.0;
      }
      else
      {
        array[i][j] = 0.0;
      }
    }
  }
}
