/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:45:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/01 17:36:04 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account( int initial_deposit )
{
    
}

//destructor! used for cleanup
Account::~Account( void )
{
    
}

int	Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
    return _totalAmount;
}

int	Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
    
}

void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{

}

int		Account::checkAmount( void ) const
{

}

void	Account::displayStatus( void ) const
{
    
}

void	Account::_displayTimestamp( void )
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
    //this->_displayTimestamp();
}