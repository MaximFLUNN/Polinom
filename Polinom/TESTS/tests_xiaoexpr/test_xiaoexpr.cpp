// Copyright 2022 Filatov Maxim

#include <gtest/gtest.h>
#include "../../LIBS/lib_polinom/lib_polinom.h"

TEST(XiaoExpr_tests, plus) {
	EXPECT_EQ(XE::Solver().calculate("2+2"), 4);
}

TEST(XiaoExpr_tests, plus_x2) {
	EXPECT_EQ(XE::Solver().calculate("2+2+6"), 10);
}

TEST(XiaoExpr_tests, plus_x3) {
	EXPECT_EQ(XE::Solver().calculate("2+2+6+12"), 22);
}

TEST(XiaoExpr_tests, minus) {
	EXPECT_EQ(XE::Solver().calculate("2-2"), 0);
}

TEST(XiaoExpr_tests, minus_x2) {
	EXPECT_EQ(XE::Solver().calculate("2-2-6"), -6);
}

TEST(XiaoExpr_tests, minus_x3) {
	EXPECT_EQ(XE::Solver().calculate("2-2-6-12"), -18);
}

TEST(XiaoExpr_tests, multiply) {
	EXPECT_EQ(XE::Solver().calculate("2*2"), 4);
}

TEST(XiaoExpr_tests, multiply_x2) {
	EXPECT_EQ(XE::Solver().calculate("2*2*6"), 24);
}

TEST(XiaoExpr_tests, multiply_x3) {
	EXPECT_EQ(XE::Solver().calculate("2*2*6*12"), 288);
}

TEST(XiaoExpr_tests, devide) {
	EXPECT_EQ(XE::Solver().calculate("2/2"), 1);
}

TEST(XiaoExpr_tests, devide_x2) {
	EXPECT_EQ(XE::Solver().calculate("24/6/2"), 2);
}

TEST(XiaoExpr_tests, devide_x3) {
	EXPECT_EQ(XE::Solver().calculate("120/12/2"), 5);
}

TEST(XiaoExpr_tests, expr) {
	EXPECT_EQ(XE::Solver().calculate("2^2"), 4);
}

TEST(XiaoExpr_tests, expr_x2) {
	EXPECT_EQ(XE::Solver().calculate("2^2^2"), 16);
}

TEST(XiaoExpr_tests, expr_x3) {
	EXPECT_EQ(XE::Solver().calculate("2^2^2^2"), 256);
}

TEST(XiaoExpr_tests, fac) {
	EXPECT_EQ(XE::Solver().calculate("2!"), 2);
}

TEST(XiaoExpr_tests, fac_x2) {
	EXPECT_EQ(XE::Solver().calculate("2!+3!"), 8);
}

TEST(XiaoExpr_tests, fac_x3) {
	EXPECT_EQ(XE::Solver().calculate("2!+3!+4!"), 32);
}