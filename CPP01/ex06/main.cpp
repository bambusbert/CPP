/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:42:13 by slambert          #+#    #+#             */
/*   Updated: 2026/06/05 11:58:16 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "wrong number of arguments! try again." << std::endl;
        std::cout << "Usage: ./harlFilter level" << std::endl;
        return 1;
    }
    Harl harli;
    harli.complain(argv[1]);
}