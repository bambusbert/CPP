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

void PhoneBook::printContact(int index)
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

void PhoneBook::printAll()
{
    int count;

    count = this->getSize() > 8 ? 8: this->getSize();
    std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
    for (int i = 0; i < count; i++)
    {
        this->printContact(i);
    }
    
}

int PhoneBook::getSize()
{
    return this->sssize;
}
