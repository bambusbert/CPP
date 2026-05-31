#include "contact.hpp"

Contact::Contact() {}

const std::string &Contact::getFirstName() const
{
    return first_name;
}

const std::string &Contact::getLastName() const
{
    return last_name;
}

const std::string &Contact::getNickName() const
{
    return nick_name;
}

const std::string &Contact::getNumber() const
{
    return number;
}

const std::string &Contact::getSecret() const
{
    return secret;
}

void Contact::setFirstName(const std::string &name)
{
    first_name = name;
}

void Contact::setLastName(const std::string &name)
{
    last_name = name;
}

void Contact::setNickName(const std::string &name)
{
    nick_name = name;
}

void Contact::setNumber(const std::string &num)
{
    number = num;
}

void Contact::setSecret(const std::string &sec)
{
    secret = sec;
}
