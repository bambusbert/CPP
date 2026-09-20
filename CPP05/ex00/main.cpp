/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:30:46 by slambert          #+#    #+#             */
/*   Updated: 2026/09/20 11:59:56 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat a;
    std::cout << a;
    a.decrementGrade();
    std::cout << a;
    Bureaucrat b("manfred", 7);
    std::cout << b;
    Bureaucrat b1 = b;
    std::cout << b1;
    a = b1;
    std::cout << a;
    std::cout << "\nnow testing exception stuff\n";
    try
    {
        Bureaucrat c("lanfred", 0);
    }
    catch(std::exception &e)
    {
        std::cout << "Nope. " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat d("rolf", 255);
    }
    catch(std::exception &e)
    {
        std::cout << "Nope. " << e.what() << std::endl;
    }
    Bureaucrat e("horst", 1);
    try
    {
        e.incrementGrade();
    }
    catch(std::exception &e)
    {
        std::cout << "Nope. " << e.what() << std::endl;
    }
    std::cout << e;
    Bureaucrat *pB = new Bureaucrat("sepp", 10);
    pB->decrementGrade();
    std::cout << pB;

    std::cout << "\nnow testing if incrementGrade also throws exception\n";
    while (true)
    {
        try
        {
            pB->incrementGrade();
            std::cout << pB;
        }
        catch(const std::exception& e)
        {
            std::cout << "Nope. " << e.what() << std::endl;
            break;
        }
    }
    delete(pB);
    //Bureaucrat asd("bert", 0);
    //without try/catch block we will get the following behaviour:
    //terminate called after throwing an instance of 'Bureaucrat::GradeTooLowException'
    //what():  Grade is too low
    //Aborted                    (core dumped) ./ex00
    
}
