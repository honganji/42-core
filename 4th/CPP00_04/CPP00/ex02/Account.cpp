#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

std::string formatNum(int num)
{
	std::stringstream str;
	str << std::setw(2) << std::setfill('0') << num;
	return (str.str());
}

void displayProp(std::string name, int value, bool is_end)
{
	std::cout << name;
	std::cout << ":";
	std::cout << "\033[0;34m";
	std::cout << value;
	std::cout << "\033[0m";
	if (!is_end)
		std::cout << ";";
}

void Account::_displayTimestamp(void)
{
	std::time_t current_time = time(0);
	struct std::tm *local_time;

	if (current_time == -1)
	{
		std::cerr << "Error in getting time" << std::endl;
		return;
	}
	local_time = localtime(&current_time);
	if (local_time)
	{
		std::cout << "[";
		std::cout << local_time->tm_year + 1900;
		std::cout << formatNum(local_time->tm_mon);
		std::cout << formatNum(local_time->tm_mday);
		std::cout << "_" << formatNum(local_time->tm_hour);
		std::cout << formatNum(local_time->tm_min);
		std::cout << formatNum(local_time->tm_sec) << "] ";
	}
}
int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	displayProp("accounts", getNbAccounts(), false);
	displayProp("total", getTotalAmount(), false);
	displayProp("deposits", getNbDeposits(), false);
	displayProp("withdrawals", getNbWithdrawals(), true);
	std::cout << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	displayProp("index", _accountIndex, false);
	displayProp("amount", _amount, false);
	std::cout << "created";
	std::cout << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	displayProp("index", _accountIndex, false);
	displayProp("amount", _amount, false);
	std::cout << "closed";
	std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	displayProp("index", _accountIndex, false);
	displayProp("p_amount", _amount, false);
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	displayProp("deposit", deposit, false);
	displayProp("amount", _amount, false);
	displayProp("nb_deposits", _nbDeposits, true);
	std::cout << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	displayProp("index", _accountIndex, false);
	displayProp("p_amount", _amount, false);
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused";
		std::cout << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	displayProp("withdrawal", withdrawal, false);
	displayProp("amount", _amount, false);
	displayProp("nb_withdrawals", _nbWithdrawals, true);
	std::cout << std::endl;
	return (true);
}
int Account::checkAmount(void) const
{
	return (_amount);
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	displayProp("index", _accountIndex, false);
	displayProp("amount", _amount, false);
	displayProp("deposits", _nbDeposits, false);
	displayProp("withdrawals", _nbWithdrawals, true);
	std::cout << std::endl;
}
