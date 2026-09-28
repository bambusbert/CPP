/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/09/28 17:17:40 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T> void swap(T* val1, T* val2)
{
    T swp = *val1;
    *val1 = *val2;
    *val2 = swp;
}

template <typename T> T min(T val1, T val2)
{
    return val1 < val2 ? val1 : val2;
}

template <typename T> T max(T val1, T val2)
{
    return val1 > val2 ? val1 : val2;
}

int main (void)
{
    std::cout << "SWAP" << std::endl;
    int n1 = 5;
    int n2 = 10;
    std::cout << "before " << n1 << ", " << n2 << std::endl;
    swap<int>(&n1, &n2);
    std::cout << "after  " << n1 << ", " << n2 << std::endl;
    
    std::cout << "MIN" << std::endl;
    int n3 = 5;
    int res = min<int>(n1, n2);
    std::cout << "Minimum is: " << res << std::endl;
    res = min<int>(n1, n3);
    std::cout << "Minimum is: " << res << std::endl; 
}
