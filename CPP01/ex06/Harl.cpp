/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:35:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/11 10:52:22 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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

//this solution gave me a compilter error on my personal machine
//(-Werror flag complains because of implicit fallthrough)
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
    int i;
    for (i = 0; i < size ; i++)
    {
        if (levels[i] == level)
            break;
    }
    switch (i)
    {
        case 0:
            std::cout << "[ " << levels[0] << " ]" << std::endl;
            this->debug();
            std::cout << std::endl;
            //fallthrough
        case 1:
            std::cout << "[ " << levels[1] << " ]" << std::endl;
            this->info();
            std::cout << std::endl;
            //fallthrough
        case 2:
            std::cout << "[ " << levels[2] << " ]" << std::endl;
            this->warning();
            std::cout << std::endl;
            //fallthrough
        case 3:
            std::cout << "[ " << levels[3] << " ]" << std::endl;
            this->error();
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

// void	Harl::complain(std::string level)
// {
// 	std::string levels[] = 
//     {
//         "DEBUG",
//         "INFO",
//         "WARNING",
//         "ERROR"
//     };
//     void (Harl::*functions[]) (void) =
//     {
//         &Harl::debug,
//         &Harl::info,
//         &Harl::warning,
//         &Harl::error
//     };
//     int size = static_cast<int>(sizeof(functions) / sizeof (functions[0]));
//     int i;
//     for (i = 0; i < size ; i++)
//     {
//         if (levels[i] == level)
//             break;
//     }
//     int start = -1;
//     switch (i)
//     {
//         case 0:
//             start = 0;
//             break;
//         case 1:
//             start = 1;
//             break;
//         case 2:
//             start = 2;
//             break;
//         case 3:
//             start = 3;
//             break;
//         default:
//             std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
//             return ;
//     }
//     for (int j = start; j < size; j++)
//     {
//         std::cout << "[ " << levels[j] << " ]" << std::endl;   
//         (this->*functions[j])();
//         std::cout << std::endl;
//     }
// }
//1st solution (no switch case)
// void	Harl::complain(std::string level)
// {
// 	std::string levels[] = 
//     {
//         "DEBUG",
//         "INFO",
//         "WARNING",
//         "ERROR"
//     };
//     void (Harl::*functions[]) (void) =
//     {
//         &Harl::debug,
//         &Harl::info,
//         &Harl::warning,
//         &Harl::error
//     };
//     int size = static_cast<int>(sizeof(functions) / sizeof (functions[0]));
//     for (int i = 0; i < size ; i++)
//     {
//         if (levels[i] == level)
//         {
//             for (int j = i; j < size; j++)
//             {
//                 std::cout << "[ " << levels[j] << " ]" << std::endl;   
//                 (this->*functions[j])();
//                 std::cout << std::endl;
//             }
//             return;
//         }
//     }
//     std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
// }