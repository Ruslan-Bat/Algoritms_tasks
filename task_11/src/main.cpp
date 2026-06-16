#include <iostream>
#include <string>

#include "func_11.h"

int main() {
  std::string s, p;
  if (!(std::cin >> s)) return 0;
  if (!(std::cin >> p)) return 0;
  int res = func(s, p);
  std::cout << res << '\n';
  return 0;
}
