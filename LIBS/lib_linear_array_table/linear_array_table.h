// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_LINEAR_ARRAY_TABLE_H_
#define INCLUDE_LINEAR_ARRAY_TABLE_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_interface_table/interface_table.h"

template <class T>
class Array_table : public ITable<T> {
protected:
	std::pair<std::string, T>* pairs;
	int m_size;
	int m_inside_size;

	void write_in_table(std::string key, T tbl_obj, int idx) {
		pairs[idx] = std::pair<std::string, T>(key, tbl_obj);
	}
public:
	Array_table() {
		m_size = DEFAULT_SIZE;
		pairs = new std::pair<std::string, T>[m_size];
		m_inside_size = NULL;
	}
	Array_table(int size) {
		size < MIN_SIZE ?
			throw std::logic_error("The entered size is less than the minimum, error in constructor!") :
			size > MAX_SIZE ? throw std::logic_error("The entered size is larger than the maximum, error in constructor!") :
			m_size = size;
		pairs = new std::pair<std::string, T>[m_size];
		m_inside_size = NULL;
	}
	void insert(std::string key, T tbl_obj) override {
		if (isFull()) throw std::logic_error("Table is full, error in insert method!");
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
		if (idx != m_inside_size - 1) {
			for (int i = idx; i < m_inside_size; i++) {
				pairs[i] = pairs[i + 1];
			}
		}
		m_inside_size--;
	}
	int find(std::string key) override {
		for (int i = 0; i < m_inside_size; i++) {
			if (key == pairs[i].first) {
				return i;
			}
		}
		return NOT_FOUND;
	}
	T get(int idx) override {
		return pairs[idx].second;
	}
	int size() override {
		return m_inside_size;
	}
	int inside_size() {
		return m_size;
	}
	void print() override {
		for (int i = 0; i < m_inside_size; i++) {
			std::cout << pairs[i].first << " | " << pairs[i].second << "\n";
		}
	}
	bool isClear() {
		return m_inside_size == NULL;
	}
	bool isFull() {
		return m_size == m_inside_size;
	}
};

#endif  // INCLUDE_LINEAR_ARRAY_TABLE_H_
