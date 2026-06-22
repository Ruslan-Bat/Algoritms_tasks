#include <iostream>
#include <vector>

#include "func_13.h"

int main() {
  int n;
  if (!(std::cin >> n)) return 0;
  std::vector<std::pair<double, double>> lessons;
  lessons.reserve(n);
  for (int i = 0; i < n; ++i) {
    double s, e;
    std::cin >> s >> e;
    lessons.emplace_back(s, e);
  }
  auto res = SelectMaxNonOverlappingIntervals(n, lessons);
  std::cout << res.size() << '\n';
  for (auto &pr : res) {
    std::cout << pr.first << ' ' << pr.second << '\n';
  }
  return 0;
}
