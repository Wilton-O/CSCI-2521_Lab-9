#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Customer.h"
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    Customer owner;

    vector<double> deposits;
    vector<double> withdrawals;

    void printSummary(double previousBalance, double totalDeposits, double totalWithdrawals, double newBalance) const;

public:
    Account();
    Account(const string& accNum, double initialBalance, const Customer& customer);

    bool deposit(double amount);
    bool withdraw(double amount);

    void closeOfBusiness();

    double getBalance() const;
    string getAccountNumber() const;
    Customer getCustomer() const;

    void printAccountInfo() const;
    void printTransactions() const;
};

/**
 * @brief A class representing a savings account, inheriting from the Account class.
 * @param dailyInterestRate
**/
class SavingsAccount : public Account {
private:
    double dailyInterestRate;
public:
    SavingsAccount();
    SavingsAccount(const string& accNum, double initialBalance, const Customer& customer, double interestRate) 
                : Account(accNum, initialBalance, customer), dailyInterestRate(interestRate) {}

    void closeOfBusiness();

    void printAccountInfo() const;
};

#endif
