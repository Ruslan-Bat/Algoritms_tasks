#include "func_01.h"

#include <vector>
using namespace std;

vector<int> func(int S, int N, vector<int>& mass) {
  int right = 0;
  int left = N - 1;
  vector<int> result = {-1};

  if (N < 2) return result;

  if (mass[right] > mass[left]) {  // в порядке убывания
    while (mass[right] + mass[left] != S) {
      if (right >= left) break;

      if (mass[right] + mass[left] < S)
        left--;
      else if (mass[right] + mass[left] > S)
        right++;
    }
  } else {  // в порядке возрастания

    while (mass[right] + mass[left] != S) {
      if (right >= left) break;

      if (mass[right] + mass[left] < S)
        right++;
      else if (mass[right] + mass[left] > S)
        left--;
    }
  }

  if (mass[right] + mass[left] == S)
    result = {min(mass[right], mass[left]), max(mass[right], mass[left])};

  return result;
}
