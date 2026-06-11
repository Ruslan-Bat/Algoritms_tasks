#include <gtest/gtest.h>
#include "func_02.h"
#include <vector>

TEST(Border01, Minimal) {
  std::vector<int> a{0,1};
  int idx = func(2, a);
  ASSERT_EQ(0, idx);
}

TEST(Border01, Middle) {
  std::vector<int> a{0,0,0,1,1};
  int idx = func(5, a);
  ASSERT_EQ(2, idx);
}

TEST(Border01, LastZero) {
  std::vector<int> a{0,0,0,0,0,1};
  int idx = func(6, a);
  ASSERT_EQ(4, idx);
}

TEST(Border01, FirstBoundary) {
  std::vector<int> a{0,1,1,1,1};
  int idx = func(5, a);
  ASSERT_EQ(0, idx);
}

TEST(Border01, AnyValid) {
  std::vector<int> a{0,0,1,1};
  int idx = func(4, a);
  ASSERT_TRUE(idx >= 0 && idx+1 < (int)a.size());
  ASSERT_EQ(0, a[idx]);
  ASSERT_EQ(1, a[idx+1]);
}

TEST(Border01, LargeInput) {
  std::vector<int> a(1000, 0);
  a.back() = 1;
  int idx = func((int)a.size(), a);
  ASSERT_EQ((int)a.size()-2, idx);
}
