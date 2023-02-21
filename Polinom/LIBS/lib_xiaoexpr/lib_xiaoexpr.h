// Copyright 2022 Filatov Maxim
#ifndef INCLUDE_XIAOEXPR_H_
#define INCLUDE_XIAOEXPR_H_
#include <vector>
#include <stack>
#include <string>
#include <math.h>
// [EN] Namespace XiaoExpr 
// [RU] Пространство имён XiaoExpr
namespace XE {//XiaoExpr {
#pragma region Defines

#define OPEN_BRACKET 40
#define CLOSE_BRACKET 41
#define COMMA 44
#define PLUS 43
#define MINUS 45
#define MULTIPLY 42
#define DEVIDE 47
#define EXPONINTEALE 94
#define FACTORIAL 33
#define DOT 46
#define SPACE 32
#define START_NUMBERS 48
#define END_NUMBERS 57
#define START_UPPERCASE_LETTER 65
#define END_UPPERCASE_LETTER 90
#define START_LOWERCASE_LETTER 97
#define END_LOWERCASE_LETTER 122
#define FUNCTION_OFFSET 200
#define XE_PI 3.1415926535897931

#pragma endregion

	int str_to_int(std::string _str);

	double str_to_double(std::string _str);


	// [EN] Sample custom function
	// [RU] Шаблон пользовательской функции
	typedef double(*CustomFunc) (std::stack<double>&);

	namespace funcs_lib {

		double _abs(std::stack<double>& content);

		double _ceil(std::stack<double>& content);

		double _floor(std::stack<double>& content);

		double _cos(std::stack<double>& content);

		double _sin(std::stack<double>& content);

		double _tan(std::stack<double>& content);

		double _log(std::stack<double>& content);

		/*double _log10(std::stack<double>& content);*/

		double _sqrt(std::stack<double>& content);

		/*double _acos(std::stack<double>& content);*/

		/*double _asin(std::stack<double>& content);*/

		double _atan2(std::stack<double>& content);

		/*double _cosh(std::stack<double>& content);

		double _sinh(std::stack<double>& content);*/
	}

	// [EN] Namespace add in XiaoExpr 
	// [RU] Пространство имён add в XiaoExpr
	namespace add {
		// [EN] Add variable
		// [RU] Добавление переменной
		void var(std::pair<char, double> variable);
		void vars(std::vector<std::pair<char, double>> variables);

		// [EN] Add function
		// [RU] Добавление функции
		void func(std::pair<std::string, CustomFunc> function);
		void funcs(std::vector<std::pair<std::string, CustomFunc>> function);
	}

	namespace check {
		bool var(char name);
		bool vars(std::vector<char> names);
		
		bool func(std::string name);
		bool funcs(std::vector<std::string> names);
	}
	// [EN] Namespace del in XiaoExpr 
	// [RU] Пространство имён del в XiaoExpr
	namespace del {
		/// <summary>
		/// <para>[EN] Del variable</para>
		/// [RU] Удаление переменной
		/// </summary>
		void var(char name);
		void vars(std::vector<char> names);

		/// <summary>
		/// <para>[EN] Del function</para>
		/// [RU] Удаление функции
		/// </summary>
		void func(std::string name);
		void funcs(std::vector<std::string> names);
	}

	void load_default_functions_library();

	// [EN] Class Solver for Expression
	// [RU] Класс Solver для выражений
	class Solver {
	private:
		int current_element;
		int actions_top;
		int current_priority;
		int last_priority;
		double first_num;
		double second_num;
		double last_answer;
		unsigned int expr_size;
		std::string word;
		std::stack<double> stack_for_function;
		std::stack<double> numbers;
		std::stack<int> actions;
		bool last_close_bracket;
		bool last_factorial_action;

		int get_func_id(std::string name);
		void stacks_action_evaluate();
		void stacks_calculate();
		int calculate_priority(char action);
		void clear_stack(std::stack<double>& stack);

	public:
		// [EN] Solver default constructor
		// [RU] Конструктор по умолчанию для Solver 
		Solver();

		// [EN] Expression calculate
		// [RU] Вычисление выражения
		double calculate(std::string expr);

		double call_func(int id, std::stack<double>& content);
		double get_value_var(char name);

		/// <summary>
		/// <para>[EN] Solver destructor</para>
		/// <para>[RU] Деструктор для Solver</para>
		/// </summary>
		~Solver();
	};
}

#endif  // INCLUDE_XIAOEXPR_H_
