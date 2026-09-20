/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:30:46 by slambert          #+#    #+#             */
/*   Updated: 2026/09/20 12:19:46 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "TEST1" << std::endl;
    Intern i;
    AForm *a = i.makeForm("robotomy request", "abc");
    AForm *b = i.makeForm("NonExistingForm", "def");
    AForm *c = i.makeForm("presidential request", "Jeffrey");
    
    std::cout << "\n\nTEST2" << std::endl;
    Bureaucrat b1 ("Rüdiger", 150);
    Bureaucrat b2 ("asdf", 1);
    b1.signForm(*c);
    b1.executeForm(*c);
    b2.signForm(*c);
    b2.executeForm(*c);
    if (a)
        delete(a);
    if (b)
        delete(b);
    if (c)
        delete(c);
}
