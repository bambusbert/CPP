/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:30:57 by slambert          #+#    #+#             */
/*   Updated: 2026/06/01 16:33:23 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

void say_bye();
int add_contact(PhoneBook &book);
int search_contact (PhoneBook &book);

int main (void)
{
    PhoneBook book;
    std::string input;

    std::cout << "Hello to the super fancy phonebook!" << std::endl;
    while (true)
    {
        std::cout << "What do you wanna do? you can ADD, SEARCH or EXIT." << std::endl;
        if (!std::getline(std::cin, input))
        {
            say_bye();
            return 0;
        }
        if (input == "ADD" && !add_contact(book))
        {
            say_bye();
            return 0;
        }  
        if (input == "SEARCH" && !search_contact(book))
        {
            say_bye();
            return 0;
        }
        if (input == "EXIT")
        {
            say_bye();
            return 0;
        }
    }
    return 0;
}

void say_bye()
{
    std::cout << "\nExiting phonebook..." << std::endl;
}

//TODO should i additionally check if the index is a valid one?
//e.g. only 3 contact stored and index is 6
int search_contact (PhoneBook& book)
{
    std::string id;
    
    book.printAll();
    std::cout << "gimme index" << std::endl;
    if (!std::getline (std::cin, id))
        return 0;
    if (id.length() == 1 && id[0] >= '0' && id[0] <= '7')
        book.printContact(id[0] - '0');
    else
        std::cout << "invalid index! has to be between 0 and 7" << std::endl;
    return 1;
}

int is_empty(std::string str)
{
    if (str.empty())
    {
        std::cout << "empty input detected! as a punishment you have to start again." << std::endl;
        return 1;
    }
    return 0;
}

int add_contact(PhoneBook& book)
{
    std::string fn;
    std::string ln;
    std::string nn;
    std::string num;
    std::string sec;
    
    std::cout << "Enter first name." << std::endl;
    if (!std::getline(std::cin, fn))
        return 0;
    if (is_empty(fn))
        return 1;        
    std::cout << "Enter last name." << std::endl;
    if (!std::getline(std::cin, ln))
        return 0;
    if (is_empty(ln))
        return 1;   
    std::cout << "Enter nickname." << std::endl;
    if (!std::getline(std::cin, nn))
        return 0;
    if (is_empty(nn))
        return 1;   
    std::cout << "Enter phone number." << std::endl;
    if (!std::getline(std::cin, num))
        return 0;
    if (is_empty(num))
        return 1;   
    std::cout << "Enter darkest secret." << std::endl;
    if (!std::getline(std::cin, sec))
        return 0;
    if (is_empty(sec))
        return 1;
    book.addContact(fn, ln, nn, num, sec);
    return 1;
}
