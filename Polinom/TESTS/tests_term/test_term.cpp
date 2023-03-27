// Copyright 2023 Filatov Maxim

#include <gtest/gtest.h>
#include "../../LIBS/lib_term/lib_term.h"


TEST(Var_tests, can_create_default_constructor) {
	ASSERT_NO_THROW(Var());
}

TEST(Var_tests, correctly_create_default_constructor) {
	Var var;
	EXPECT_EQ(var.character, NULL);
	EXPECT_EQ(var.power, NULL);
}

TEST(Var_tests, can_create_initialize_constructor) {
	ASSERT_NO_THROW(Var('x', 2));
}

TEST(Var_tests, correctly_create_initialize_constructor) {
	Var var = Var('x', 2);
	EXPECT_EQ(var.character, 'x');
	EXPECT_EQ(var.power, 2);
}

TEST(Var_tests, can_copy) {
	ASSERT_NO_THROW(Var().copy_from(Var()));
}

TEST(Var_tests, correctly_copy) {
	Var var;
	var.copy_from(Var('x', 2));
	EXPECT_EQ(var.character, 'x');
	EXPECT_EQ(var.power, 2);
}

TEST(Var_tests, can_get_string_ignore_brackets_false) {
	ASSERT_NO_THROW(Var().get_string(false));
}

TEST(Var_tests, correcly_get_string_ignore_brackets_false) {
	Var var = Var('x', 2);
	EXPECT_EQ(var.get_string(false), "(x^2)");
}

TEST(Var_tests, can_get_string_ignore_brackets_true) {
	ASSERT_NO_THROW(Var().get_string(true));
}

TEST(Var_tests, correcly_get_string_ignore_brackets_true) {
	Var var = Var('x', 2);
	EXPECT_EQ(var.get_string(true), "x^2");
}

TEST(Var_tests, can_operator_double_equal) {
	ASSERT_NO_THROW(Var() == Var());
}

TEST(Var_tests, correctly_operator_double_equal) {
	Var var_1 = Var('x', 2);
	Var var_2 = Var('x', 2);
	Var var_3 = Var('y', 2);
	EXPECT_EQ(var_1 == var_2, true);
	EXPECT_EQ(var_1 == var_3, false);
}

TEST(Var_tests, can_operator_not_equal) {
	ASSERT_NO_THROW(Var() != Var());
}

TEST(Var_tests, correctly_operator_not_equal) {
	Var var_1 = Var('x', 2);
	Var var_2 = Var('x', 2);
	Var var_3 = Var('y', 2);
	EXPECT_EQ(var_1 != var_2, false);
	EXPECT_EQ(var_1 != var_3, true);
}

TEST(Term_tests, can_create_default_constructor) {
	ASSERT_NO_THROW(Term());
}

TEST(Term_tests, correctly_create_default_constructor) {
	Term term = Term();
	EXPECT_EQ(term.vars.empty(), true);
}

TEST(Term_tests, can_create_initialize_constructor) {
	ASSERT_NO_THROW(Term({}));
}

TEST(Term_tests, correctly_create_initialize_constructor) {
	Term term = Term({ Var('x', 2), Var('y', 3), Var('z', 4)});
	EXPECT_EQ(term.vars.size(), 3);
}

TEST(Term_tests, can_add_var) {
	ASSERT_NO_THROW(Term().add(Var()));
}

TEST(Term_tests, correctly_add_var) {
	Term term = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	EXPECT_EQ(term.vars.size(), 3);
	term.add(Var('g', 5));
	EXPECT_EQ(term.vars.size(), 4);
}

TEST(Term_tests, can_add_term) {
	ASSERT_NO_THROW(Term().add(Term()));
}

TEST(Term_tests, correctly_add_term) {
	Term term = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	EXPECT_EQ(term.vars.size(), 3);
	term.add(Term({ Var('t', 2), Var('u', 3), Var('k', 4) }));
	EXPECT_EQ(term.vars.size(), 6);
}

TEST(Term_tests, can_equal_vars) {
	ASSERT_NO_THROW(Term().equal_vars(Term()));
}

TEST(Term_tests, correctly_equal_vars) {
	Term term1 = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	Term term2 = Term({ Var('x', 21), Var('y', 31), Var('z', 41) });
	Term term3 = Term({ Var('f', 2), Var('g', 3), Var('h', 4) });
	EXPECT_EQ(term1.equal_vars(term2), true);
	EXPECT_EQ(term1.equal_vars(term3), false);
}

TEST(Term_tests, can_equal_vars_coeff) {
	ASSERT_NO_THROW(Term().equal_vars_coeff(Term()));
}

TEST(Term_tests, correctly_equal_vars_coeff) {
	Term term1 = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	Term term2 = Term({ Var('x', 21), Var('y', 31), Var('z', 41) });
	Term term3 = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	EXPECT_EQ(term1.equal_vars_coeff(term2), false);
	EXPECT_EQ(term1.equal_vars_coeff(term3), true);
}

TEST(Term_tests, can_get_string_ignore_brackets_false) {
	ASSERT_NO_THROW(Term().get_string(false));
}

TEST(Term_tests, correctly_get_string_ignore_brackets_false) {
	Term term1 = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	EXPECT_EQ(term1.get_string(false), "(x^2)(y^3)(z^4)");
}

TEST(Term_tests, can_get_string_ignore_brackets_true) {
	ASSERT_NO_THROW(Term().get_string(true));
}

TEST(Term_tests, correctly_get_string_ignore_brackets_true) {
	Term term1 = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	EXPECT_EQ(term1.get_string(true), "x^2y^3z^4");
}

TEST(Term_tests, can_get_string_for_solve) {
	ASSERT_NO_THROW(Term().get_string_for_solve());
}

TEST(Term_tests, correctly_get_string_for_solve) {
	Term term1 = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	EXPECT_EQ(term1.get_string_for_solve(), "(x^2)*(y^3)*(z^4)");
}

TEST(Term_tests, can_copy_from) {
	ASSERT_NO_THROW(Term().copy_from(Term()));
}

TEST(Term_tests, correctly_copy_from) {
	Term term1 = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	Term term2 = Term({ Var('x', 21), Var('y', 31), Var('z', 41) });
	term1.copy_from(term2);
	EXPECT_EQ(term1.vars[0].character, 'x');
	EXPECT_EQ(term1.vars[0].power, 21);
	EXPECT_EQ(term1.vars[1].character, 'y');
	EXPECT_EQ(term1.vars[1].power, 31);
	EXPECT_EQ(term1.vars[2].character, 'z');
	EXPECT_EQ(term1.vars[2].power, 41);
}

TEST(Term_tests, can_operator_double_equal) {
	ASSERT_NO_THROW(Term() == Term());
}

TEST(Term_tests, correctly_operator_double_equal) {
	Term term1 = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	Term term2 = Term({ Var('x', 21), Var('y', 31), Var('z', 41) });
	Term term3 = Term({ Var('x', 2), Var('y', 3), Var('z', 4) });
	bool equal = term1 == term2;
	EXPECT_EQ(equal, false);
	equal = term1 == term3;
	EXPECT_EQ(equal, true);
}