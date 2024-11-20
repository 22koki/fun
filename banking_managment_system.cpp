#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Enum for Account Type
enum AccountType { SAVINGS, CURRENT };

// Struct for Transaction History
struct Transaction {
    string date;
    string type;
    double amount;
    double balanceAfter;
};

// BankAccount Class
class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    string password;
    double balance;
    AccountType accountType;
    vector<Transaction> transactionHistory;

    string getCurrentDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[11];
        strftime(buffer, 11, "%Y-%m-%d", ltm);
        return string(buffer);
    }

public:
    // Constructor
    BankAccount(string name, string number, string pwd, double initialBalance, AccountType type)
        : accountHolderName(name), accountNumber(number), password(pwd), balance(initialBalance), accountType(type) {}

    // Login validation
    bool login(string number, string pwd) {
        return (accountNumber == number && password == pwd);
    }

    // Display account details
    void displayAccountDetails() {
        cout << "\nAccount Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << (accountType == SAVINGS ? "Savings" : "Current") << endl;
    }

    // Display account balance
    void displayBalance() {
        cout << "\nAccount Balance: $" << balance << endl;
    }

    // Update account details
    void updateAccountDetails(string newName) {
        accountHolderName = newName;
        cout << "Account details updated successfully.\n";
    }

    // Deposit money
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive value.\n";
            return;
        }
        balance += amount;
        transactionHistory.push_back({getCurrentDate(), "Deposit", amount, balance});
        cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive value.\n";
            return;
        }
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.push_back({getCurrentDate(), "Withdrawal", amount, balance});
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    // Pay bills
    void payBill(string billType, double amount) {
        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive value.\n";
            return;
        }
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.push_back({getCurrentDate(), "Bill Payment (" + billType + ")", amount, balance});
            cout << "Paid " << billType << " bill of $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance to pay the bill.\n";
        }
    }

    // Transfer money to another account
    void transferMoney(BankAccount &toAccount, double amount) {
        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive value.\n";
            return;
        }
        if (amount <= balance) {
            balance -= amount;
            toAccount.balance += amount;
            transactionHistory.push_back({getCurrentDate(), "Transfer to " + toAccount.accountNumber, amount, balance});
            toAccount.transactionHistory.push_back({getCurrentDate(), "Transfer from " + accountNumber, amount, toAccount.balance});
            cout << "Transferred: $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance to transfer.\n";
        }
    }

    // Transfer money to a phone number (simulating mobile money transfer)
    void transferMoneyToPhone(string phoneNumber, double amount) {
        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive value.\n";
            return;
        }
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.push_back({getCurrentDate(), "Transfer to Phone " + phoneNumber, amount, balance});
            cout << "Transferred: $" << amount << " to phone number " << phoneNumber << " | New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance to transfer to phone.\n";
        }
    }

    // View transaction history
    void viewTransactionHistory() {
        if (transactionHistory.empty()) {
            cout << "No transactions available.\n";
            return;
        }
        cout << "\nTransaction History for " << accountHolderName << ":\n";
        for (const auto &t : transactionHistory) {
            cout << t.date << " | " << t.type << " | $" << t.amount << " | Balance After: $" << t.balanceAfter << endl;
        }
    }

    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }
};

// Function to register a new user
BankAccount registerNewUser() {
    string name, number, password;
    double initialBalance;
    int typeChoice;

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> number;
    cout << "Set a password: ";
    cin >> password;

    do {
        cout << "Enter initial balance (must be positive): ";
        cin >> initialBalance;
        if (initialBalance <= 0)
            cout << "Initial balance must be positive. Try again.\n";
    } while (initialBalance <= 0);

    cout << "Choose account type (1 for Savings, 2 for Current): ";
    cin >> typeChoice;

    AccountType type = (typeChoice == 1) ? SAVINGS : CURRENT;
    return BankAccount(name, number, password, initialBalance, type);
}

int main() {
    vector<BankAccount> accounts;
    int choice;

    while (true) {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Register New User\n";
        cout << "2. Login to Account\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            BankAccount newAccount = registerNewUser();
            accounts.push_back(newAccount);
        } else if (choice == 2) {
            cout << "Enter account number: ";
            string number;
            cin >> number;
            cout << "Enter password: ";
            string password;
            cin >> password;

            bool loggedIn = false;
            BankAccount *loggedInAccount = nullptr;
            for (auto &account : accounts) {
                if (account.login(number, password)) {
                    loggedIn = true;
                    loggedInAccount = &account;
                    break;
                }
            }

            if (loggedInAccount) {
                int accountChoice;
                while (true) {
                    cout << "\n--- Account Menu ---\n";
                    cout << "1. View Account Details\n";
                    cout << "2. View Account Balance\n";
                    cout << "3. Deposit Money\n";
                    cout << "4. Withdraw Money\n";
                    cout << "5. Pay Bill\n";
                    cout << "6. View Transaction History\n";
                    cout << "7. Update Account Details\n";
                    cout << "8. Transfer Money\n";
                    cout << "9. Transfer Money to Phone\n";
                    cout << "10. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> accountChoice;

                    cin.ignore();

                    if (accountChoice == 1) {
                        loggedInAccount->displayAccountDetails();
                    } else if (accountChoice == 2) {
                        loggedInAccount->displayBalance();
                    } else if (accountChoice == 3) {
                        double amount;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        loggedInAccount->deposit(amount);
                    } else if (accountChoice == 4) {
                        double amount;
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        loggedInAccount->withdraw(amount);
                    } else if (accountChoice == 5) {
                        string billType;
                        double amount;
                        cout << "Enter bill type: ";
                        cin >> billType;
                        cout << "Enter amount to pay: ";
                        cin >> amount;
                        loggedInAccount->payBill(billType, amount);
                    } else if (accountChoice == 6) {
                        loggedInAccount->viewTransactionHistory();
                    } else if (accountChoice == 7) {
                        string newName;
                        cout << "Enter new account holder name: ";
                        cin.ignore();
                        getline(cin, newName);
                        loggedInAccount->updateAccountDetails(newName);
                    } else if (accountChoice == 8) {
                        string targetNumber;
                        double amount;
                        cout << "Enter target account number: ";
                        cin >> targetNumber;
                        cout << "Enter amount to transfer: ";
                        cin >> amount;

                        bool found = false;
                        for (auto &account : accounts) {
                            if (account.getAccountNumber() == targetNumber) {
                                loggedInAccount->transferMoney(account, amount);
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            cout << "Target account not found.\n";
                        }
                    } else if (accountChoice == 9) {
                        string phoneNumber;
                        double amount;
                        cout << "Enter phone number to transfer to: ";
                        cin >> phoneNumber;
                        cout << "Enter amount to transfer: ";
                        cin >> amount;
                        loggedInAccount->transferMoneyToPhone(phoneNumber, amount);
                    } else if (accountChoice == 10) {
                        cout << "Logged out successfully.\n";
                        break;
                    } else {
                        cout << "Invalid choice. Please try again.\n";
                    }
                }
            } else {
                cout << "Login failed. Invalid account number or password.\n";
            }
        } else if (choice == 3) {
            cout << "Exiting... Thank you for using the banking system.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
