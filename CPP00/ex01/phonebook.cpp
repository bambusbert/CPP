#include "phonebook.hpp"

PhoneBook::PhoneBook() {}

void PhoneBook::addContact(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& num, const std::string& sec)
{
    contacts[size % 8].setFirstName(fn);
    contacts[size % 8].setLastName(ln);
    contacts[size % 8].setNickName(nn);
    contacts[size % 8].setNumber(num);
    contacts[size % 8].setSecret(sec);
    size++;
}