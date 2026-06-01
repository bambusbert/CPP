/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:30:57 by slambert          #+#    #+#             */
/*   Updated: 2026/06/01 16:18:09 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

void add_contact(PhoneBook &book);
void search_contact (PhoneBook &book);

int main (void)
{
    PhoneBook book;
    std::string input;

    std::cout << "Hello to the super fancy phonebook!" << std::endl;
    while (true)
    {
        std::cout << "What do you wanna do? you can ADD, SEARCH or EXIT." << std::endl;
        std::getline(std::cin, input); //TODO protection
        if (input == "ADD")
            add_contact(book);
        if (input == "SEARCH")
            search_contact(book);
        if (input == "EXIT")
            return 0;
    }
    return 0;
}

//TODO should i additionally check if the index is a valid one?
//e.g. only 3 contact stored and index is 6
void search_contact (PhoneBook& book)
{
    std::string id;
    
    book.printAll();
    std::cout << "gimme index" << std::endl;
    std::getline (std::cin, id);
    if (id.length() == 1 && id[0] >= '0' && id[0] <= '7')
        book.printContact(id[0] - '0');
    else
        std::cout << "invalid index! has to be between 0 and 7" << std::endl;
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

void add_contact(PhoneBook& book)
{
    std::string fn;
    std::string ln;
    std::string nn;
    std::string num;
    std::string sec;
    
    std::cout << "Enter first name." << std::endl;
    std::getline(std::cin, fn);
    if (is_empty(fn))
        return;        
    std::cout << "Enter last name." << std::endl;
    std::getline(std::cin, ln);
    if (is_empty(ln))
        return;   
    std::cout << "Enter nickname." << std::endl;
    std::getline(std::cin, nn);
    if (is_empty(nn))
        return;   
    std::cout << "Enter phone number." << std::endl;
    std::getline(std::cin, num);
    if (is_empty(num))
        return;   
    std::cout << "Enter darkest secret." << std::endl;
    std::getline(std::cin, sec);
    if (is_empty(sec))
        return;   
    book.addContact(fn, ln, nn, num, sec);
}
