/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:45:38 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 12:15:05 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//uintptr_t: any valid pointer to void can be converted to that type
//if that is then converted back into a void* the result is the same

#include "Serializer.hpp"

Serializer::Serializer()
{
    
}

Serializer::Serializer(const Serializer& other)
{
    (void)other;    
}

Serializer& Serializer::operator=(const Serializer& other)
{
    if (this != &other)
    {

    }
    return *this;
}

Serializer::~Serializer()
{
    
}

//Data* -> void* -> uintptr_t
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

//uintptr -> void* -> Data*
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
