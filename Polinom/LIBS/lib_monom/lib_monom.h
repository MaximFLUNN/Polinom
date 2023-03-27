// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_MONOM_H_
#define INCLUDE_MONOM_H_

#include "../lib_term/lib_term.h"
#include <stdexcept>

//class Monom;

class Monom {
public:
	Term term;
	int coefficient;

	Monom();
	Monom(const Monom& monom);
	Monom(int _coefficient);
	Monom(int _coefficient, Term _term);
	~Monom();

	std::string get_string(bool ignore_brackets = false);
	std::string get_string_for_solve();
	bool operator == (Monom monom);
	Monom operator = (Monom monom);
	Monom operator * (Monom monom);
	Monom operator *= (Monom monom);
	Monom operator + (Monom monom);
	Monom operator += (Monom monom);
	Monom operator - (Monom monom);
	Monom operator -= (Monom monom);

private:

};

#endif  // INCLUDE_MONOM_H_

