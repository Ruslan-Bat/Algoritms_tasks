#include <iostream>
#include <vector>

#include "func_02.h"

int main() {
  int N;
  if (!(std::cin >> N)) return 0;

  std::vector<int> mass;
  mass.reserve(N);
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    mass.push_back(x);
  }
  int a = func(N, mass);
  std::cout << a << std::endl;
  return a;
}
