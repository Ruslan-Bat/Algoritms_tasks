#include <iostream>
#include <string>
#include <vector>
#include "func_03.h"

int main() {
	std::string S;
	if (!(std::cin >> S))
		return 0;

	std::vector<std::string> res = func(S);

	for (size_t i = 0; i < res.size(); ++i) {
		if (i) std::cout << ' ';
		std::cout << res[i];
	}
	if (!res.empty()) std::cout << '\n';

	return 0;
}
