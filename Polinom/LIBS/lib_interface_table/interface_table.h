// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_INTERFACE_TABLE_H_
#define INCLUDE_INTERFACE_TABLE_H_

#include "../../LIBS/lib_polinom/lib_polinom.h"
#include <string>

#define MIN_SIZE 1
#define DEFAULT_SIZE 10
#define MAX_SIZE 100
#define MAX_TABLE_ELEMENTS 5000
#define NOT_FOUND -1

template <class T>
class ITable {
public:
	void virtual insert(std::string key, T tbl_obj) = NULL;
	void virtual update(std::string key, T tbl_obj) = NULL;
	void virtual remove(std::string key) = NULL;
	int virtual find(std::string key) = NULL;
	T virtual get(int idx) = NULL;
	int virtual size() = NULL;
	void virtual print() = NULL;
};

#endif  // INCLUDE_INTERFACE_TABLE_H_
