#include <iostream>
#include <vector>

using namespace std;

double L = 2.0;
int N = 8;
double delta_x = L / N;
double delta_t = 0.0625;
double c, R2;

// 最初のu(delta_t,x)を求める関数
double initialize(double X)
{
  return 0.05 * X * (2 - X);
}

class U
{
public:
  U(){};
  U(double X, bool isEdge);
  double calculate_followingT_X(double T_followingX, double T_previousX);
  void update_for_T(double followingT_X);

  double T_X, previousT_X;
};

U::U(double X, bool isEdge)
{
  previousT_X = initialize(X);
  if (isEdge)
  {
    T_X = 0;
  }
  else
  {
    T_X = (1 - R2) * initialize(X) + R2 * (initialize(X + delta_x) + initialize(X - delta_x)) / 2;
  }
}

double U::calculate_followingT_X(double T_followingX, double T_previousX)
{
  // printf("%f, %f, %f, %f, %f\n", R2, T_X, previousT_X, T_followingX, T_previousX);
  // printf("%f\n", 2 * (1 - R2) * T_X - previousT_X + R2 * (T_followingX + T_previousX));
  return 2 * (1 - R2) * T_X - previousT_X + R2 * (T_followingX + T_previousX);
}

void U::update_for_T(double followingT_X)
{
  previousT_X = T_X;
  T_X = followingT_X;
}

int main()
{
  double x = 0;
  vector<U> U_vector(N + 1);

  cin >> c;
  R2 = c * c * delta_t * delta_t / (delta_x * delta_x);

  int index = 0;
  for (auto &u : U_vector)
  {
    if (index == 0 || index == N)
    {
      u = U(0, true);
      index++;
      x += delta_x;
      continue;
    }
    u = U(x, false);
    index++;
    x += delta_x;
  }

  for (int i = 1; i < 10; i++)
  {
    vector<double> temp_u_array(N + 1);
    for (int j = 1; j < N; j++)
    {
      temp_u_array[j] = U_vector[j].calculate_followingT_X(U_vector[j + 1].T_X, U_vector[j - 1].T_X);
    }

    int index = 0;
    for (auto &u : U_vector)
    {
      if (index == 0 || index == N)
      {
        index++;
        continue;
      }
      u.update_for_T(temp_u_array[index]);
      index++;
    }
  }
  for (auto &u : U_vector)
  {
    printf("%.15f\n", u.T_X);
  }
}
