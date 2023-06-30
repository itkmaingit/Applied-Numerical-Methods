#include <vector>
#include <iostream>

int main()
{
  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2 = v1;
  v2[0] = 100;
  std::cout << v1[0] << std::endl; // prints "1"
  std::cout << v2[0] << std::endl; // prints "100"
}