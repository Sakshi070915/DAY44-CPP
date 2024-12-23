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
    string name;
    int accountNumber;
    double initialBalance;

    // Take user input to create an account
    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    // Create a BankAccount object
    BankAccount userAccount(name, accountNumber, initialBalance);

    int choice;
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Display Account Details" << endl;
        cout << "2. Credit Amount" << endl;
        cout << "3. Debit Amount" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            userAccount.displayAccountDetails();
            break;
        case 2: {
            double amount;
            cout << "Enter amount to credit: ";
            cin >> amount;
            userAccount.credit(amount);
            break;
        }
        case 3: {
            double amount;
            cout << "Enter amount to debit: ";
            cin >> amount;
            userAccount.debit(amount);
            break;
        }
        case 4:
            cout << "Exiting the program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
