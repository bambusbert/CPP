/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:30:46 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 14:09:15 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    //seed randomness
    srand(std::time(NULL));
    Base base;  //TODO ev static anstatt member function (aber dann kann 
    //identify nicht virtual sein - schlecht)
    Base* ptrs[10];
    for (int i = 0; i < 10; i++)
    {
        ptrs[i] = base.generate();
        std::cout << "Pointer " << i << ":" << std::endl;
        base.identify(ptrs[i]);
        base.identify(*(ptrs[i]));
        std::cout << std::endl;
    }
}
