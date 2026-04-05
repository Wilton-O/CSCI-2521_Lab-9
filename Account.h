#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include <numeric> // for accumulate
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

    virtual void closeOfBusiness();

    double getBalance() const;
    string getAccountNumber() const;
    Customer getCustomer() const;

    virtual void printAccountInfo() const;
    void printTransactions() const;
};

/*
 * @brief A class representing a savings account, inheriting from the Account class.
 * @param dailyInterestRate
*/
class SavingsAccount : public Account {
private:
    double dailyInterestRate;
public:
    // Constructor for savingsAccount, include dailyInterestRate
    SavingsAccount() : Account(), dailyInterestRate(0.0) {}
    SavingsAccount(const string& accNum, double initialBalance, const Customer& customer, double dailyInterestRate)
        : Account(accNum, initialBalance, customer), dailyInterestRate(dailyInterestRate) {}

    // Override the closeOfBusiness function, include interest calculation
    void closeOfBusiness() override {
        double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
        double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

        double previousBalance = balance;
        double newBalance = previousBalance + totalDeposits - totalWithdrawals;

        // If balance is negative, interest does not accumulate
        if (newBalance > 0) {
            balance += (balance * dailyInterestRate);
        }

        // Display close of business results - no override
        printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

        deposits.clear();
        withdrawals.clear();
    }

    // Override the printAccountInfo function, include dailyInterestRate
    void printAccountInfo() const override {
        cout << "Savings Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "Daily Interest Rate: " << dailyInterestRate * 100 << "%" << endl;
        owner.printCustomerInfo();
    }
};

#endif
