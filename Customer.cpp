#include "Customer.h"
#include <iostream>
using namespace std;

/// <summary>
/// Default constructor
/// </summary>
Customer::Customer() 
{
    customerID = "Unknown";
    email = "none@example.com";
}

/// <summary>
/// Parameterized constructor
/// </summary>
/// <param name="id">The unique id of the customer</param>
/// <param name="emailAddr">The email address of the customer</param>
Customer::Customer(const string& id, const string& emailAddr) 
{
    customerID = id;
    email = emailAddr;
}

/// <summary>
/// Getter/Accessor to retrieve the customer's unique identifier
/// </summary>
/// <returns></returns>
string Customer::getCustomerID() const 
{
    return customerID;
}

/// <summary>
/// Getter/Accessor to retrieve the customer's email address
/// </summary>
/// <returns></returns>
string Customer::getEmail() const 
{
    return email;
}

/// <summary>
/// Function that prints an information summary about the Customer
/// </summary>
void Customer::printCustomerInfo() const 
{
    cout << "Customer ID: " << customerID << endl;
    cout << "Email: " << email << endl;
}
