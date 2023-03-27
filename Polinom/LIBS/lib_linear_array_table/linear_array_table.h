﻿// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_LINEAR_ARRAY_TABLE_H_
#define INCLUDE_LINEAR_ARRAY_TABLE_H_

#define MIN_SIZE 1
#define DEFAULT_SIZE 10
#define MAX_SIZE 100
#define NOT_FOUND -1

#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_interface_table/interface_table.h"

class Array_table : public iTable {
private:
	std::string* m_keys;
	Polinom* m_polinoms;
	int m_size;
	int m_inside_size;

	void place(std::string key, Polinom polinom, int idx) {
		m_keys[idx] = key;
		m_polinoms[idx] = polinom;
	}
public:
	Array_table() {
		m_size = DEFAULT_SIZE;
		m_keys = new std::string[m_size];
		m_polinoms = new Polinom[m_size];
		m_inside_size = NULL;
	}
	Array_table(int size) {
		size < MIN_SIZE ?
			throw std::logic_error("The entered size is less than the minimum, error in constructor!") :
			size > MAX_SIZE ? throw std::logic_error("The entered size is larger than the maximum, error in constructor!") :
			m_size = size;
		m_keys = new std::string[m_size];
		m_polinoms = new Polinom[m_size];
		m_inside_size = NULL;
	}
	void insert(std::string key, Polinom polinom) override {
		if (isFull()) throw std::logic_error("Table is full, error in insert method!");
		int idx = find(key);
		if (idx != NOT_FOUND) throw std::logic_error("The table already has an instance with the same name, error in insert method!");
		place(key, polinom, m_inside_size);
		m_inside_size++;
	}
	void update(std::string key, Polinom polinom) override {
		int idx = find(key);
		if (idx == NOT_FOUND) throw std::logic_error("The specified element was not found, error in update method!");
		place(key, polinom, idx);
	}
	void remove(std::string key) override {
		if (isClear()) throw std::logic_error("Table is clear, error in remove method!");
		int idx = find(key);
		if (idx == NOT_FOUND) throw std::logic_error("The specified element was not found, error in remove method!");
		if (idx != m_inside_size - 1) {
			for (int i = idx; i < m_inside_size; i++) {
				m_keys[i] = m_keys[i + 1];
				m_polinoms[i] = m_polinoms[i + 1];
			}
		}
		m_inside_size--;
	}
	int find(std::string key) override {
		for (int i = 0; i < m_inside_size; i++) {
			if (key == m_keys[i]) {
				return i;
			}
		}
		return NOT_FOUND;
	}
	Polinom get(int idx) override {
		return m_polinoms[idx];
	}
	int size() override {
		return m_size;
	}
	int inside_size() {
		return m_inside_size;
	}
	void print() override {
		for (int i = 0; i < m_inside_size; i++) {
			std::cout << m_keys[i] << " | " << m_polinoms[i].get_string() << std::endl;
		}
	}
	bool isClear() {
		return m_size == NULL;
	}
	bool isFull() {
		return m_size == m_inside_size;
	}
};

#endif  // INCLUDE_LINEAR_ARRAY_TABLE_H_