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

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    std::cout << "TEST 0" << std::endl;
    Form valid("BLAFORM", 1, 100);
    try
    {
        Form invalid("INVFORM", 1, 151);
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\nTEST 1" << std::endl;
    Bureaucrat a("Horst", 1);
    Bureaucrat b("Horst", 100);
    std::cout << a;
    std::cout << b;
    Form f("form1", 10, 10);
    std::cout << f;
    b.signForm(f);
    std::cout << f;
    a.signForm(f);
    std::cout << f;
}
