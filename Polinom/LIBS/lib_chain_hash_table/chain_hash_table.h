// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_CHAIN_HASH_TABLE_H_
#define INCLUDE_CHAIN_HASH_TABLE_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_interface_table/interface_table.h"

template <class T>
class ChainHashTable: ITable<T> {
protected:
	CList<std::pair<std::string, T>>* lists_arr;
	int m_size;
	int m_objects_count;
	int m_temp_index_buffer;

	int hashFunc(std::string key) {
		int result_position = NULL;
		for (const auto elem : key) {
			result_position += abs(static_cast<int>(elem));
		}
		return result_position % m_size;
	}

	void write_in_table(std::string key, T tbl_obj, int idx) {
		if (lists_arr[m_temp_index_buffer].size() <= idx) {
			lists_arr[m_temp_index_buffer].push_back(std::pair<std::string, T>(key, tbl_obj));
		}
		else {
			lists_arr[m_temp_index_buffer][idx]->set_data(std::pair<std::string, T>(key, tbl_obj));
		}
	}
public:
	ChainHashTable() {
		m_size = DEFAULT_SIZE;
		lists_arr = new CList<std::pair<std::string, T>>[m_size];
		m_objects_count = NULL;
		m_temp_index_buffer = NULL;
	}
	ChainHashTable(int size) {
		size < MIN_SIZE ?
			throw std::logic_error("The entered size is less than the minimum, error in constructor!") :
			size > MAX_SIZE ? throw std::logic_error("The entered size is larger than the maximum, error in constructor!") :
			m_size = size;
		lists_arr = new CList<std::pair<std::string, T>>[m_size];
		m_objects_count = NULL;
		m_temp_index_buffer = NULL;
	}
	void insert(std::string key, T tbl_obj) override {
		if (isFull()) throw std::logic_error("Table is full, error in insert method!");
		int idx = find(key);
		if (idx != NOT_FOUND) throw std::logic_error("The table already has an instance with the same name, error in insert method!");
		write_in_table(key, tbl_obj, NULL);
		m_objects_count++;
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
		int l_size = lists_arr[m_temp_index_buffer].size();
		if (l_size <= 1) {
			lists_arr[m_temp_index_buffer].clear();
		}
		else {
			lists_arr[m_temp_index_buffer].erase(idx);
		}
	}
	int find(std::string key) override {
		m_temp_index_buffer = hashFunc(key);
		int i = NULL;
		if (!lists_arr[m_temp_index_buffer].isEmpty()) {
			for (auto elem : lists_arr[m_temp_index_buffer]) {
				if (key == elem.get_data().first) {
					return i;
				}
				else {
					i++;
				}
			}
		}
		return NOT_FOUND;
	}
	T get(int idx) override {
		return lists_arr[m_temp_index_buffer][idx]->get_data().second;
	}
	int size() override {
		return m_size;
	}
	int get_objects_count() {
		return m_objects_count;
	}
	void print() override {
		for (int i = 0; i < m_size; i++) {
			if (!lists_arr[i].isEmpty()) {
				for (auto elem : lists_arr[i]) {
					std::cout << elem.get_data().first << " | " << elem.get_data().second << "\n";
				}
			}
		}
	}
	int get_temp_index_buffer() {
		return m_temp_index_buffer;
	}
	void set_temp_index_buffer(int value) {
		if (value > m_size) {
			throw std::logic_error("Value too large, greater than the size of the current table!");
		}
		if (value < MIN_SIZE) {
			throw std::logic_error("Too small value!");
		}
		m_temp_index_buffer = value;
	}
	bool isClear() {
		return m_objects_count == NULL;
	}
	bool isFull() {
		return m_objects_count >= MAX_TABLE_ELEMENTS;
	}
	~ChainHashTable() {}

private:

};

#endif  // INCLUDE_CHAIN_HASH_TABLE_H_
