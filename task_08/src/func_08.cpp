#include "func_08.h"

#include <cstdlib>
#include <random>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
  static thread_local std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> dist(left, right);
  int pivot_index = dist(rng);
  swap(arr[pivot_index], arr[right]);

  int pivot = arr[right];
  int i = left;

  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[right]);
  return i;
}

int quick_select_impl(vector<int>& arr, int left, int right, int N) {
  if (left == right) return arr[left];

  int pivot_index = partition(arr, left, right);

  if (pivot_index == N)
    return arr[pivot_index];
  else if (pivot_index > N)
    return quick_select_impl(arr, left, pivot_index - 1, N);
  else
    return quick_select_impl(arr, pivot_index + 1, right, N);
}

int quick_select(int N, int K, vector<int>& arr) {
  return quick_select_impl(arr, 0, arr.size() - 1, K - 1);
}