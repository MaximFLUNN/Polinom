// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_TERM_H_
#define INCLUDE_TERM_H_

#include <string>
#include <vector>

struct Var;
struct Term;

struct Var {
	char character;
	int power;

	Var();
	Var(char _character, int _power);
	void copy_from(Var var);
	std::string get_string(bool ignore_brackets = false);
	bool operator == (Var var);
	bool operator != (Var var);
};

struct Term {
	std::vector<Var> vars;

	Term();
	Term(std::initializer_list<Var> var_list);
	void add(Var var);
	void add(Term term);
	bool equal_vars(Term term);
	bool equal_vars_coeff(Term term);
	std::string get_string(bool ignore_brackets = false);
	std::string get_string_for_solve();
	void copy_from(Term term);
	bool operator == (Term term);
};



#endif  // INCLUDE_TERM_H_
