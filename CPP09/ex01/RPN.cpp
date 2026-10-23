/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:05:43 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 16:54:01 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const std::string &str)
{
	parse_string(str);
}

RPN::RPN(const RPN &other)
{
	_lst = other._lst;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_lst.clear();
		_lst = other._lst;
	}
	return *this;
}

long RPN::execute_addition()
{
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);
	return *second_to_last + _lst.back();
}

long RPN::execute_subtraction()
{
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);
	return *second_to_last - _lst.back();
}

long RPN::execute_multiplication()
{
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);
	return *second_to_last * _lst.back();
}

int RPN::execute_division(long *res)
{
	if (_lst.back() == 0)
		return -1;
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);
	*res = *second_to_last / _lst.back();
	return 0;
}

int RPN::execute_operation(long *res, char c)
{
	int div_by_zero = 0;
	if (_lst.size() <= 1)
		return -1;
	if (c == '+')
		*res = execute_addition();
	else if (c == '-')
		*res = execute_subtraction();
	else if (c == '*')
		*res = execute_multiplication();
	else if (c == '/')
		div_by_zero = execute_division(res);
	if (div_by_zero == -1)
		return -1;
	return 0;
}

void RPN::parse_char_to_long_and_add_to_list(char c)
{
	long num = static_cast<long>(c - 48);
	_lst.push_back(num);
}

static bool is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

// valid chars: "0123456789+-*/ "
void RPN::parse_string(const std::string &str)
{
	if (str.find_first_not_of("0123456789 +-*/") != str.npos)
	{
		std::cerr << "Error. invalid character detected." << std::endl;
		return;
	}

	bool fail = false;
	int i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			continue;
		if (is_operator(str[i]))
		{
			long res;
			if (execute_operation(&res, str[i]) == -1)
			{
				//std::cerr << "Error. too little numbers before operator" << std::endl;
				fail = true;
				break;
			}
			_lst.pop_back();
			_lst.pop_back();
			_lst.push_back(res);
			continue;
		}
		parse_char_to_long_and_add_to_list(str[i]);
	}
	if (_lst.size() != 1 || fail)
	{
		std::cerr << "Error." << std::endl;
		return ;
	}
	std::cout << _lst.front() << std::endl;		
}
