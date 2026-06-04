/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:42:13 by slambert          #+#    #+#             */
/*   Updated: 2026/06/04 18:26:31 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "wrong number of arguments. Usage: ./replace <filename> <str1> <str2>" << std::endl;
        return 1;
    }
    return replace_stuff(argv[1], argv[2], argv[3]);
}