/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:30:59 by slambert          #+#    #+#             */
/*   Updated: 2026/06/06 10:58:09 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "contact.hpp"
#include <cctype>

class PhoneBook
{
    private:
        Contact contacts[8];
        int sssize;
    public:
        PhoneBook();
        int getSize();
        void addContact(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& num, const std::string& sec);
        void printContactTrunc(int index);
        void printContactDetail(int index);
        void printAll();
};

#endif