#include "topology_sort.hpp"

#include <vector>

using namespace std;
vector<int> func(int N, const vector<int>& temp) {
  vector<int> result(N, 0);
  vector<int> indexes;

  for (int index = 0; index < N; index++) {
    while (!indexes.empty() && temp[index] > temp[indexes.back()]) {
      result[indexes.back()] = index - indexes.back();
      indexes.pop_back();
    }
    indexes.push_back(index);
  }
  return result;
}