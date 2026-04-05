/**
 * @file Source.cpp
 * @author Wilton Oliver
 * @date 2026-04-05
 * @brief A banking simulation interacting with Account and Customer objects.
 */

#include <iostream>
#include "Account.h"

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

/**
 * @brief Entry point for the banking application. 
 *        Edited to implement case functions (DEPOSIT, WITHDRAWAL, CLOSE_OF_BUSINESS),
 *        polymorphism with the SavingsAccount class object.
 * @return 0 to indicate success.
 */
int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    //Account account("0123456789", 100.00, customer);
    // EDIT: create savingsAccount object to replace Account object, store it in pointer of type Account*
    SavingsAccount account("0123456789", 100.00, customer, 0.01);
    Account* accountPtr = &account;

    account.printAccountInfo();

    double depositAmt = 0.0, withdrawAmt = 0.0;
    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
            // EDIT: Implemented user I/O for deposit amount
            // deposit amount is validated as being 'above $0'
            // valid input is deposited into the user/object account
            case DEPOSIT:
                cout << "Enter deposit amount: ";
                cin >> depositAmt;

                if(depositAmt <= 0){ 
                    cout << "Invalid deposit. Deposit amount must be greater than 0." << endl;
                }
                else {
                    account.deposit(depositAmt);
                }

                break;

            // EDIT: Implemented user I/O for withdraw amount
            // deposit amount is validated as being 'above $0'
            // valid input is withdrawn from the user/object account
            case WITHDRAWAL:
                cout << "Enter withdrawal amount: ";
                cin >> withdrawAmt;

                if(withdrawAmt <= 0){ 
                    cout << "Invalid withdraw. Withdraw amount must be greater than 0." << endl;
                }
                else {
                    account.withdraw(withdrawAmt);
                }

                break;

            // EDIT: Call closeOfBusiness() on the base class pointer/reference to show that the derived version is called.
            case CLOSE_OF_BUSINESS:
                accountPtr->closeOfBusiness();
                break;
        }

        menuChoice = getMenuOption();
    }
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT && choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}
