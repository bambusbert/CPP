/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:13:04 by slambert          #+#    #+#             */
/*   Updated: 2026/10/28 15:03:43 by slambert         ###   ########.fr       */
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

//TODO overflow protection
long RPN::execute_multiplication()
{
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);
	return *second_to_last * _lst.back();
}

int RPN::execute_division(long *res)
{
	if (_lst.back() == 0)
		return FAIL;
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);
	*res = *second_to_last / _lst.back();
	return SUCCESS;
}

int RPN::execute_operation(long *res, char c)
{
	int div_by_zero = 0;
	if (_lst.size() <= 1)
		return (std::cerr << "Error. there need to be 2 numbers before an operator" << std::endl, FAIL);
	if (c == '+')
		*res = execute_addition();
	else if (c == '-')
		*res = execute_subtraction();
	else if (c == '*')
		*res = execute_multiplication();
	else if (c == '/')
		div_by_zero = execute_division(res);
	if (div_by_zero == FAIL)
		return (std::cerr << "Error. Division by zero" << std::endl, FAIL);
	return 0;
}
