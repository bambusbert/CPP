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
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    // this should not work, bc it's an abstract class
    // AForm a("asd", 5, 5);
    std::cout << "TEST1" << std::endl;
    Bureaucrat b("Bert", 137);
    ShrubberyCreationForm sf("target");
    std::cout << sf;
    b.executeForm(sf);
    b.signForm(sf);
    std::cout << sf;
    b.executeForm(sf);

    std::cout << "\n\nTEST2" << std::endl;
    RobotomyRequestForm rf("deine mama");
    Bureaucrat mama("Mama", 45);
    std::cout << rf;
    mama.executeForm(rf);
    mama.signForm(rf);
    mama.executeForm(rf);
    std::cout << rf;

    std::cout << "\n\nTEST3" << std::endl;
    PresidentialPardonForm pf ("Herbert");
    mama.signForm(pf);
    Bureaucrat superBur("rudi", 1);
    superBur.signForm(pf);
    std::cout << pf;
    superBur.executeForm(pf);
   // b.signForm(sf);
}
