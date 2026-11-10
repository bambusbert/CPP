/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:13:04 by slambert          #+#    #+#             */
/*   Updated: 2026/11/10 11:52:53 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::execute_addition(long *res, std::list<long>::iterator &second_to_last)
{
	long a = *second_to_last;
	long b = _lst.back();
	if ((b > 0 && a > std::numeric_limits<long>::max() - b) ||
		(b < 0 && a < std::numeric_limits<long>::min() - b))
		return FAIL;
	*res = a + b;
	return SUCCESS;
}

int RPN::execute_subtraction(long *res, std::list<long>::iterator &second_to_last)
{
	long a = *second_to_last;
	long b = _lst.back();
	if ((b > 0 && a < std::numeric_limits<long>::min() + b) ||
		(b < 0 && a > std::numeric_limits<long>::max() + b))
		return FAIL;
	*res = a - b;
	return SUCCESS;
}

int RPN::execute_multiplication(long *res, std::list<long>::iterator &second_to_last)
{
	long a = *second_to_last;
	long b = _lst.back();
	if ((a > 0 && b > 0 && a > std::numeric_limits<long>::max() / b) ||
		(a > 0 && b < 0 && b < std::numeric_limits<long>::min() / a) ||
		(a < 0 && b > 0 && a < std::numeric_limits<long>::min() / b) ||
		(a < 0 && b < 0 && a < std::numeric_limits<long>::max() / b))
		return FAIL;
	*res = a * b;
	return SUCCESS;
}

int RPN::execute_division(long *res, std::list<long>::iterator &second_to_last)
{
	long b = _lst.back();
	if (b == 0)
		return FAIL;
	long a = *second_to_last;
	if (a == std::numeric_limits<long>::min() && b == -1)
		return FAIL;
	*res = a / b;
	return SUCCESS;
}

int RPN::execute_operation(long *res, char c)
{
	if (_lst.size() <= 1)
		return (std::cerr << "Error. there need to be 2 numbers before an operator" << std::endl,
				FAIL);
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);
	if (c == '+' && execute_addition(res, second_to_last) == FAIL)
		return (std::cerr << "Error. Addition Overflow" << std::endl, FAIL);
	else if (c == '-' && execute_subtraction(res, second_to_last) == FAIL)
		return (std::cerr << "Error. Subtraction Overflow" << std::endl, FAIL);
	else if (c == '*' && execute_multiplication(res, second_to_last) == FAIL)
		return (std::cerr << "Error. Multiplication Overflow" << std::endl, FAIL);
	else if (c == '/' && execute_division(res, second_to_last) == FAIL)
		return (std::cerr << "Error. Division overflow or division by zero" << std::endl, FAIL);
	return SUCCESS;
}
