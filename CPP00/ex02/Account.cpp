/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:45:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/01 22:26:06 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:";
    std::cout << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
    _nbAccounts--;
    _totalAmount -= _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:";
    std::cout << _amount << ";closed" << std::endl;
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
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:";
    std::cout << _totalAmount << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        _displayTimestamp();
        std::cout << " index:" << _accountIndex << ";p_amount:";
        std::cout << _amount + withdrawal << ";withdrawal:" << withdrawal;
        std::cout << ";amount:" << _amount << ";nb_withdrawals:";
        std::cout << _nbWithdrawals << std::endl;
        return true;
    }
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:";
    std::cout << _amount << ";withdrawal:refused" << std::endl;
    return false;
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits <<";withdrawals:";
    std::cout << _nbWithdrawals << std::endl;
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
