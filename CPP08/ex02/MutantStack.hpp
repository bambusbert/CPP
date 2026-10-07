/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:55:05 by slambert          #+#    #+#             */
/*   Updated: 2026/10/07 15:04:52 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <deque>

template <typename T, typename C=std::deque<T> >
class MutantStack : public std::stack<T, C>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        typedef typename C::iterator iterator;
        iterator begin();
        iterator end();        
};

#include "MutantStack.tpp"

#endif
