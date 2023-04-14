// Copyright 2023 Filatov Maxim

#include "../lib_polinom/lib_polinom.h"

#pragma region Realization

Polinom::Polinom() {
	monomial_list = CList<Monom>();
}

Polinom::Polinom(const Polinom& polinom) {
	monomial_list.clear();
	if (polinom.isEmpty()) {
		return;
	}
	for (const auto& element : polinom.monomial_list) {
		auto temp_data = element.check_data();
		Term temp_term;
		temp_term.copy_from(temp_data.term);
		this->monomial_list.push_back(Monom(temp_data.coefficient, temp_term));
	}
}

Polinom::Polinom(CList<Monom> _monomial_list) {
	for (const auto& element : _monomial_list) {
		this->add_monom(element.check_data());
	}
}

void  Polinom::add_monom(Monom monom) {
	if (!this->isEmpty()) {
		for (const auto& element : monomial_list) {
			if (element.check_data().term.equal_vars_coeff(monom.term)) {
				*this += monom;
				return;
			}
		}
	}
	monomial_list.push_back(monom);
}

void Polinom::print(bool ignore_brackets) {
	std::cout << this->get_string();
}

std::string Polinom::get_string(bool ignore_brackets) {
	bool first = true;
	std::string out = "";
	for (const auto& element : monomial_list) {
		out += ((element.check_data().coefficient) > 0 ? !first ? "+" : "" : "");
		first ? first = !first : NULL;
		out += element.check_data().get_string(ignore_brackets);
	}
	return out;
}

std::string Polinom::get_string_for_solve() {
	bool first = true;
	std::string out = "";
	for (const auto& element : monomial_list) {
		out += ((element.check_data().coefficient) > 0 ? !first ? "+" : "" : "");
		first ? first = !first : NULL;
		out += element.check_data().get_string_for_solve();
	}
	return out;
}


void Polinom::set_vars(std::vector<std::pair<char, double>> vars) {
	XE::add::vars(vars);
}

double Polinom::calculate() {
	return solver.calculate(get_string_for_solve());
}

bool Polinom::isEmpty() const {
	return monomial_list.isEmpty();
}

Polinom Polinom::operator = (Polinom polinom) {
	monomial_list.clear();
	if (polinom.isEmpty()) {
		return *this;
	}
	for (const auto& element : polinom.monomial_list) {
		auto temp_data = element.check_data();
		Term temp_term;
		temp_term.copy_from(temp_data.term);
		this->monomial_list.push_back(Monom(temp_data.coefficient, temp_term));
	}
	return *this;
}

bool Polinom::operator == (Polinom polinom) {
	bool equal = true;
	if (this->isEmpty() && polinom.isEmpty()) {
		return true;
	}
	if (this->monomial_list.size() != polinom.monomial_list.size()) {
		return false;
	}
	for (auto& main_element : monomial_list) {
		if (!equal) {
			return false;
		}
		else {
			equal = false;
		}
		for (const auto& term_element : polinom.monomial_list) {
			if (main_element.check_data() == term_element.check_data()) {
				equal = true;
				break;
			}
		}
	}
	return equal;
}

Polinom Polinom::operator * (Polinom polinom) {
	Polinom out_poly = Polinom();
	for (auto& element : polinom.monomial_list) {
		out_poly += (*this) * element.get_data();
	}
	return out_poly;
}

Polinom Polinom::operator *= (Polinom polinom) {
	return *this = *this * polinom;
}

Polinom Polinom::operator + (Polinom polinom) {
	if (this->isEmpty()) { return Polinom(polinom); }
	Polinom temp_poly = *this;
	Polinom out_poly;
	for (auto& element : polinom.monomial_list) {
		*this = *this + element.get_data();
	}
	out_poly = *this;
	*this = temp_poly;
	return out_poly;
}

Polinom Polinom::operator += (Polinom polinom) {
	return *this = *this + polinom;
}

Polinom Polinom::operator - (Polinom polinom) {
	if (this->isEmpty()) { return Polinom(polinom) * Monom(-1); }
	Polinom temp_poly = *this;
	Polinom out_poly;
	for (auto& element : polinom.monomial_list) {
		*this = *this - element.get_data();
	}
	out_poly = *this;
	*this = temp_poly;
	return out_poly;
}

Polinom Polinom::operator -= (Polinom polinom) {
	return *this = *this - polinom;
}

Polinom Polinom::operator *= (Monom monom) {
	return *this = *this * monom;
}

Polinom Polinom::operator * (Monom monom) {
	Polinom out_poly;
	for (const auto& element : monomial_list) {
		out_poly.add_monom(element.check_data() * monom);
	}
	return out_poly;
}

Polinom Polinom::operator + (Monom monom) {
	Polinom temp_poly = *this;
	Polinom out_poly;
	bool action = false;
	for (auto& element : monomial_list) {
		if (element.get_data().term.equal_vars_coeff(monom.term)) {
			element.set_data(element.get_data() + monom);
			action = !action;
			break;
		}
	}
	out_poly = *this;
	*this = temp_poly;
	action ? void() : out_poly.add_monom(monom);
	return out_poly;
}

Polinom Polinom::operator += (Monom monom) {
	return *this = *this + monom;
}

Polinom Polinom::operator - (Monom monom) {
	Polinom temp_poly = *this;
	Polinom out_poly;
	bool action = false;
	for (auto& element : monomial_list) {
		if (element.get_data().term.equal_vars_coeff(monom.term)) {
			element.set_data(element.get_data() - monom);
			action = !action;
			break;
		}
	}
	out_poly = *this;
	*this = temp_poly;
	action ? void() : out_poly.add_monom(monom * Monom(-1));
	return out_poly;
}

Polinom Polinom::operator -= (Monom monom) {
	return *this = *this - monom;
}

Monom Polinom::operator [] (int index) {
	return monomial_list[index]->get_data();
}

Polinom Polinom::operator * (int number) {
	return *this * Monom(number);
}
Polinom Polinom::operator *= (int number) {
	return *this = *this * Monom(number);
}
Polinom Polinom::operator + (int number) {
	return *this + Monom(number);
}
Polinom Polinom::operator += (int number) {
	return *this = *this + Monom(number);
}
Polinom Polinom::operator - (int number) {
	return *this - Monom(number);
}
Polinom Polinom::operator -= (int number) {
	return *this = *this - Monom(number);
}

Polinom::~Polinom() {}

std::ostream& operator<<(std::ostream& os, const Polinom& polinom) {
	bool first = true;
	std::string out = "";
	for (auto& element : polinom.monomial_list) {
		out += ((element.check_data().coefficient) > 0 ? !first ? "+" : "" : "");
		first ? first = !first : NULL;
		out += element.check_data().get_string(false);
	}
	return os << out;
}

#pragma endregion