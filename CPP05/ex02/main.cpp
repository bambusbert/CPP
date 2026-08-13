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

int main(void)
{
    // this should not work, bc it's an abstract class
    // AForm a("asd", 5, 5);
    Bureaucrat b("Bert", 137);
    ShrubberyCreationForm sf("target");
    std::cout << sf;
    b.executeForm(sf);
    b.signForm(sf);
    std::cout << sf;
    b.executeForm(sf);

   // b.signForm(sf);
}
