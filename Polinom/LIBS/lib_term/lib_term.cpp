// Copyright 2022 Filatov Maxim

#include "../lib_term/lib_term.h"

#pragma region Realization

std::string Var::get_string(bool ignore_brackets) {
	std::string out = "";
	out = std::string(
		(ignore_brackets ? "" : "(") +
		std::string(1, character) +
		std::string(1, '^') +
		std::to_string(power) +
		(ignore_brackets ? "" : ")")
	);
	return out;
}

bool Var::operator == (Var var) {
	return character == var.character && power == var.power;
}
bool Var::operator != (Var var) {
	return !(*this == var);
}

Var::Var() {
	character = NULL;
	power = NULL;
}

Var::Var(char _character, int _power) {
	character = _character;
	power = _power;
}

void Var::copy_from(Var var) {
	this->character = var.character;
	this->power = var.power;
}

std::string Term::get_string(bool ignore_brackets) {
	std::string out = "";
	for (auto& var : vars) {
		out += var.get_string(ignore_brackets);
	}
	return out;
}

std::string Term::get_string_for_solve() {
	std::string out = "";
	bool first = true;
	for (auto& var : vars) {
		out += (first ? "" : "*") + var.get_string();
		first ? first = !first : NULL;
	}
	return out;
}

Term::Term() {
	vars = std::vector<Var>();
}

Term::Term(std::initializer_list<Var> var_list) {
	for (auto elem : var_list) {
		this->add(elem);
	}
}

void Term::add(Var var) {
	for (auto& element : vars) {
		if (element.character == var.character) {
			element.power += var.power;
			return;
		}
	}
	vars.push_back(var);
}

void Term::add(Term term) {
	for (auto& element : term.vars) {
		this->add(element);
	}
}

bool Term::equal_vars(Term term) {
	bool equal = true;
	if (vars.empty() && term.vars.empty()) {
		return true;
	}
	if (vars.size() != term.vars.size()) {
		return false;
	}
	for (auto& main_element : vars) {
		if (!equal) {
			return false;
		}
		else {
			equal = false;
		}
		for (const auto& term_element : term.vars) {
			if (main_element.character == term_element.character) {
				equal = true;
				break;
			}
		}
	}
	return equal;
}

bool Term::equal_vars_coeff(Term term) {
	bool equal = true;
	if (vars.empty() && term.vars.empty()) {
		return true;
	}
	if (vars.size() != term.vars.size()) {
		return false;
	}
	for (auto& main_element : vars) {
		if (!equal) {
			return false;
		}
		else {
			equal = false;
		}
		for (const auto& term_element : term.vars) {
			if (main_element == term_element) {
				equal = true;
				break;
			}
		}
	}
	return equal;
}

void Term::copy_from(Term term) {
	this->vars.clear();
	for (auto const& var : term.vars) {
		Var temp;
		temp.copy_from(var);
		this->vars.push_back(temp);
	}
}

bool Term::operator == (Term term) {
	return equal_vars_coeff(term);
}

#pragma endregion