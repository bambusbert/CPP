/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:48:57 by slambert          #+#    #+#             */
/*   Updated: 2026/10/05 14:20:09 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _arr(new T[0]), _size(0)
{
}

template <typename T>
Array<T>::Array(size_t n): _size(n)
{
    _arr = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other)
{
    _arr = new T[other._size];
    _size = other._size;
    for (size_t i = 0; i < other._size; i++)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        T* tmp = new T[other._size];
        for (size_t i = 0; i < other._size; i++)
            tmp[i] = other._arr[i];
        delete[] _arr;
        _arr = tmp;
        _size = other._size;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

template <typename T>
size_t Array<T>::size() const
{
    return _size;
}

template <typename T>
T& Array<T>::operator[] (size_t index)
{
    if (index >= _size)
        throw Array<T>::OutOfBoundsException();
    return _arr[index];
}

template <typename T>
const T& Array<T>::operator[] (size_t index) const
{
    if (index >= _size)
        throw Array<T>::OutOfBoundsException();
    return _arr[index];
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
    return "The index is out of bounds.";
}


#endif
