// Copyright 2022 Filatov Maxim

#include <gtest/gtest.h>
#include "../../LIBS/lib_list/lib_list.h"

TEST(List_tests, can_create) {
	ASSERT_NO_THROW(CList<int>());
}

TEST(List_tests, can_push_back) {
	ASSERT_NO_THROW(CList<int>().push_back(1));
}

TEST(List_tests, can_push_front) {
	ASSERT_NO_THROW(CList<int>().push_front(1));
}

TEST(List_tests, can_front) {
	CList<int> l;
	l.push_back(1);
	ASSERT_NO_THROW(l.front());
}

TEST(List_tests, correctly_front) {
	CList<int> l;
	l.push_back(5);
	l.push_back(1);
	l.push_back(1);
	EXPECT_EQ((l.front())->get_data(), 5);
}

TEST(List_tests, can_back) {
	CList<int> l;
	l.push_back(1);
	ASSERT_NO_THROW(l.back());
}

TEST(List_tests, correctly_back) {
	CList<int> l;
	l.push_back(1);
	l.push_back(1);
	l.push_back(5);
	EXPECT_EQ((l.back())->get_data(), 5);
}

TEST(List_tests, correctly_push_back) {
	CList<int> l;
	l.push_back(2);
	EXPECT_EQ((l.front())->get_data(), 2);
}

TEST(List_tests, correctly_push_front) {
	CList<int> l;
	l.push_back(2);
	l.push_back(2);
	l.push_front(3);
	EXPECT_EQ((l.front())->get_data(), 3);
}

TEST(List_tests, can_size) {
	ASSERT_NO_THROW(CList<int>().size());
}

TEST(List_tests, correctly_size) {
	CList<int> l;
	l.push_back(2);
	l.push_back(2);
	l.push_front(3);
	EXPECT_EQ(l.size(), 3);
}

TEST(List_tests, can_clear_head_and_teil) {
	ASSERT_NO_THROW(CList<int>().clearHeadAndTail());
}

TEST(List_tests, correctly_clear_head_and_teil) {
	CList<int> l;
	l.push_back(2);
	l.push_back(2);
	l.push_front(3);
	l.clearHeadAndTail();
	EXPECT_EQ(l.isEmpty(), true);
}

TEST(List_tests, can_erase) {
	CList<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	ASSERT_NO_THROW(a.erase(0));
}

TEST(List_tests, correctly_erase) {
	CList<int> l;
	l.push_back(2);
	l.push_back(2);
	l.push_front(3);
	l.erase(1);
	EXPECT_EQ(l.size(), 2);
}

TEST(List_tests, can_get_index) {
	CList<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	ASSERT_NO_THROW(a[0]);
}

TEST(List_tests, correctly_get_index) {
	CList<int> l;
	l.push_back(2);
	l.push_back(2);
	l.push_back(3);
	int a = l[2]->get_data();
	EXPECT_EQ(a, 3);
}

TEST(List_tests, can_empty) {
	CList<int> a;
	ASSERT_NO_THROW(a.isEmpty());
}

TEST(List_tests, correctly_empty) {
	CList<int> l;
	l.push_back(2);
	l.push_back(2);
	l.push_back(3);
	EXPECT_NE(l.isEmpty(), true);
	l.clearHeadAndTail();
	EXPECT_EQ(l.isEmpty(), true);
}

TEST(List_tests, can_reverse) {
	CList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	ASSERT_NO_THROW(l.reverse());
}

TEST(List_tests, correctly_reverse) {
	CList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.reverse();
	EXPECT_EQ(l.front()->get_data(), 3);
	EXPECT_EQ(l.back()->get_data(), 1);
	EXPECT_EQ(l[1]->get_data(), 2);
}

TEST(List_tests, can_insert) {
	CList<int> l;
	l.push_back(1);
	l.push_back(3);
	ASSERT_NO_THROW(l.insert(2, 1));
}

TEST(List_tests, correctly_insert) {
	CList<int> l;
	l.push_back(1);
	l.push_back(3);
	EXPECT_EQ(l.size(), 2);
	ASSERT_NO_THROW(l.insert(2, 1));
	EXPECT_EQ(l.size(), 3);
	EXPECT_EQ(l.front()->get_data(), 1);
	EXPECT_EQ(l.back()->get_data(), 3);
	EXPECT_EQ(l[1]->get_data(), 2);
}

TEST(List_tests, can_clear) {
	CList<int> l;
	l.push_back(1);
	l.push_back(3);
	ASSERT_NO_THROW(l.clear());
}

TEST(List_tests, correctly_clear) {
	CList<int> l;
	l.push_back(1);
	l.push_back(3);
	l.clear();
	EXPECT_EQ(l.isEmpty(), true);
}

TEST(List_iterator_tests, can_begin) {
	CList<int> l;
	l.push_back(1);
	l.push_back(3);
	ASSERT_NO_THROW(l.begin());
}

TEST(List_iterator_tests, can_end) {
	CList<int> l;
	l.push_back(1);
	l.push_back(3);
	ASSERT_NO_THROW(l.end());
}

TEST(List_iterator_tests, can_iterator) {
	CList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	ASSERT_NO_THROW(for (const auto& element : l));
}

TEST(List_iterator_tests, correctly_iterator) {
	CList<int> l;
	bool f1, f2, f3;
	f1 = f2 = f3 = false;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	for (const auto& element : l) {
		if (element.check_data() == 1) f1 = !f1;
		else if (element.check_data() == 1 && f1) ADD_FAILURE();
		else if (element.check_data() == 2) f2 = !f2;
		else if (element.check_data() == 2 && f2) ADD_FAILURE();
		else if (element.check_data() == 3) f3 = !f3;
		else if (element.check_data() == 3 && f3) ADD_FAILURE();
	}
	EXPECT_EQ(f1, true);
	EXPECT_EQ(f2, true);
	EXPECT_EQ(f3, true);
}