#include "func_02.h"

#include <vector>
using namespace std;
/*
int func(int N, vector<int> mass){
    int i=0;
    for (int j=0; j<N-1; j++){
        if (mass[j]==0 && mass[j+1]==1){
            i=j;
            break;
        }
    }
    return i;
}
*/

int func(int N, const vector<int>& mass) {
  int left = 0;
  int right = N - 1;
  int mid = N - 1;

  while (right - left > 1) {
    mid = (right - left) / 2 + left;

    if (mass[mid] == 0)
      left = mid;
    else
      right = mid;
  }

  return left;
}