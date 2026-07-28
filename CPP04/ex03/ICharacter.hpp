/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:58:10 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 16:52:37 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
class AMateria;

class ICharacter
{
	public:
    	virtual ~ICharacter(){}
      	virtual std::string const &getName() const = 0;
	    virtual void equip(AMateria *m) = 0;
	    virtual void unequip(int idx) = 0;
	    virtual void use(int idx, ICharacter &target) = 0;
};

#endif
