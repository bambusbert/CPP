/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:45:19 by slambert          #+#    #+#             */
/*   Updated: 2026/10/01 17:09:43 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T> class Array
{
    private:
        T* _arr;
        size_t _size;
    public:
        Array();
        Array(size_t n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        size_t size() const;
        T& operator[] (size_t index);
        const T& operator[] (size_t index) const;
        
        class OutOfBoundsException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif
