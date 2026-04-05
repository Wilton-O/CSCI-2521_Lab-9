#include "Account.h"
#include <iostream>
#include <numeric> // for accumulate
using namespace std;

/// <summary>
/// Default constructor
/// </summary>
Account::Account() 
{
    accountNumber = "0000000000";
    balance = 0.0;
    owner = Customer();
}

/// <summary>
/// Parameterized constructor
/// </summary>
/// <param name="accNum">The account number</param>
/// <param name="initBal">The initial balance</param>
/// <param name="cust">The customer object associated to this account</param>
Account::Account(const string& accNum, double initBal, const Customer& cust)
    : accountNumber(accNum), balance(initBal), owner(cust) 
{
}

/// <summary>
/// This function adds a deposit transaction to the account. The deposit is not permanent
/// until the closeOfBusiness function is called.
/// </summary>
/// <param name="amount">The dollar amount of the deposit</param>
/// <returns>
/// The amount value should be greater than 0. If not, it will be ignored
/// and false will be returned. If the amount is valid, then the deposit is added
/// to the account and true is returned.
/// </returns>
bool Account::deposit(double amount) 
{
    if (amount > 0) {
        deposits.push_back(amount);
        return true;
    }

    return false;
}

/// <summary>
/// This function adds a withdrawal transaction to the account. The withdrawal is not
/// permanent until the closeOfBusiness function is called.
/// </summary>
/// <param name="amount">The dollar amount of the withdrawal.</param>
/// <returns>
/// The amount value should be greater than 0. If not, it will be ignored
/// and false will be returned. If the amount is valid, then the withdrawal is added
/// to the account and true is returned.
/// </returns>
bool Account::withdraw(double amount) 
{
    if (amount > 0) {
        withdrawals.push_back(amount);
        return true;
    }

    return false;
}

/// <summary>
/// This function will iterate deposits and withdrawals and update the balance
/// available in the account.
/// </summary>
void Account::closeOfBusiness() 
{
    double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
    double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    double previousBalance = balance;
    double newBalance = previousBalance + totalDeposits - totalWithdrawals;

    printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();
}

/// <summary>
/// Prints a summary of what occurred in this account today. Should only be called from
/// the closeOfBusiness function.
/// </summary>
/// <param name="previousBalance">The balance before close of day balancing.</param>
/// <param name="totalDeposits">The total dollar amount of deposits added to the account.</param>
/// <param name="totalWithdrawals">The total dollar amount of withdrawals added to the account.</param>
/// <param name="newBalance">The balance after close of day balancing.</param>
void Account::printSummary(double previousBalance, double totalDeposits, double totalWithdrawals, double newBalance) const 
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Previous Balance: $" << previousBalance << endl;
    cout << "Total Deposits: $" << totalDeposits << endl;
    cout << "Total Withdrawals: $" << totalWithdrawals << endl;
    cout << "New Balance after COB: $" << newBalance << endl;
}

/// <summary>
/// Getter/Accessor to retrieve the current balance on the account calculated
/// by the previous closeOfBusiness call.
/// </summary>
/// <returns></returns>
double Account::getBalance() const 
{
    return balance;
}

/// <summary>
/// Getter/Accessor to retrieve this Account's accountNumber
/// </summary>
/// <returns></returns>
string Account::getAccountNumber() const 
{
    return accountNumber;
}

/// <summary>
/// Getter/Accessor to retrieve the associated Customer object
/// </summary>
/// <returns></returns>
Customer Account::getCustomer() const 
{
    return owner;
}

/// <summary>
/// Prints a quick informational summary about the Account
/// </summary>
void Account::printAccountInfo() const 
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    owner.printCustomerInfo();
}

/// <summary>
/// Prints a summary of deposits and withdrawals that have been added to an account
/// before the closeOfBusiness function is called.
/// </summary>
void Account::printTransactions() const 
{
    cout << "Deposits: ";
    for (double d : deposits) {
        cout << "$" << d << " ";
    }
    cout << endl;

    cout << "Withdrawals: ";
    for (double w : withdrawals) {
        cout << "$" << w << " ";
    }
    cout << endl;
}
