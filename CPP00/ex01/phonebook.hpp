/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:30:59 by slambert          #+#    #+#             */
/*   Updated: 2026/05/31 12:36:03 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int size;
    public:
        PhoneBook();
        void addContact(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& num, const std::string& sec);
        void printContact(int index);
        void printAll();
};

#endif