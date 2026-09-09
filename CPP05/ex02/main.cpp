/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:30:46 by slambert          #+#    #+#             */
/*   Updated: 2026/09/09 15:44:40 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sys/time.h>
#include <cstdlib>

int main(void)
{
    //Seeding randomness for robotomy form
    //ctime only gives seconds and that is not enough precision
    //so we use gettimeofday
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == -1)
    {
        std::cout << "gettimeofday failed, exiting." << std::endl;
        return 1;   
    }
    srand(static_cast<unsigned int>(tv.tv_usec));
    //more elaborate seeding methods
    //srand(static_cast<unsigned int>(tv.tv_sec ^ (tv.tv_usec << 11)));
    //srand(static_cast<unsigned int>(tv.tv_sec ^ (tv.tv_usec << 11) ^ getpid()));
    
    //TEST 0
    //this should not work, bc it's an abstract class
    //AForm a("asd", 5, 5);
    
    std::cout << "TEST1 - testing shrubbery form" << std::endl;
    Bureaucrat a("Hans", 146);
    Bureaucrat b("Bert", 137);
    ShrubberyCreationForm sf("target");
    std::cout << sf;
    a.signForm(sf);
    b.executeForm(sf);
    b.signForm(sf);
    std::cout << sf;
    a.executeForm(sf);
    b.executeForm(sf);

    std::cout << "\n\nTEST2 - testing robotomy form" << std::endl;
    RobotomyRequestForm rf("deine mama");
    Bureaucrat mama("Mama", 45);
    std::cout << rf;
    b.signForm(rf);
    mama.executeForm(rf);
    mama.signForm(rf);
    mama.executeForm(rf);
    std::cout << rf;

    std::cout << "\n\nTEST2b - testing robo chance" << std::endl;
    for (int i = 0; i < 20; i++)
        mama.executeForm(rf);

    std::cout << "\n\nTEST3 - testing presidential pardon form" << std::endl;
    PresidentialPardonForm pf ("Herbert");
    mama.signForm(pf);
    Bureaucrat superBur("rudi", 1);
    std::cout << pf;
    superBur.signForm(pf);
    std::cout << pf;
    superBur.executeForm(pf);
}
