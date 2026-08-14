/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:54 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 14:05:42 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Intern::~Intern()
{
}

static AForm *makeShrub(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *makePres(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

static AForm *makeRobo(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

// shrub, pres, robo
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm",
							"PresidentialPardonForm"};
	AForm *(*functionPointers[3])(const std::string &) = {&makeShrub, &makeRobo, &makePres};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return functionPointers[i](target);
		}
	}
	std::cout << "Intern could not create " << formName << std::endl;
	return NULL;
}
