
#include <gtest/gtest.h>
#include "func_11.h"
#include <string>


TEST(Func11, BasicExample) {
	std::string s = "abcsrlfcxdms";
	std::string p = "lrf";
	EXPECT_EQ(func(s, p), 5);
}

TEST(Func11, NotFound) {
	std::string s = "smnkfwlvk";
	std::string p = "nmsf";
	EXPECT_EQ(func(s, p), -1);
}

TEST(Func11, PermutationAtStart) {
	std::string s = "abcabc";
	std::string p = "cab";
	EXPECT_EQ(func(s, p), 1);
}

TEST(Func11, SingleChar) {
	std::string s = "a";
	std::string p = "a";
	EXPECT_EQ(func(s, p), 1);
}

TEST(Func11, EndOfString) {
	std::string s = "zzabc";
	std::string p = "abc";
	EXPECT_EQ(func(s, p), 3);
}
