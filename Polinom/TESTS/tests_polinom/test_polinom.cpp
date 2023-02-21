// Copyright 2022 Filatov Maxim

#include <gtest/gtest.h>
#include "../../LIBS/lib_polinom/lib_polinom.h"

TEST(Polinom_tests, can_create_default_constructor) {
	ASSERT_NO_THROW(Polinom());
}

TEST(Polinom_tests, correctly_create_default_constructor) {
	Polinom polinom;
	EXPECT_EQ(polinom.monomial_list.isEmpty(), true);
}

TEST(Polinom_tests, can_create_const_copy_constructor) {
	ASSERT_NO_THROW(Polinom(Polinom()));
}

TEST(Polinom_tests, correctly_create_cont_copy_constructor) {
	Polinom polinom(Polinom({ CList<Monom>({Monom(1, {Var('x', 2)})})}));
	EXPECT_EQ(polinom.monomial_list.isEmpty(), false);
}

TEST(Polinom_tests, can_create_initialize_constructor) {
	ASSERT_NO_THROW(Polinom({ CList<Monom>({Monom(1, {Var('x', 2)})}) }));
}

TEST(Polinom_tests, correctly_create_initialize_constructor) {
	Polinom polinom({ CList<Monom>({Monom(1, {Var('x', 2)})}) }); 
	EXPECT_EQ(polinom.monomial_list.isEmpty(), false);
}

TEST(Polinom_tests, can_isEmpty) {
	ASSERT_NO_THROW(Polinom().isEmpty());
}

TEST(Polinom_tests, correctly_isEmpty) {
	Polinom polinom;
	EXPECT_EQ(polinom.isEmpty(), true);
}

TEST(Polinom_tests, can_add_monom) {
	ASSERT_NO_THROW(Polinom().add_monom(Monom(1, { Var('x', 2) })));
}

TEST(Polinom_tests, correctly_add_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(1, { Var('x', 2) }));
	EXPECT_EQ(polinom.isEmpty(), false);
}

TEST(Polinom_tests, can_get_string_ignore_brackets_false) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom.get_string(false));
}

TEST(Polinom_tests, correctly_get_string_ignore_brackets_false) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3)}));
	polinom.add_monom(Monom(-20, { Var('g', 2), Var('z', 3)}));
	EXPECT_EQ(polinom.get_string(false), "2((x^2)(y^3))-20((g^2)(z^3))");
}

TEST(Polinom_tests, can_get_string_ignore_brackets_true) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom.get_string(true));
}

TEST(Polinom_tests, correctly_get_string_ignore_brackets_true) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom.add_monom(Monom(-20, { Var('g', 2), Var('z', 3) }));
	EXPECT_EQ(polinom.get_string(true), "2x^2y^3-20g^2z^3");
}

TEST(Polinom_tests, can_get_string_for_solve) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom.get_string_for_solve());
}

TEST(Polinom_tests, correctly_get_string_for_solve) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom.add_monom(Monom(-20, { Var('g', 2), Var('z', 3) }));
	EXPECT_EQ(polinom.get_string_for_solve(), "2*((x^2)*(y^3))-20*((g^2)*(z^3))");
}

TEST(Polinom_tests, can_set_vars) {
	Polinom polinom;
	ASSERT_NO_THROW(polinom.set_vars({ {'x', 2}, {'y', 3} }));
}

TEST(Polinom_tests, correctly_set_vars) {
	Polinom polinom;
	polinom.set_vars({ {'x', 2}, {'y', 3} });
	EXPECT_EQ(XE::check::vars({ 'x', 'y' }), true);
}

TEST(Polinom_tests, can_calculate) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom.calculate());
}

TEST(Polinom_tests, correctly_calculate) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom.add_monom(Monom(3, { Var('x', 3), Var('y', 4) }));
	EXPECT_EQ(polinom.calculate(), 2160);
	EXPECT_EQ(polinom.calculate(), XE::Solver().calculate("2*((2^2)*(3^3))+3*((2^3)*(3^4))"));
}

