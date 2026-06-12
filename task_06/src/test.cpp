
#include <gtest/gtest.h>
#include "func_06.h"
#include <vector>
#include <climits>


TEST(FishBuyer, Example1) {
  std::vector<int> costs{5};
  ASSERT_EQ(5LL, func(1, 1, costs));
}

TEST(FishBuyer, Example2) {
  std::vector<int> costs{5,3,4};
  ASSERT_EQ(12LL, func(3, 1, costs));
}

TEST(FishBuyer, Example3) {
  std::vector<int> costs{5,3,4};
  ASSERT_EQ(11LL, func(3, 3, costs));
}

TEST(FishBuyer, KOneEqualsSum) {
  std::vector<int> costs{7,1,5,3};
  long long expected = 0;
  for (int x : costs) expected += x;
  ASSERT_EQ(expected, func((int)costs.size(), 1, costs));
}


TEST(FishBuyer, LargeValues) {
  std::vector<int> costs(50, 1000);
  int N = (int)costs.size();
  ASSERT_EQ((long long)N * 1000LL, func(N, 10, costs));
}
