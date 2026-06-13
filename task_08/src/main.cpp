#include <iostream>
#include <vector>
#include "func_08.h"

int main() {
	int N, K;
	if (!(std::cin >> N >> K)) return 0;
	std::vector<int> arr(N);
	for (int i = 0; i < N; ++i) std::cin >> arr[i];
	int res = quick_selest(N, K, arr);
	std::cout << res << '\n';
	return 0;
}
