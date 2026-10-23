/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:13:04 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 17:45:57 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
		return (std::cerr << "Error. there need to be 2 numbers before an operator" << std::endl, -1);
	if (c == '+')
		*res = execute_addition();
	else if (c == '-')
		*res = execute_subtraction();
	else if (c == '*')
		*res = execute_multiplication();
	else if (c == '/')
		div_by_zero = execute_division(res);
	if (div_by_zero == -1)
		return (std::cerr << "Error. Division by zero" << std::endl, -1);
	return 0;
}
