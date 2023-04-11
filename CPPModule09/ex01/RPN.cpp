#include "RPN.hpp"

RPN::RPN(){};

RPN::RPN(std::string expr): expression(expr)
{
	error = valid_args(expression);
}

RPN::~RPN(){}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN	&RPN::operator=(const RPN &other)
{
	nums = other.nums;
	error = other.error;
	expression = other.expression;
	return *this;
}

bool RPN::is_valid_int(char c)
{
	std::string ints("0123456789");

	if (ints.find(c) != ints.npos)
		return true;
	return false;
}

bool RPN::is_valid_op(char c)
{
	std::string ints("+-*/");

	if (ints.find(c) != ints.npos)
		return true;
	return false;
}

bool	RPN::valid_args(std::string expression)
{
	if (expression.empty())
		return true;
	for (size_t i = 0; i < expression.size(); i++)
	{
		if (expression[i] == ' ')
			continue;
		else if ((is_valid_int(expression[i]) || is_valid_op(expression[i])) && (i + 1 == expression.size() || expression[i + 1] == ' '))
		{
			continue;
		}
		else
			return true;
	}
	return false;
}

double	RPN::operate(float a, float b, char c)
{
	switch(c)
	{
		case 42:
			return (a * b);
		case 43:
			return (a + b);
		case 45:
			return (a - b);
		case 47:
			return (a / b);
	}
	return -1;
}

void	RPN::do_op()
{
	if (error == true)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	float a, b;
	std::string::iterator it;
	for(it = expression.begin(); it != expression.end(); it++)
	{
		if(is_valid_op(*it))
		{
			if(nums.empty() || nums.size() == 1)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			b = nums.top();
			nums.pop();
			a = nums.top();
			nums.pop();
			nums.push(operate(a, b, *it));
		}
		else if(is_valid_int(*it))
		{
			nums.push(static_cast<double>(*it - 48));
		}
	}
	std::cout << nums.top() << std::endl;
}
