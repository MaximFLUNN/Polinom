// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_INTERFACE_TABLE_H_
#define INCLUDE_INTERFACE_TABLE_H_

#include "../../LIBS/lib_polinom/lib_polinom.h"
#include <string>

#define MIN_SIZE 1
#define DEFAULT_SIZE 10
#define MAX_SIZE 100
#define NOT_FOUND -1

template <class T>
class iTable {
public:
	void virtual insert(std::string key, T polinom) = 0;
	void virtual update(std::string key, T polinom) = 0;
	void virtual remove(std::string key) = 0;
	int virtual find(std::string key) = 0;
	T virtual get(int idx) = 0;
	int virtual size() = 0;
	void virtual print() = 0;
};

#endif  // INCLUDE_INTERFACE_TABLE_H_
