#include "func_06.h"

#include <deque>
#include <vector>
using namespace std;

long long func(int N, int K, const vector<int>& costs) {
  long long result = 0;
  deque<int> ind_min_costs;

  for (int i = 0; i < N; i++) {
    if (!ind_min_costs.empty() && i - ind_min_costs.front() >= K)
      ind_min_costs.pop_front();

    while (!ind_min_costs.empty() && costs[i] <= costs[ind_min_costs.back()]) {
      ind_min_costs.pop_back();
    }

    ind_min_costs.push_back(i);
    // теперь в начале очереди гарантировано минимальная цена на рыбу для i-того
    // дня
    result += costs[ind_min_costs.front()];
  }
  return result;
}