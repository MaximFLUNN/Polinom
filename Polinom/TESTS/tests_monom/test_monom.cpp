// Copyright 2022 Filatov Maxim

#include <gtest/gtest.h>
#include "../../LIBS/lib_monom/lib_monom.h"

TEST(Monom_tests, can_create_default_constructor) {
	ASSERT_NO_THROW(Monom());
}

TEST(Monom_tests, correctly_create_default_constructor) {
	Monom monom;
	EXPECT_EQ(monom.coefficient, NULL);
	EXPECT_EQ(monom.term.vars.empty(), true);
}

TEST(Monom_tests, can_create_initialize_constructor_coef) {
	ASSERT_NO_THROW(Monom(2));
}

TEST(Monom_tests, correctly_create_initialize_constructor_coef) {
	Monom monom = Monom(2);
	EXPECT_EQ(monom.coefficient, 2);
	EXPECT_EQ(monom.term.vars.empty(), true);
}

TEST(Monom_tests, can_create_initialize_constructor_coef_term) {
	ASSERT_NO_THROW(Monom(2, {Var()}));
}

TEST(Monom_tests, correctly_create_initialize_constructor_coef_term) {
	Monom monom = Monom(2, {Var()});
	EXPECT_EQ(monom.coefficient, 2);
	EXPECT_EQ(monom.term.vars.size(), 1);
}

TEST(Monom_tests, can_get_string_ignore_brackets_false) {
	ASSERT_NO_THROW(Monom().get_string(false));
}

TEST(Monom_tests, correctly_get_string_ignore_brackets_false) {
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3)});
	EXPECT_EQ(monom.get_string(false), "2((x^2)(y^3))");
}

TEST(Monom_tests, can_get_string_ignore_brackets_true) {
	ASSERT_NO_THROW(Monom().get_string(true));
}

TEST(Monom_tests, correctly_get_string_ignore_brackets_true) {
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	EXPECT_EQ(monom.get_string(true), "2x^2y^3");
}

TEST(Monom_tests, can_get_string_for_solve) {
	ASSERT_NO_THROW(Monom().get_string_for_solve());
}

TEST(Monom_tests, correctly_get_string_for_solve) {
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	EXPECT_EQ(monom.get_string_for_solve(), "2*((x^2)*(y^3))");
}

TEST(Monom_tests, can_double_equals) {
	ASSERT_NO_THROW(Monom() == Monom());
}

TEST(Monom_tests, correctly_double_equals) {
	Monom monom1 = Monom(2, { Var('x', 2), Var('y', 3) });
	Monom monom2 = Monom(2, { Var('x', 2), Var('y', 3) });
	Monom monom3 = Monom(2, { Var('g', 2), Var('b', 8) });
	EXPECT_EQ(monom1 == monom2, true);
	EXPECT_EQ(monom1 == monom3, false);
}

TEST(Monom_tests, can_equal) {
	ASSERT_NO_THROW(Monom() == Monom());
}

TEST(Monom_tests, correctly_equal) {
	Monom monom1 = Monom(2, { Var('x', 2), Var('y', 3) });
	Monom monom2 = Monom(2, { Var('x', 2), Var('y', 3) });
	Monom monom3 = Monom(2, { Var('g', 2), Var('b', 8) });
	EXPECT_EQ(monom1 == monom2, true);
	EXPECT_EQ(monom1 == monom3, false);
	monom1 = monom3;
	EXPECT_EQ(monom1 == monom3, true);
}

TEST(Monom_tests, can_multiply) {
	ASSERT_NO_THROW(Monom() * Monom());
}

TEST(Monom_tests, correctly_multiply) {
	Monom monom1 = Monom(2, { Var('x', 2) });
	Monom monom2 = Monom(2, { Var('x', 2) });
	EXPECT_EQ((monom1 * monom2).get_string(), "4((x^4))");
}

TEST(Monom_tests, can_multiply_equal) {
	ASSERT_NO_THROW(Monom() *= Monom());
}

TEST(Monom_tests, correctly_multiply_equal) {
	Monom monom1 = Monom(2, { Var('x', 2) });
	Monom monom2 = Monom(2, { Var('x', 2) });
	monom1 *= monom2;
	EXPECT_EQ(monom1.get_string(), "4((x^4))");
}

TEST(Monom_tests, can_plus) {
	ASSERT_NO_THROW(Monom() + Monom());
}

TEST(Monom_tests, correctly_plus) {
	Monom monom1 = Monom(2, { Var('x', 2) });
	Monom monom2 = Monom(2, { Var('x', 2) });
	EXPECT_EQ((monom1 + monom2).get_string(), "4((x^2))");
}

TEST(Monom_tests, can_plus_equal) {
	ASSERT_NO_THROW(Monom() += Monom());
}

TEST(Monom_tests, correctly_plus_equal) {
	Monom monom1 = Monom(2, { Var('x', 2) });
	Monom monom2 = Monom(2, { Var('x', 2) });
	monom1 += monom2;
	EXPECT_EQ(monom1.get_string(), "4((x^2))");
}

TEST(Monom_tests, can_minus) {
	ASSERT_NO_THROW(Monom() - Monom());
}

TEST(Monom_tests, correctly_minus) {
	Monom monom1 = Monom(2, { Var('x', 2) });
	Monom monom2 = Monom(3, { Var('x', 2) });
	EXPECT_EQ((monom1 - monom2).get_string(), "-1((x^2))");
}

TEST(Monom_tests, can_minus_equal) {
	ASSERT_NO_THROW(Monom() -= Monom());
}

TEST(Monom_tests, correctly_minus_equal) {
	Monom monom1 = Monom(2, { Var('x', 2) });
	Monom monom2 = Monom(3, { Var('x', 2) });
	monom1 -= monom2;
	EXPECT_EQ(monom1.get_string(), "-1((x^2))");
}