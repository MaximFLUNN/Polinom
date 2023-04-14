// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_ORDERED_ARRAY_TABLE_H_
#define INCLUDE_ORDERED_ARRAY_TABLE_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_linear_array_table/linear_array_table.h"

template <class T>
class Ordered_array_table : public Array_table<T> {
public:
	using Array_table<T>::Array_table;
	using Array_table<T>::write_in_table;
	using Array_table<T>::isClear;
	using Array_table<T>::isFull;
	using Array_table<T>::print;
	using Array_table<T>::m_inside_size;
	using Array_table<T>::m_size;
	using Array_table<T>::pairs;

	void insert(std::string key, T tbl_obj) override {
		if (isFull()) throw std::logic_error("Table is full, error in insert method!");
		for (int i = 0; i < m_inside_size; i++) {
			int find_result = strcmp(key.c_str(), pairs[i].first.c_str());
			if (find_result == 0) {
				throw std::logic_error("The table already has an instance with the same name, error in insert method!");
			}
			else if (find_result == -1) {
				for (int j = m_inside_size - 1; j >= i; j--) {
					pairs[j + 1] = pairs[j];
				}
				write_in_table(key, tbl_obj, i);
				break;
			}
			else {
				if (i == m_inside_size - 1) {
					write_in_table(key, tbl_obj, m_inside_size);
				}
				else {
					continue;
				}
			}
		}
		if (isClear()) { write_in_table(key, tbl_obj, NULL); }
		m_inside_size++;
	}
};

#endif  // INCLUDE_ORDERED_ARRAY_TABLE_H_
