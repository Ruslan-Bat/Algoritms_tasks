
#include <gtest/gtest.h>
#include "func_08.h"
#include <vector>

TEST(QuickSelect, ExamplesFromReadme) {
  std::vector<int> a1 = {7, 10, 4, 3, 20};
  EXPECT_EQ(quick_selest(5, 3, a1), 7);

  std::vector<int> a2 = {7, 10, 4, 3, 20};
  EXPECT_EQ(quick_selest(5, 1, a2), 3);

  std::vector<int> a3 = {7, 10, 4, 3, 20};
  EXPECT_EQ(quick_selest(5, 5, a3), 20);
}

TEST(QuickSelect, DuplicatesAndNegatives) {
  std::vector<int> v = {5, -1, 5, 2, 2, -1};
  // Sorted: -1, -1, 2, 2, 5, 5
  EXPECT_EQ(quick_selest(6, 1, v), -1);
  EXPECT_EQ(quick_selest(6, 2, v), -1);
  EXPECT_EQ(quick_selest(6, 3, v), 2);
  EXPECT_EQ(quick_selest(6, 6, v), 5);
}

TEST(QuickSelect, SingleElement) {
  std::vector<int> v = {42};
  EXPECT_EQ(quick_selest(1, 1, v), 42);
}

TEST(QuickSelect, AlreadySorted) {
  std::vector<int> v = {1,2,3,4,5,6,7,8,9};
  EXPECT_EQ(quick_selest(9, 4, v), 4);
  EXPECT_EQ(quick_selest(9, 9, v), 9);
}
