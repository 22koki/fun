#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);
double payBill(double balance);
double transferToAccount(double balance);
double transferToPhone(double balance);

int main() {
    double balance = 0;
    int choice = 0;

    do {
        cout << "\n--- Banking System ---\n";
        cout << "Enter your choice:\n";
        cout << "1. Show Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Pay Bill\n";
        cout << "5. Transfer to Account\n";
        cout << "6. Transfer to Phone\n";
        cout << "7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit();
                showBalance(balance);
                break;
            case 3:
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            case 4:
                balance -= payBill(balance);
                showBalance(balance);
                break;
            case 5:
                balance -= transferToAccount(balance);
                showBalance(balance);
                break;
            case 6:
                balance -= transferToPhone(balance);
                showBalance(balance);
                break;
            case 7:
                cout << "Thanks for visiting!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

void showBalance(double balance) {
    cout << "Your balance is: sh" << fixed << setprecision(2) << balance << endl;
}

double deposit() {
    double amount = 0;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        return amount;
    } else {
        cout << "That's not a valid amount.\n";
        return 0;
    }
}

double withdraw(double balance) {
    double amount = 0;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient funds.\n";
        return 0;
    } else if (amount < 0) {
        cout << "That's not a valid amount.\n";
        return 0;
    } else {
        return amount;
    }
}

double payBill(double balance) {
    double amount = 0;
    string billType;
    cout << "Enter bill type (e.g., Electricity, Water): ";
    cin >> billType;
    cout << "Enter bill amount: ";
    cin >> amount;

    if (amount > balance) {
        cout << "Insufficient funds to pay the " << billType << " bill.\n";
        return 0;
    } else if (amount <= 0) {
        cout << "That's not a valid amount.\n";
        return 0;
    } else {
        cout << "Successfully paid the " << billType << " bill of sh" << fixed << setprecision(2) << amount << ".\n";
        return amount;
    }
}

double transferToAccount(double balance) {
    double amount = 0;
    string targetAccount;
    cout << "Enter target account number: ";
    cin >> targetAccount;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    if (amount > balance) {
        cout << "Insufficient funds to transfer.\n";
        return 0;
    } else if (amount <= 0) {
        cout << "That's not a valid amount.\n";
        return 0;
    } else {
        cout << "Successfully transferred sh" << fixed << setprecision(2) << amount
             << " to account " << targetAccount << ".\n";
        return amount;
    }
}

double transferToPhone(double balance) {
    double amount = 0;
    string phoneNumber;
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    if (amount > balance) {
        cout << "Insufficient funds to transfer.\n";
        return 0;
    } else if (amount <= 0) {
        cout << "That's not a valid amount.\n";
        return 0;
    } else {
        cout << "Successfully transferred sh" << fixed << setprecision(2) << amount
             << " to phone number " << phoneNumber << ".\n";
        return amount;
    }
}