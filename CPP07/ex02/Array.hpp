/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:45:19 by slambert          #+#    #+#             */
/*   Updated: 2026/09/29 17:51:06 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>


template <typename T> class Array
{
    private:
        T* _arr;
        size_t _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        T* getArray() const;
        size_t getSize() const;
        T& operator[] (const size_t index) const;

        //OutOfBounds Exception
};

#include "Array.tpp"

#endif
