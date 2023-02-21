// Copyright 2022 Filatov Maxim

#include "../lib_monom/lib_monom.h"

#pragma region Realization

Monom::Monom():coefficient(NULL) {}

Monom::Monom(int _coefficient) {
	coefficient = _coefficient;
	term = Term();
}

Monom::Monom(int _coefficient, Term _term) {
	coefficient = _coefficient;
	term.copy_from(_term);
}

Monom::Monom(const Monom& monom) {
	coefficient = monom.coefficient;
	term.copy_from(monom.term);
}

Monom::~Monom() {}

std::string Monom::get_string(bool ignore_brackets) {
	std::string out;
	out = std::to_string(coefficient) +
		(ignore_brackets ? "" : "(") +
		term.get_string(ignore_brackets) +
		(ignore_brackets ? "" : ")");
	return out;
}

std::string Monom::get_string_for_solve() {
	return std::to_string(coefficient) + "*(" + term.get_string_for_solve() + ')';
}

Monom Monom::operator = (Monom monom) {
	coefficient = monom.coefficient;
	term.copy_from(monom.term);
	return *this;
}

bool Monom::operator == (Monom monom) {
	return coefficient == monom.coefficient && term == monom.term;
}

Monom Monom::operator *= (Monom monom) {
	return *this = *this * monom;
}

Monom Monom::operator * (Monom monom) {
	Monom out_monom = *this;
	out_monom.coefficient *= monom.coefficient;
	out_monom.term.add(monom.term);
	return out_monom;
}

Monom Monom::operator + (Monom monom) {
	Monom temp = Monom(*this);
	if (this->term.equal_vars_coeff(monom.term)) {
		temp.coefficient += monom.coefficient;
	}
	else {
		throw std::logic_error("vars and coeff not equal");
	}
	return temp;
}

Monom Monom::operator += (Monom monom) {
	return *this = *this + monom;
}

Monom Monom::operator - (Monom monom) {
	Monom temp = Monom(*this);
	if (this->term.equal_vars_coeff(monom.term)) {
		temp.coefficient -= monom.coefficient;
	}
	else {
		throw std::logic_error("vars and coeff not equal");
	}
	return temp;
}

Monom Monom::operator -= (Monom monom) {
	return *this = *this - monom;
}

#pragma endregion