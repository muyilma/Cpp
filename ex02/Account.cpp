#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts=0;
int Account::_totalAmount=0;
int Account::_totalNbDeposits=0;
int Account::_totalNbWithdrawals=0;

void Account::displayAccountsInfos()
{
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount  << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
Account::Account(int initial_deposit)
{
    _totalAmount+=initial_deposit;
    _amount=initial_deposit;
    _accountIndex=_nbAccounts;
    _nbDeposits=0;
    _nbWithdrawals=0;
    std::cout << "index:" << _accountIndex << ";" 
              << "amount:" << _amount << ";created\n" ;//amount hesabındaki parayı gösteriyor
    _nbAccounts++;
}

bool Account::makeWithdrawal(int withdrawal)
{

    std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount ;
    if (_amount<withdrawal)
        std::cout << ";withdrawal:refused\n";
    else
    {
        _amount -= withdrawal;
        _totalAmount -=withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal 
                << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }

    return _amount;
}

void Account::displayStatus() const
{
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount 
            << ";deposits:" << _nbDeposits 
            << ";withdrawals:" << _nbWithdrawals << std::endl;

}

void Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount 
        << ";deposit:" << deposit 
        << ";amount:" << _amount + deposit
        << ";nb_deposits:" << _nbDeposits << "\n";
    _totalAmount +=deposit;
    _amount +=deposit;
}

Account::~Account()
{
    std::cout << "index:" << _accountIndex << ";" 
              << "amount:" << _amount << ";closed\n" ;//amount hesabındaki parayı gösteriyor
    _nbAccounts++;
}
