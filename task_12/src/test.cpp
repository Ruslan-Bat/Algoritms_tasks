
#include <gtest/gtest.h>

#include <vector>

#include "func_12.h"

TEST(Func12, Example1) {
  std::vector<int> coins = {1, 2, 5, 10};
  EXPECT_EQ(func(14, (int)coins.size(), coins), 3);
}

TEST(Func12, Example2) {
  std::vector<int> coins = {1, 2, 5, 10};
  EXPECT_EQ(func(19, (int)coins.size(), coins), 4);
}

TEST(Func12, SingleCoin) {
  std::vector<int> coins = {7};
  EXPECT_EQ(func(7, (int)coins.size(), coins), 1);
}

TEST(Func12, ZeroSum) {
  std::vector<int> coins = {1, 5, 10};
  EXPECT_EQ(func(0, (int)coins.size(), coins), 0);
}

TEST(Func12, Impossible) {
  std::vector<int> coins = {2};
  EXPECT_EQ(func(3, (int)coins.size(), coins), -1);
}

TEST(Func12, GreedyTrap) {
  std::vector<int> coins = {1, 3, 4};
  EXPECT_EQ(func(6, (int)coins.size(), coins), 2);
}
