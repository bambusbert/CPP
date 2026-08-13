/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:30:46 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 15:19:32 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "TEST1" << std::endl;
    Intern i;
    AForm *a = i.makeForm("RobotomyRequestForm", "beidl");
    AForm *b = i.makeForm("RobotfomyRequestForm", "beidl");
    (void) a;
    (void) b;
    b = i.makeForm("PresidentialPardonForm", "Jeffrey");
    std::cout << "\n\nTEST2" << std::endl;
    Bureaucrat bu ("Rüdiger", 1);
    bu.signForm(*b);
    bu.executeForm(*b);

    delete(a);
    delete(b);
}
