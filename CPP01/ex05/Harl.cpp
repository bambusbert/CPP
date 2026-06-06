/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:35:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/06 10:11:03 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << "I am Harl and I am midly discomforted." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I am Harl and I am a very discomforted." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I am Harl and I HATE MY LIFE" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "AKLBFIUGEUIOZZDGSAHKLVBiEUJK FBJKEVIL" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[] = 
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    void (Harl::*functions[]) (void) =
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    int size = static_cast<int>(sizeof(functions) / sizeof (functions[0]));
    for (int i = 0; i < size ; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "Error: you passed a wrong argument to complain(). call with DEBUG, INFO, WARNING or ERROR." << std::endl;
}
