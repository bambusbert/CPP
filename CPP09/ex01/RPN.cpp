/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:05:43 by slambert          #+#    #+#             */
/*   Updated: 2026/10/28 15:01:33 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//TODO check if parse string on default constructed element does nothing stupid
RPN::RPN() { }

RPN::~RPN() { }

RPN::RPN(const std::string &str): _str(str) { }

RPN::RPN(const RPN &other): _lst (other._lst), _str(other._str) { }

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_lst.clear();
		_lst = other._lst;
		_str = other._str;
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

void RPN::insert_result (long &res)
{
	_lst.pop_back();
	_lst.pop_back();
	_lst.push_back(res);
}

void RPN::parse_string()
{
    if (_str.find_first_not_of("0123456789 +-*/") != _str.npos)
		return (void)(std::cerr << "Error. invalid character detected." << std::endl);
	_lst.clear();
	bool fail = false;
	int i = -1;
	while (_str[++i])
	{
		if (_str[i] == ' ')
			continue;
		if (is_operator(_str[i]))
		{
			long res;
			if (execute_operation(&res, _str[i]) == FAIL)
				{ fail = true; break; }
			insert_result(res);
			continue;
		}
		parse_char_to_long_and_add_to_list(_str[i]);
	}
	if (fail)
		return;
	if (_lst.empty())
		return (void)(std::cerr << "Error. empty input" << std::endl);
	else if (_lst.size() > 1)
		return (void)(std::cerr << "Error. notation does not solve to one value" << std::endl);
	std::cout << _lst.front() << std::endl;
}
