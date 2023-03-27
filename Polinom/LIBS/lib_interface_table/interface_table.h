// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_INTERFACE_TABLE_H_
#define INCLUDE_INTERFACE_TABLE_H_

#include "../../LIBS/lib_polinom/lib_polinom.h"
#include <string>

class iTable {
public:
	void virtual insert(std::string key, Polinom polinom) = 0;
	void virtual update(std::string key, Polinom polinom) = 0;
	void virtual remove(std::string key) = 0;
	int virtual find(std::string key) = 0;
	Polinom virtual get(int idx) = 0;
	int virtual size() = 0;
	void virtual print() = 0;
};

#endif  // INCLUDE_INTERFACE_TABLE_H_
