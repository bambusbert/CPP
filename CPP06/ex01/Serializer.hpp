/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:45:48 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 12:19:14 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
    int x;
    int y;
};

class Serializer
{
    public:
        Serializer();
        Serializer (const Serializer& other);
        Serializer& operator=(const Serializer& other);
        virtual ~Serializer() = 0;
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);  
};

#endif
