/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:30:57 by slambert          #+#    #+#             */
/*   Updated: 2026/05/31 12:41:53 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

void say_hello();
void add_contact(PhoneBook book);

int main (void)
{
    PhoneBook book;
    std::string input;

    say_hello();
    while (true)
    {
        std::cin >> input;
        if (input == "ADD")
            add_contact(book);
    }
}

void say_hello()
{
    std::cout << "Hello to the super fancy phonebook" << std::endl;
    std::cout << "What do you wanna do? you can ADD, SEARCH or EXIT." << std::endl;
}

void add_contact(PhoneBook book)
{
    (void) book;
    std::cout << "we are in add_contact";
}