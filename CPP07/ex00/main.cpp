/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/09/29 11:34:03 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main (void)
{
    std::cout << "SWAP" << std::endl;
    int n1 = 5;
    int n2 = 10;
    std::cout << "before " << n1 << ", " << n2 << std::endl;
    // swap<int>(n1, n2);
    ::swap(n1, n2);
    std::cout << "after  " << n1 << ", " << n2 << std::endl;
    
    std::cout << "MIN" << std::endl;
    int n3 = 5;
    // int res = min<int>(n1, n2);
    int res = ::min(n1, n2);
    std::cout << "Minimum is: " << res << std::endl;
    // res = min<int>(n1, n3);
    res = ::min(n1, n3);
    std::cout << "Minimum is: " << res << std::endl;

    std::cout << "\ntest from subject" << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}
