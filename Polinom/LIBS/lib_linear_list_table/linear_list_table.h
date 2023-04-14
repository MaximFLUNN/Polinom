// Copyright 2023 Filatov Maxim
#ifndef LINEAR_LIST_TABLE_H_
#define LINEAR_LIST_TABLE_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_interface_table/interface_table.h"
#include "../../LIBS/lib_list/lib_list.h"

template <class T>
class List_table : public ITable<T> {
private:
	CList<std::pair<std::string, T>> pairs;
	int m_inside_size;

	void write_in_table(std::string key, T tbl_obj, int idx) {
		if (idx == m_inside_size) {
			pairs.push_back(std::pair<std::string, T>(key, tbl_obj));
		}
		else {
			pairs[idx]->set_data(std::pair<std::string, T>(key, tbl_obj));
		}
	}
public:
	List_table() { 
		m_inside_size = NULL;
		pairs = CList<std::pair<std::string, T>>();
	}
	void insert(std::string key, T tbl_obj) override {
		int idx = find(key);
		if (idx != NOT_FOUND) throw std::logic_error("The table already has an instance with the same name, error in insert method!");
		write_in_table(key, tbl_obj, m_inside_size);
		m_inside_size++;
	}
	void update(std::string key, T tbl_obj) override {
		int idx = find(key);
		if (idx == NOT_FOUND) throw std::logic_error("The specified element was not found, error in update method!");
		write_in_table(key, tbl_obj, idx);
	}
	void remove(std::string key) override {
		if (isClear()) throw std::logic_error("Table is clear, error in remove method!");
		int idx = find(key);
		if (idx == NOT_FOUND) throw std::logic_error("The specified element was not found, error in remove method!");
		pairs.erase(idx);
		m_inside_size--;
	}
	int find(std::string key) override {
		if (isClear()) return NOT_FOUND;
		int idx = 0;
		for (CNode<std::pair<std::string, T>> tbl_obj : pairs) {
			if (key == tbl_obj.check_data().first) {
				return idx;
			}
			idx++;
		}
		return NOT_FOUND;
	}
	T get(int idx) override {
		return pairs[idx]->get_data().second;
	}
	int size() override {
		return m_inside_size;
	}
	void print() override {
		for (int i = 0; i < m_inside_size; i++) {
			std::cout << pairs[i]->check_data().first << " | " << pairs[i]->check_data().second << "\n";
		}
	}
	bool isClear() {
		return m_inside_size == 0;
	}
};


#endif  // LINEAR_LIST_TABLE_H_
