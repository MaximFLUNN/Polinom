// Copyright 2022 Filatov Maxim
#ifndef INCLUDE_POLINOM_H_
#define INCLUDE_POLINOM_H_

#include "../lib_list/lib_list.h"
#include "../lib_monom/lib_monom.h"
#include "../lib_xiaoexpr/lib_xiaoexpr.h"

class Polinom {
public:
	CList<Monom> monomial_list;
	XE::Solver solver;
	Polinom();
	Polinom(const Polinom& polinom);
	Polinom(CList<Monom> _monomisl_list);
	~Polinom();

	bool isEmpty() const;
	void add_monom(Monom monom);
	void print(bool ignore_brackets = false);
	std::string get_string(bool ignore_brackets = false);
	std::string get_string_for_solve();
	void set_vars(std::vector<std::pair<char, double>> vars);
	double calculate();
	bool operator == (Polinom polinom);
	Polinom operator = (Polinom polinom);
	Polinom operator * (Polinom polinom);
	Polinom operator *= (Polinom polinom);
	Polinom operator + (Polinom polinom);
	Polinom operator += (Polinom polinom);
	Polinom operator - (Polinom polinom);
	Polinom operator -= (Polinom polinom);
	Polinom operator * (Monom monom);
	Polinom operator *= (Monom monom);
	Polinom operator + (Monom monom);
	Polinom operator += (Monom monom);
	Polinom operator - (Monom monom);
	Polinom operator -= (Monom monom);
	Polinom operator * (int number);
	Polinom operator *= (int number);
	Polinom operator + (int number);
	Polinom operator += (int number);
	Polinom operator - (int number);
	Polinom operator -= (int number);
	Monom operator [] (int index);
private:

};

#endif  // INCLUDE_POLINOM_H_
