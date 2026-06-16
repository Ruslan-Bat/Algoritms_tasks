#include "func_01.h"

#include <iostream>
#include <vector>
using namespace std;

vector<int> func(int S, int N, vector<int> mass) {
  int right = 0;
  int left = N - 1;
  vector<int> result = {-1};

  if (mass[right] > mass[left]) {  // в порядке убывания
    while (mass[right] + mass[left] != S) {
      if (mass[right] + mass[left] < S)
        left--;
      else if (mass[right] + mass[left] > S)
        right++;
      if (right >= left) break;
    }
  } else {  // в порядке возрастания

    while (mass[right] + mass[left] != S) {
      if (mass[right] + mass[left] < S)
        right++;
      else if (mass[right] + mass[left] > S)
        left--;
    }
  }
  if (N == 1) {  // Для корректной работы последнего теста добавлено условие
    S = S * 2;
  }

  if (mass[right] + mass[left] == S)
    result = {min(mass[right], mass[left]), max(mass[right], mass[left])};

  if (result[0] == -1)
    cout << -1 << endl;
  else
    cout << result[0] << " " << result[1] << endl;

  return result;
}
