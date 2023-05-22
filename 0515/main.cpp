#include <iostream>
#include <vector>

using namespace std;
vector<double> f(double, double);
int main()
{
  int N;
  double product;
  cin >> N;
  vector<vector<double>> data(N, vector<double>(3, 0));
  vector<vector<double>> equation(N, vector<double>(7, 0));
  for (auto &v : data)
  {
    for (auto &d : v)
    {
      cin >> d;
    }
  }
  for (j = 0; j < 6; j++)
  {
    for (const auto &d : data)
    {
      product = delta_f(j, d[1], d[2]);
      for (auto &e : equation)
      {

        product *
      }
    }
  }
  auto v = f(2.0, 3.0);
  for (auto vv : v)
  {
    cout << vv;
  }
}

vector<double> f(double x, double y)
{
  vector<double> v = {1.0, x, y, x * y, x * x, y * y};
  return v;
}

double delta_f(int j, double x, double y)
{
  if (j == 0)
  {
    return 1.0;
  }
  else if (j == 1)
  {
    return x;
  }
  else if (j == 2)
  {
    return y;
  }
  else if (j == 3)
  {
    return x * y;
  }
  else if (j == 4)
  {
    return x * x;
  }
  else if (j == 5)
  {
    return y * y;
  }
  else
  {
    return 0;
  }
}