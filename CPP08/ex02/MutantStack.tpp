/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:38:03 by slambert          #+#    #+#             */
/*   Updated: 2026/10/27 14:32:05 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

#include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack(): std::stack<T, C>() {}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack &other): std::stack<T, C>(other) {}

template <typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack &other)
{
    if (this != &other)
        std::stack<T, C>::operator=(other);
    return *this;
}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack() {}

//this->c accesses the actual container
template <typename T, typename C>
typename C::iterator MutantStack<T, C>::begin()
{
    return this->c.begin();
}

template <typename T, typename C>
typename C::iterator MutantStack<T, C>::end()
{
    return this->c.end();
}

#endif
