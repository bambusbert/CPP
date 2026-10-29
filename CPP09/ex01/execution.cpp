/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:13:04 by slambert          #+#    #+#             */
/*   Updated: 2026/10/29 12:02:49 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::execute_addition(long *res)
{
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);

	long a = *second_to_last;
	long b = _lst.back();
	if ((b > 0 && a > LONG_MAX - b) || 
		(b < 0 && a < LONG_MIN - b))
		return FAIL;
	*res = a + b;
	return SUCCESS;
}

int RPN::execute_subtraction(long *res)
{
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);

	long a = *second_to_last;
	long b = _lst.back();
	if ((b > 0 && a < LONG_MIN + b) ||
		(b < 0 && a > LONG_MAX + b))
		return FAIL;
	*res = a - b;
	return SUCCESS;
}

int RPN::execute_multiplication(long *res)
{
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);
	
	long a = *second_to_last;
	long b = _lst.back();
	if((a > 0 && b > 0 && a > LONG_MAX / b) ||
		(a > 0 && b < 0 && b < LONG_MIN / a) ||
		(a < 0 && b > 0 && a < LONG_MIN / b) ||
		(a < 0 && b < 0 && a < LONG_MAX / b))
		return FAIL;
	*res = a * b;
	return SUCCESS;
}

int RPN::execute_division(long *res)
{
	long b = _lst.back();	
	if (b == 0)
		return FAIL;
	std::list<long>::iterator second_to_last = _lst.end();
	std::advance(second_to_last, -2);
	long a = *second_to_last;
	if (a == LONG_MIN && b == -1)
		return FAIL;
	*res = a / b;
	return SUCCESS;
}

int RPN::execute_operation(long *res, char c)
{
	if (_lst.size() <= 1)
		return (std::cerr << "Error. there need to be 2 numbers before an operator" << std::endl,
				FAIL);
	if (c == '+' && execute_addition(res) == FAIL)
		return (std::cerr << "Error. Addition Overflow" << std::endl, FAIL);
	else if (c == '-' && execute_subtraction(res) == FAIL)
		return (std::cerr << "Error. Subtraction Overflow" << std::endl, FAIL);
	else if (c == '*' && execute_multiplication(res) == FAIL)
		return (std::cerr << "Error. Multiplication Overflow" << std::endl, FAIL);
	else if (c == '/' && execute_division(res) == FAIL)
		return (std::cerr << "Error. Division overflow or division by zero" << std::endl, FAIL);
	return SUCCESS;
}
