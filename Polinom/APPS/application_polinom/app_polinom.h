// Copyright 2022 Filatov Maxim

#include "../../LIBS/lib_polinom/lib_polinom.h"
#include "../../LIBS/lib_color/Color.h"

#define WIDTH_START_CONSOLE 120

void print_start(std::string text, int width = WIDTH_START_CONSOLE) {
	int new_width = width - text.size();
	if (new_width < 0) { return throw std::exception("Very long text, max size: " + width); }
	int count_first = ceil(new_width * 0.5);
	int count_second = floor(new_width * 0.5);
	std::cout << color(colors::azure) << std::string(count_first, '-')
		<< color(colors::blue_dark) << text
		<< color(colors::azure) << std::string(count_second, '-')
		<< color();
}

void print_end() {
	std::cout << color(colors::azure) 
		<< "\n---------------------------------------"
		<< "-----------------------------------------"
		<< "----------------------------------------\n"
		<< color();
}

void test() {
	Polinom poly = Polinom(CList({ 
		Monom(2, Term({ 
				Var('x', 2),  Var('y', 3),  Var('z', 5) 
			})),
		Monom(3, Term({
				Var('q', 2),  Var('w', 3),  Var('e', 5)
			})),
		Monom(5, Term({
				Var('i', 2),  Var('o', 3),  Var('p', 5)
			})),
		}));
	Polinom poly2 = Polinom(CList({
		Monom(2, Term({
				Var('x', 2),  Var('y', 3),  Var('z', 5)
			})),
		Monom(3, Term({
				Var('q', 2),  Var('w', 3),  Var('e', 5)
			})),
		Monom(5, Term({
				Var('i', 2),  Var('o', 3),  Var('p', 5)
			})),
		}));
	print_start("Task(1 / 12) - print");
	std::cout << color(colors::blue_dark) << "Print: " << color();
	poly.print();
	print_end();
	getch();
	print_start("Task(2 / 12) - plus and minus monom get_string");
	Monom m1 = Monom(13, Term({ Var('x', 2), Var('y', 3) }));
	Monom m2 = Monom(-10, Term({ Var('x', 2), Var('y', 3) }));
	std::cout << color(colors::blue_dark) << "Monom plus: " << color();
	std::cout << m1.get_string();
	std::cout << color(colors::blue_dark) << "\nMonom minus: " << color();
	std::cout << m2.get_string();
	print_end();
	getch();
	print_start("Task(3 / 12) - minus two monoms");
	Monom m3 = m1 - m2;
	std::cout << color(colors::blue_dark) << "Monom minus monom: " << color();
	std::cout << m1.get_string() << m2.get_string();
	std::cout << color(colors::blue_dark) << "\nMonom result: " << color();
	std::cout << m3.get_string();
	print_end();
	getch();
	print_start("Task(4 / 12) - polinom plus monoms");
	Monom m4 = Monom(2, Term({ Var('x', 2),  Var('y', 3),  Var('z', 5) }));
	Monom m4_1 = Monom(2, Term({ Var('q', 2),  Var('w', 3),  Var('e', 5) }));
	Monom m4_2 = Monom(20, Term({ Var('i', 2),  Var('o', 3),  Var('p', 5) }));
	Monom m4_3 = Monom(9, Term({ Var('g', 2)}));
	std::cout << color(colors::blue_dark) << "Polinom: " << color();
	poly.print();
	std::cout << color(colors::blue_dark) << "\nMonom: " << color();
	std::cout << m4.get_string();
	Polinom p1 = poly + m4;
	std::cout << color(colors::blue_dark) << "\nPolinom plus monom result: " << color();
	p1.print();
	std::cout << color(colors::blue_dark) << "\nMonom two: " << color();
	std::cout << m4_1.get_string();
	p1 = p1 + m4_1;
	std::cout << color(colors::blue_dark) << "\nPolinom plus monom two result: " << color();
	p1.print();
	std::cout << color(colors::blue_dark) << "\nMonom three: " << color();
	std::cout << m4_2.get_string();
	p1 = p1 + m4_2;
	std::cout << color(colors::blue_dark) << "\nPolinom plus monom three result: " << color();
	p1.print();
	std::cout << color(colors::blue_dark) << "\nMonom four: " << color();
	std::cout << m4_3.get_string();
	p1 = p1 + m4_3;
	std::cout << color(colors::blue_dark) << "\nPolinom plus monom four result: " << color();
	p1.print();
	print_end();
	getch();
	Polinom p2 = p1;
	print_start("Task(5 / 12) - polinom plus polinom");
	std::cout << color(colors::blue_dark) << "Polinom:                      " << color();
	p1.print();
	p1 += p1;
	std::cout << color(colors::blue_dark) << "\nPolinom plus polinom result:  " << color();
	p1.print();
	p1 = p1 + p1;
	std::cout << color(colors::blue_dark) << "\nPolinom plus polinom result: " << color();
	p1.print();
	print_end();
	getch();
	print_start("Task(6 / 12) - polinom print with no brackets");
	Polinom p3 = Polinom(
		CList<Monom>({
			Monom(1, {}),
			Monom(2, {Var('x', 2)}),
			Monom(3, {Var('x', 2), Var('y', 3)}),
			Monom(4, {Var('x', 2), Var('y', 3), Var('z', 4)}),
			Monom(5, {Var('x', 2), Var('y', 3), Var('z', 4), Var('i', 5)}),
		})
	);
	Polinom p3_1 = Polinom(
		CList<Monom>({
			Monom(1, {}),
			Monom(2, {Var('x', 2)}),
			Monom(3, {Var('y', 3)}),
			Monom(4, {Var('z', 4)}),
			Monom(5, {Var('i', 5)}),
			})
			);
	std::cout << color(colors::blue_dark) << "Default polinom: " << color();
	std::cout << p3.get_string(false);
	std::cout << color(colors::blue_dark) << "\nNo brackets polinom: " << color();
	std::cout << p3.get_string(true);
	std::cout << color(colors::blue_dark) << "\nDefault polinom: " << color();
	std::cout << p3_1.get_string(false);
	std::cout << color(colors::blue_dark) << "\nNo brackets polinom: " << color();
	std::cout << p3_1.get_string(true);
	print_end();
	getch();
	print_start("Task(7 / 12) - monom multiply monom");
	Monom m5 = Monom(5, {Var('x', 2), Var('y', 2)});
	Monom m6 = Monom(20, {Var('x', 4), Var('y', 4), Var('z', 6)});
	std::cout << color(colors::blue_dark) << "First monom:              " << color();
	std::cout << m5.get_string(false);
	std::cout << color(colors::blue_dark) << "\nSecond monom:            " << color();
	std::cout << m6.get_string(false);
	Monom m7 = m5 * m6;
	std::cout << color(colors::blue_dark) << "\nResult myltiply monoms: " << color();
	std::cout << m7.get_string(false);
	print_end();
	getch();
	print_start("Task(8 / 12) - polinom multiply monom");
	Polinom p4 = Polinom(CList<Monom>({
			Monom(3, Term({Var('x', 2), Var('y', 2), Var('z', 2)})),
			Monom(6, Term({Var('x', 3), Var('y', 3), Var('z', 3)})),
		}));
	std::cout << color(colors::blue_dark) << "Polinom: " << color();
	std::cout << p4.get_string();
	Monom m8 = Monom(2, Term({ Var('x', 2), Var('y', 3) }));
	std::cout << color(colors::blue_dark) << "\nMonom: " << color();
	std::cout << m8.get_string();
	p4 = p4 * m8;
	std::cout << color(colors::blue_dark) << "\nMultiply result: " << color();
	std::cout << p4.get_string();
	print_end();
	getch();
	print_start("Task(9 / 12) - hard polinom multiply");
	Polinom p5 = Polinom(CList<Monom>({
			Monom(2, Term({Var('x', 2)})),
			Monom(4, Term({Var('y', 3)})),
			Monom(6, Term({Var('z', 4)})),
		}));
	Polinom p6 = Polinom(CList<Monom>({
			Monom(3, Term({Var('z', 4)})),
			Monom(-5, Term({Var('y', 3)})),
			Monom(-7, Term({Var('x', 2)})),
		}));
	std::cout << color(colors::blue_dark) << "Polinom first: " << color();
	p5.print();
	std::cout << color(colors::blue_dark) << "\nPolinom second: " << color();
	p6.print();
	Polinom p7 = p5 * p6;
	std::cout << color(colors::blue_dark) << "\nMultiply result: " << color();
	p7.print();
	print_end();
	getch();
	print_start("Task(10 / 12) - add monoms");
	Monom p8m1 = Monom(4, Term({ Var('x', 2) }));
	Monom p8m2 = Monom(5, Term({ Var('x', 2) }));
	Monom p8m3 = Monom(6, Term({ Var('x', 2) }));
	Monom p8m4 = Monom(7, Term({ Var('x', 2) }));
	Polinom p8 = Polinom(CList<Monom>({
			p8m1,
			p8m2,
			p8m3,
			p8m4,
		}));
	std::cout << color(colors::blue_dark) << "\nMonom one:   " << color();
	std::cout << p8m1.get_string_for_solve();
	std::cout << color(colors::blue_dark) << "\nMonom two:   " << color();
	std::cout << p8m2.get_string_for_solve();
	std::cout << color(colors::blue_dark) << "\nMonom three: " << color();
	std::cout << p8m3.get_string_for_solve();
	std::cout << color(colors::blue_dark) << "\nMonom four:  " << color();
	std::cout << p8m4.get_string_for_solve();
	std::cout << color(colors::blue_dark) << "\nPolinom:    " << color();
	std::cout << p8.get_string_for_solve();
	print_end();
	getch();
	print_start("Task(11 / 12) - set vars and solve");
	p8.set_vars({ {'x', 2}, {'y', 2}, {'z', 2}});
	std::cout << color(colors::blue_dark) << "Polinom: " << color();
	p8.print();
	std::cout << color(colors::blue_dark) << "\nVars: " << color();
	std::cout << "x = 2";
	std::cout << color(colors::blue_dark) << "\nCalculate result: " << color();
	std::cout << p8.calculate();
	print_end();
	getch();
	print_start("Task(12 / 12) - Polinom equals");
	Polinom p9 = Polinom(CList<Monom>({
			Monom(4, Term({Var('x', 2)})),
			Monom(5, Term({Var('y', 3)})),
		}));
	Polinom p10 = Polinom(CList<Monom>({
			Monom(4, Term({Var('x', 2)})),
			Monom(5, Term({Var('y', 3)})),
		}));
	Polinom p11 = Polinom(CList<Monom>({
			Monom(4, Term({Var('x', 2)})),
			Monom(7, Term({Var('z', 5)})),
		}));
	bool eq1 = p9 == p10;
	bool eq2 = p9 == p11;
	std::cout << color(colors::blue_dark) << "Polinom first: " << color();
	p9.print();
	std::cout << color(colors::blue_dark) << "\nPolinom second: " << color();
	p10.print();
	std::cout << color(colors::blue_dark) << "\nPolinom third: " << color();
	p11.print();
	std::cout << color(colors::blue_dark) << "\nFirst equal second: " << color();
	if (eq1) { std::cout << color(colors::green) << "true"; }
	else { std::cout << color(colors::red) << "false"; }
	std::cout << color(colors::blue_dark) << "\nFirst equal to third: " << color();
	if (eq2) { std::cout << color(colors::green) << "true"; }
	else { std::cout << color(colors::red) << "false"; }
	print_end();
	getch();
}