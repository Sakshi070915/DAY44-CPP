//Design a Bank Account class with basic credit and debit operations in C++ 
//using obejct oriented programming feature
#include <iostream>
#include <string>
using namespace std;

// BankAccount class definition
class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance >= 0 ? initialBalance : 0; // Ensure non-negative balance
    }

    // Display account details
    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    // Credit operation
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully credited $" << amount << " to your account." << endl;
        } else {
            cout << "Invalid amount! Cannot credit negative or zero value." << endl;
        }
    }

    // Debit operation
    void debit(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Successfully debited $" << amount << " from your account." << endl;
            } else {
                cout << "Insufficient balance! Debit operation failed." << endl;
            }
        } else {
            cout << "Invalid amount! Cannot debit negative or zero value." << endl;
        }
    }
};

int main() {
    // Create a BankAccount object
    BankAccount myAccount("John Doe", 12345678, 500.0);

    // Display initial account details
    myAccount.displayAccountDetails();

    // Perform some operations
    myAccount.credit(200.0);  // Adding money
    myAccount.displayAccountDetails();

    myAccount.debit(150.0);  // Withdrawing money
    myAccount.displayAccountDetails();

    myAccount.debit(1000.0); // Attempt to withdraw more than balance

    return 0;
}
