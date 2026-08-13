/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:55 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 14:05:48 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm(), _target("anon_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
AForm("robo", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

//common practice is to seed in main
void RobotomyRequestForm::beExecuted() const
{
    static bool seeded = false;

    if (!seeded)
    {
        srand(time(NULL));
        seeded = true;
    }
    std::cout << "...DRILLING NOISES..." << std::endl;
    if (rand() % 2)
        std::cout << _target << " has successfully been robotomized" << std::endl;
    else
        std::cout << "Robotomization failed" << std::endl;
}
