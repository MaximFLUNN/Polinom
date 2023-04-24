// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_RED_BLACK_TREE_TABLE_H_
#define INCLUDE_RED_BLACK_TREE_TABLE_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_interface_table/interface_table.h"

enum RBColor {
	red = 0,
	black = 1
};

template <class T>
class RBNode {
protected:
	std::pair<std::string, T> pair;
	RBNode* m_left = nullptr;
	RBNode* m_right = nullptr;
	RBNode* m_parent = nullptr;
	RBColor m_color = RBColor::black; 
public:
	RBNode(std::string key, T tbl_obj) {
		this->m_pair.first = key;
		this->m_pair.second = tbl_obj;
		this->m_color = RBColor::red;
		this->m_left = nullptr;
		this->m_right = nullptr;
		this->m_parent = nullptr;
	}
	void insert(std::string key, T tbl_obj) {

	}
	~RBNode() {}

private:

};

#endif  // INCLUDE_RED_BLACK_TREE_TABLE_H_
