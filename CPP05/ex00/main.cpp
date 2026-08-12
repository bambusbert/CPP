/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:30:46 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 14:08:55 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat a;
    Bureaucrat b("manfred", 7);
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
        std::cerr << e.what() << std::endl;
    }
    std::cout << e.getGrade() << std::endl;
    std::cout << e;
    Bureaucrat *pB = new Bureaucrat("sepp", 10);
    pB->decrementGrade();
    std::cout << pB;
    delete(pB);
    
    
}