TEST(Polinom_tests, can_double_equals) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom.add_monom(Monom(3, { Var('x', 3), Var('y', 4) }));
	ASSERT_NO_THROW(polinom == Polinom());
}

TEST(Polinom_tests, correctly_double_equals) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom.add_monom(Monom(3, { Var('x', 3), Var('y', 4) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom2.add_monom(Monom(3, { Var('x', 3), Var('y', 4) }));
	EXPECT_EQ(polinom == Polinom(), false);
	EXPECT_EQ(polinom == polinom2, true);
}

TEST(Polinom_tests, can_equal) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom.add_monom(Monom(3, { Var('x', 3), Var('y', 4) }));
	ASSERT_NO_THROW(polinom = Polinom());
}

TEST(Polinom_tests, correctly_equal) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom.add_monom(Monom(3, { Var('x', 3), Var('y', 4) }));
	Polinom polinom2 = Polinom();
	EXPECT_EQ(polinom == Polinom(), false);
	polinom = polinom2;
	EXPECT_EQ(polinom == polinom2, true);
}

TEST(Polinom_tests, can_multiply_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom * polinom2);
}

TEST(Polinom_tests, correctly_multiply_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	bool eq = false;
	if (polinom * polinom2 == Polinom(CList<Monom>({ Monom({4, {Var('x', 4), Var('y', 6)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_multiply_equal_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom *= polinom2);
}

TEST(Polinom_tests, correctly_multiply_equal_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	bool eq = false;
	Polinom polinom3;
	polinom *= polinom2;
	polinom3 = polinom;
	if (polinom3 == Polinom(CList<Monom>({ Monom({4, {Var('x', 4), Var('y', 6)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_plus_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom + polinom2);
}

TEST(Polinom_tests, correctly_plus_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	bool eq = false;
	Polinom polinom3;
	polinom3 = polinom + polinom2;
	if (polinom3 == Polinom(CList<Monom>({ Monom({4, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_plus_equal_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom += polinom2);
}

TEST(Polinom_tests, correctly_plus_equal_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	bool eq = false;
	Polinom polinom3;
	polinom += polinom2;
	polinom3 = polinom;
	if (polinom3 == Polinom(CList<Monom>({ Monom({4, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_minus_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom - polinom2);
}

TEST(Polinom_tests, correctly_minus_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	bool eq = false;
	Polinom polinom3;
	polinom3 = polinom - polinom2;
	if (polinom3 == Polinom(CList<Monom>({ Monom({0, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_minus_equal_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	ASSERT_NO_THROW(polinom -= polinom2);
}

TEST(Polinom_tests, correctly_minus_equal_polinom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Polinom polinom2;
	polinom2.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	bool eq = false;
	Polinom polinom3;
	polinom -= polinom2;
	polinom3 = polinom;
	if (polinom3 == Polinom(CList<Monom>({ Monom({0, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_multiply_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	ASSERT_NO_THROW(polinom * monom);
}

TEST(Polinom_tests, correctly_multiply_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	bool eq = false;
	Polinom polinom2;
	polinom2 = polinom * monom;
	if (polinom2 == Polinom(CList<Monom>({ Monom({4, {Var('x', 4), Var('y', 6)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_multiply_equal_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	ASSERT_NO_THROW(polinom *= monom);
}

TEST(Polinom_tests, correctly_multiply_equal_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	bool eq = false;
	Polinom polinom2;
	polinom *= monom;
	polinom2 = polinom;
	if (polinom2 == Polinom(CList<Monom>({ Monom({4, {Var('x', 4), Var('y', 6)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_plus_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	ASSERT_NO_THROW(polinom + monom);
}

TEST(Polinom_tests, correctly_plus_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	bool eq = false;
	Polinom polinom2;
	polinom2 = polinom + monom;
	if (polinom2 == Polinom(CList<Monom>({ Monom({4, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_plus_equal_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	ASSERT_NO_THROW(polinom += monom);
}

TEST(Polinom_tests, correctly_plus_equal_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	bool eq = false;
	Polinom polinom2;
	polinom += monom;
	polinom2 = polinom;
	if (polinom2 == Polinom(CList<Monom>({ Monom({4, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_minus_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	ASSERT_NO_THROW(polinom - monom);
}

TEST(Polinom_tests, correctly_minus_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	bool eq = false;
	Polinom polinom2;
	polinom2 = polinom - monom;
	if (polinom2 == Polinom(CList<Monom>({ Monom({0, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_minus_equal_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	ASSERT_NO_THROW(polinom -= monom);
}

TEST(Polinom_tests, correctly_minus_equal_monom) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	Monom monom = Monom(2, { Var('x', 2), Var('y', 3) });
	bool eq = false;
	Polinom polinom2;
	polinom -= monom;
	polinom2 = polinom;
	if (polinom2 == Polinom(CList<Monom>({ Monom({0, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_multiply_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	ASSERT_NO_THROW(polinom * num);
}

TEST(Polinom_tests, correctly_multiply_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	bool eq = false;
	Polinom polinom2;
	polinom2 = polinom * num;
	if (polinom2 == Polinom(CList<Monom>({ Monom({4, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_multiply_equal_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	ASSERT_NO_THROW(polinom *= num);
}

TEST(Polinom_tests, correctly_multiply_equal_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	bool eq = false;
	Polinom polinom2;
	polinom *= num;
	polinom2 = polinom;
	if (polinom2 == Polinom(CList<Monom>({ Monom({4, {Var('x', 2), Var('y', 3)}}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_plus_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	ASSERT_NO_THROW(polinom + num);
}

TEST(Polinom_tests, correctly_plus_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	bool eq = false;
	Polinom polinom2;
	polinom2 = polinom + num;
	if (polinom2 == Polinom(CList<Monom>({ Monom({2, {Var('x', 2), Var('y', 3)}}), Monom(2, {}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_plus_equal_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	ASSERT_NO_THROW(polinom += num);
}

TEST(Polinom_tests, correctly_plus_equal_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	bool eq = false;
	Polinom polinom2;
	polinom += num;
	polinom2 = polinom;
	if (polinom2 == Polinom(CList<Monom>({ Monom({2, {Var('x', 2), Var('y', 3)}}), Monom(2, {}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_minus_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	ASSERT_NO_THROW(polinom - num);
}

TEST(Polinom_tests, correctly_minus_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	bool eq = false;
	Polinom polinom2;
	polinom2 = polinom - num;
	if (polinom2 == Polinom(CList<Monom>({ Monom({2, {Var('x', 2), Var('y', 3)}}), Monom(-2, {}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_minus_equal_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	ASSERT_NO_THROW(polinom -= num);
}

TEST(Polinom_tests, correctly_minus_equal_int) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	int num = 2;
	bool eq = false;
	Polinom polinom2;
	polinom -= num;
	polinom2 = polinom;
	if (polinom2 == Polinom(CList<Monom>({ Monom({2, {Var('x', 2), Var('y', 3)}}), Monom(-2, {}) }))) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}

TEST(Polinom_tests, can_index) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom.add_monom(Monom(3, { Var('x', 3), Var('y', 4) })); 
	ASSERT_NO_THROW(polinom[1]);
}

TEST(Polinom_tests, correctly_index) {
	Polinom polinom;
	polinom.add_monom(Monom(2, { Var('x', 2), Var('y', 3) }));
	polinom.add_monom(Monom(3, { Var('x', 3), Var('y', 4) }));
	bool eq = false;
	if (polinom[1] == Monom(3, { Var('x', 3), Var('y', 4) })) {
		eq = !eq;
	}
	EXPECT_EQ(eq, true);
}