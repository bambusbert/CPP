/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:30:57 by slambert          #+#    #+#             */
/*   Updated: 2026/06/01 13:52:00 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

void say_hello();
void add_contact(PhoneBook &book);
void search_contact (PhoneBook &book);

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
        if (input == "SEARCH")
            search_contact(book);
    }
}

void say_hello()
{
    std::cout << "Hello to the super fancy phonebook" << std::endl;
    std::cout << "What do you wanna do? you can ADD, SEARCH or EXIT." << std::endl;
}

void search_contact (PhoneBook& book)
{
    book.printAll();
}

void add_contact(PhoneBook& book)
{
    std::string fn;
    std::string ln;
    std::string nn;
    std::string num;
    std::string sec;
    
    //std::cout << "we are in add_contact" << std::endl;
    std::cout << "firstname" << std::endl;
    std::cin >> fn;
    std::cout << "lastname" << std::endl;
    std::cin >> ln;
    std::cout << "nickname" << std::endl;
    std::cin >> nn;
    std::cout << "number" << std::endl;
    std::cin >> num;
    std::cout << "secret" << std::endl;
    std::cin >> sec;
    book.addContact(fn, ln, nn, num, sec);
}

