// Copyright 2023 Filatov Maxim

#include "../../LIBS/lib_list/lib_list.h"

void printer(CList<int> l) {
	int size = l.size();
	for (int i = 0; i < size; i++) {
		std::cout << "(" << l[i]->get_data() << ")";
		if (i + 1 < size) {
			std::cout << "->";
		}
	}
}

void test() {
	CList<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.insert(4, 1);
	l1.push_front(10);
	l1.insert(7, 4);
	std::cout << "List #1: ";
	printer(l1);
	std::cout << std::endl;

	CList<int> l2;
	l2.push_back(3);
	l2.push_back(6);
	l2.push_back(8);
	l2.push_back(3);
	l2.push_back(6);
	l2.push_back(8);
	l2.insert(4, 1);
	l2.push_front(10);
	l2.insert(7, 4);
	std::cout << "List #2: ";
	printer(l2);
	std::cout << std::endl;

	CList<int> l3;
	l3.push_back(3);
	l3.push_back(6);
	l3.push_back(2);
	l3.push_back(3);
	l3.push_back(4);
	l3.push_back(5);
	l3.insert(4, 1);
	l3.push_back(6);
	l3.push_back(7);
	l3.push_back(8);
	l3.push_back(9);
	l3.push_back(1);
	l3.push_back(2);
	l3.insert(4, 1);
	l3.push_front(10);
	l3.insert(7, 4);
	std::cout << "List #3: ";
	printer(l3);
	std::cout << std::endl;

	l3.clear();
	l3.push_back(1);
	std::cout << "List #3 before clear and plus one: ";
	printer(l3);
	std::cout << std::endl;
	std::cout << "List #4 custom range based for: ";
	CList<int> l4({ 1, 2, 3, 4, 5, 4, 3, 2, 1 });

	for (auto elem : l4) {
		std::cout << "(" << elem.get_data() << ")" << "->";
	}

}