/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:21:41 by slambert          #+#    #+#             */
/*   Updated: 2026/06/01 15:23:28 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

std::string Contact::getTruncFirstName() const
{
    if (first_name.length() <= 10)
        return first_name;
    return first_name.substr(0, 9) + ".";
}

std::string Contact::getTruncLastName() const
{
    if (last_name.length() <= 10)
        return last_name;
    return last_name.substr(0, 9) + ".";
}

std::string Contact::getTruncNickName() const
{
    if (nick_name.length() <= 10)
        return nick_name;
    return nick_name.substr(0, 9) + ".";
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
