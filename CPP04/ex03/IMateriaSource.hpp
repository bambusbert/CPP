/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:56:18 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 14:26:18 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
  public:
	virtual ~IMateriaSource(){}
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
