/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Stefan Lambert <slambert@student.42vien    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:11:48 by bert              #+#    #+#             */
/*   Updated: 2026/05/29 16:14:43 by Stefan Lamb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
    int i = 0;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
            std::cout << static_cast<char>(std::toupper(static_cast<int>(argv[i][j])));
    }
    std::cout << std::endl;
    return 0;
}
