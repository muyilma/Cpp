#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts=0;
int Account::_totalAmount=0;
int Account::_totalNbDeposits=0;
int Account::_totalNbWithdrawals=0;

int Account::getNbAccounts(){return Account::_nbAccounts;}
int Account::getNbDeposits(){return Account::_totalNbDeposits;}
int Account::getNbWithdrawals(){return Account::_totalNbWithdrawals;}
int Account::getTotalAmount(){return Account::_totalAmount;}
int Account::checkAmount()const{return _amount;}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() 
            << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits() 
            << ";withdrawals:" << getNbWithdrawals() 
            << std::endl;
}
Account::Account(int initial_deposit)
{
    _displayTimestamp();
    _totalAmount+=initial_deposit;
    _amount=initial_deposit;
    _accountIndex=getNbAccounts();
    _nbDeposits=0;
    _nbWithdrawals=0;
    std::cout << "index:" << _accountIndex << ";" 
              << "amount:" << checkAmount() << ";created\n" ;
    _nbAccounts++;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";p_amount:" << checkAmount() ;
    if (checkAmount()<withdrawal)
        std::cout << ";withdrawal:refused\n";
    else
    {
        _amount -= withdrawal;
        _totalAmount -=withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal 
                << ";amount:" << checkAmount()
                << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }

    return checkAmount();
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";amount:" << checkAmount() 
            << ";deposits:" << _nbDeposits 
            << ";withdrawals:" << _nbWithdrawals << std::endl;

}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex
        << ";p_amount:" << checkAmount() 
        << ";deposit:" << deposit 
        << ";amount:" << checkAmount() + deposit
        << ";nb_deposits:" << _nbDeposits << "\n";
    _totalAmount +=deposit;
    _amount +=deposit;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" 
              << "amount:" << checkAmount() << ";closed\n" ;
    _nbAccounts++;
}

void Account::_displayTimestamp()
{
    time_t t=time(NULL);
    tm *tm=localtime(&t);
    std::cout << "[" 
            << tm->tm_year + 1900 
            << std::setw(2)<< std::setfill('0')<< tm->tm_mon+1
            << std::setw(2)<< std::setfill('0')<< tm->tm_mday
            << "_"
            << std::setw(2)<< std::setfill('0')<< tm->tm_hour
            << std::setw(2)<< std::setfill('0')<< tm->tm_min
            << std::setw(2)<< std::setfill('0')<< tm->tm_sec
            << "] ";
}
