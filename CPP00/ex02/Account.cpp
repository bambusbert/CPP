/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:45:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/01 17:16:42 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account( int initial_deposit )
{
    
}

Account::~Account( void )
{
    
}

static int	getNbAccounts(void)
{
    
}

static int	getTotalAmount(void)
{
    
}

static int	getNbDeposits(void)
{
    
}

static int	getNbWithdrawals(void)
{
    
}

static void	displayAccountsInfos(void)
{
    
}

static void	_displayTimestamp( void )
{
    std::time_t time;
    std::tm *t_struct;
    char buf[20];

    time = std::time(NULL);
    t_struct = std::localtime(&time);
    std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", t_struct);
    std::cout << buf;
}

int main (void)
{
    _displayTimestamp();
}