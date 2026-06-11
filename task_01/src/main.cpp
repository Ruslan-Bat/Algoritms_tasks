#include <iostream>
#include <vector>
#include "func_01.h"

int main() {
	int S, N;
	if (!(std::cin >> S))
		return 0;
	if (!(std::cin >> N))
		return 0;

	std::vector<int> mass;
	mass.reserve(N);
	for (int i = 0; i < N; ++i) {
		int x;
		std::cin >> x;
		mass.push_back(x);
	}
    func(S, N, mass);
	return 0;
}
