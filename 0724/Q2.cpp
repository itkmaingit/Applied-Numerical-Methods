// 1030332611

// data  (x,y)

// read data

// calucurate
// coefficient Matrix C = (f11 f21 ...... fk1)
//                       (f12 f22 ...... fk2)
//                       (f1n f2n ...... fkn)

// solve
// transpose(A) * Ax = transpose(A) * b
//  x = (a1 ...... ak)
//  b = (y1 ...... yn)
//  by LU

#include <iostream>
#include <vector>
#include <fstream>

int n, col_num, row_num;
double **A;
double **L;
double *BP;

struct _data
{
  double x;
  double y;
  double z;
};

std::vector<_data> data;

void readdata()
{
  std::cin >> n;
  row_num = n;
  col_num = 6;
  for (int i = 0; i < n; i++)
  {
    double x, y;
    std::cin >> x >> y;

    _data tmp;
    tmp.x = x;
    tmp.y = y;

    data.push_back(tmp);
  }
}

void preMatrix()
{

  A = new double *[col_num];
  for (int i = 0; i < col_num; i++)
  {
    A[i] = new double[col_num];
  }

  L = new double *[col_num];
  for (int i = 0; i < col_num; i++)
  {
    L[i] = new double[col_num];
  }

  BP = new double[col_num];
}

void LU()
{

  for (int i = 0; i < col_num; i++)
  {
    for (int j = i; j < col_num; j++)
    {
      L[j][i] = A[j][i];
    }

    double a = A[i][i];
    for (int l = i; l < col_num; l++)
    {
      A[i][l] /= a;
    }

    for (int j = i + 1; j < col_num; j++)
    {
      double ap = A[j][i];
      for (int l = i; l < col_num; l++)
      {
        A[j][l] -= ap * A[i][l];
      }
    }
  }
}

void invA()
{

  double *y;
  y = new double[col_num];

  for (int i = 0; i < col_num; i++)
  {
    double ay = 0;
    for (int j = 0; j < i; j++)
    {
      ay += L[i][j] * y[j];
    }
    y[i] = (BP[i] - ay) / L[i][i];
  }

  double *z;
  z = new double[col_num];

  for (int i = col_num - 1; i >= 0; i--)
  {
    double uz = 0;
    for (int j = i + 1; j < col_num; j++)
    {
      uz += A[i][j] * z[j];
    }
    z[i] = y[i] - uz;
  }

  for (int i = 0; i < col_num; i++)
  {
    printf("%lf\n", z[i]);
  }
}

double f0(double x)
{
  return 1;
}

double f1(double x)
{
  return x;
}

double f2(double x)
{
  return x * x;
}

double f3(double x)
{
  return x * x * x;
}

double f4(double x)
{
  return x * x * x * x;
}

double f5(double x)
{
  return x * x * x * x * x;
}

int main()
{
  (void)readdata();
  (void)preMatrix();

  double (*funcp[])(double) = {f0, f1, f2, f3, f4, f5};

  double **C;
  C = new double *[row_num];
  for (int i = 0; i < row_num; i++)
  {
    C[i] = new double[col_num];
  }

  double *B;
  B = new double[row_num];

  for (int i = 0; i < row_num; i++)
  {
    double x = data[i].x;
    double y = data[i].y;
    for (int j = 0; j < col_num; j++)
    {
      C[i][j] = funcp[j](x);
    }
    B[i] = y;
  }

  for (int i = 0; i < col_num; i++)
  {
    for (int j = 0; j < col_num; j++)
    {
      double aij = 0;
      for (int k = 0; k < row_num; k++)
      {
        aij += C[k][i] * C[k][j];
      }
      A[i][j] = aij;
    }
  }

  for (int i = 0; i < col_num; i++)
  {
    double b = 0;
    for (int j = 0; j < row_num; j++)
    {
      b += C[j][i] * B[j];
    }
    BP[i] = b;
  }

  (void)LU();
  (void)invA();

  return 0;
}