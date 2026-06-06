/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:36:02 by slambert          #+#    #+#             */
/*   Updated: 2026/06/06 11:07:13 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
    private:
	    void debug(void);
	    void info(void);
	    void warning(void);
	    void error(void);
        
    public:
	    void complain(std::string level);
};

#endif