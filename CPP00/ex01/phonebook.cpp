/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:23:51 by slambert          #+#    #+#             */
/*   Updated: 2026/06/02 12:44:35 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
    sssize = 0;
}

void PhoneBook::addContact(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& num, const std::string& sec)
{
    
    contacts[sssize % 8].setFirstName(fn);
    contacts[sssize % 8].setLastName(ln);
    contacts[sssize % 8].setNickName(nn);
    contacts[sssize % 8].setNumber(num);
    contacts[sssize % 8].setSecret(sec);
    sssize++;
}

void PhoneBook::printContactTrunc(int index)
{
    std::cout << std::setw(10) << index;
    std::cout << "|";
    std::cout << std::setw(10) << this->contacts[index].getTruncFirstName();
    std::cout << "|";
    std::cout << std::setw(10) << this->contacts[index].getTruncLastName();
    std::cout << "|";
    std::cout << std::setw(10) << this->contacts[index].getTruncNickName();
    std::cout << "|";
    std::cout << std::endl;
}

void PhoneBook::printContactDetail(int index)
{
    std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickName() << std::endl;
    std::cout << "Phone number: " << this->contacts[index].getNumber() << std::endl;
    std::cout << "Darkest secret: " << this->contacts[index].getSecret() << std::endl;

}

void PhoneBook::printAll()
{
    int count;

    count = this->getSize() > 8 ? 8: this->getSize();
    std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
    for (int i = 0; i < count; i++)
    {
        this->printContactTrunc(i);
    }
    
}

int PhoneBook::getSize()
{
    return this->sssize;
}
