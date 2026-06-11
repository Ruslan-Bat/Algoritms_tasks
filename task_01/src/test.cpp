#include <gtest/gtest.h>
#include "func_01.h"
#include <vector>
using namespace std;
TEST(FindPair, Example1) {
  std::vector<int> v{2,7,11,15};
  ASSERT_EQ((vector<int>{2, 7}), func(9, 4, v));
}

TEST(FindPair, Example2) {
  std::vector<int> v{1,2,4};
  ASSERT_EQ((vector<int>{2, 4}), func(6, 3, v));
}

TEST(FindPair, NoSolution) {
  std::vector<int> v{1,2,3};
  ASSERT_EQ((vector<int>{-1}), func(100, 3, v));
}

TEST(FindPair, DuplicateElements) {
  std::vector<int> v{2,2};
  ASSERT_EQ((vector<int>{2, 2}), func(4, 2, v));
}

TEST(FindPair, NegativeNumbers) {
  std::vector<int> v{-10,2,5};
  ASSERT_EQ((vector<int>{-10, 2}), func(-8, 3, v));
}

TEST(FindPair, SingleElement) {
  std::vector<int> v{5};
  ASSERT_EQ((vector<int>{-1}), func(10, 1, v));
}