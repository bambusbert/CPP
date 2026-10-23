/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:05:43 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 17:13:24 by slambert         ###   ########.fr       */
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
	if (fail)
		return;
	if (_lst.size() == 0)
	{
		std::cerr << "Error. empty input" << std::endl;
		return ;
	}
	else if (_lst.size() > 1)
	{
		std::cerr << "Error. notation does not solve to one value" << std::endl;
		return ;
	}
	std::cout << _lst.front() << std::endl;		
}
