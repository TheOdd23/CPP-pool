#ifndef RPN_HPP
#define RPN_HPP

#pragma once
#include <string>
#include <stack>
#include <iterator>
#include <iostream>

class RPN
{
	public:
		RPN(const std::string expr);
		~RPN();

		void	do_op();

	private:
		std::stack<float>	nums;
		std::string	expression;
		bool	error;

		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		bool	is_valid_op(char c);
		bool	valid_args(std::string expression);
		void	print_result();
		double	operate(float a, float b, char c);
		bool	is_valid_int(char c);
};

#endif