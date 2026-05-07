#include <iostream>
#include <ctime>
using namespace std;

class ATM {
private:
    int pin;
    double balance;
    string name, address, branch;
    int accNumber;

public:
    // Constructor
    ATM() {
        pin = 12345;
        balance = 20000; // present balance
        name = "Rakesh Kharva";
        address = "Mumbai";
        branch = "Andheri";
        accNumber = 5678;
    }

    // Show current date & time
    void showDateTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "Current Date & Time: " << dt << endl;
    }

    // Welcome screen
    void welcomeScreen() {
        cout << "\n=====================================\n";
        cout << "        WELCOME TO ATM\n";
        cout << "=====================================\n";
        showDateTime();

        cout << "\nPress 1 to Access Account\n";
        cout << "Press 0 for Help\n";
        cout << "Enter choice: ";
    }

    // Help screen
    void helpScreen() {
        cout << "\n=====================================\n";
        cout << "           HELP SCREEN\n";
        cout << "=====================================\n";
        cout << "You must have correct PIN to access account.\n";
        cout << "Contact bank for assistance.\n";
        cout << "=====================================\n";
    }

    // PIN verification
    bool verifyPin() {
        int enteredPin;
        cout << "\nEnter Your PIN (Only one attempt): ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            return true;
        } else {
            cout << "\nIncorrect PIN! No more attempts allowed.\n";
            return false;
        }
    }

    // Main menu
    void menu() {
        int choice;
        do {
            cout << "\n=====================================\n";
            cout << "         ATM MAIN MENU\n";
            cout << "=====================================\n";
            cout << "1. Deposit Cash\n";
            cout << "2. Withdraw Cash\n";
            cout << "3. Balance Inquiry\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: deposit(); break;
                case 2: withdraw(); break;
                case 3: checkBalance(); break;
                case 0: cout << "\nThank you for using ATM!\n"; break;
                default: cout << "Invalid choice!\n";
            }

        } while (choice != 0);
    }

    // Deposit function
    void deposit() {
        double amount;
        cout << "\n--- DEPOSIT ---\n";
        cout << "Account Holder: " << name << endl;
        cout << "Current Balance: Rs. " << balance << endl;

        cout << "Enter amount to deposit: ";
        cin >> amount;

        balance += amount;

        cout << "New Balance: Rs. " << balance << endl;
    }

    // Withdraw function
    void withdraw() {
        double amount;
        cout << "\n--- WITHDRAW ---\n";
        cout << "Current Balance: Rs. " << balance << endl;

        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
            cout << "Remaining Balance: Rs. " << balance << endl;
        }
    }

    // Balance check
    void checkBalance() {
        cout << "\n--- BALANCE INQUIRY ---\n";
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    ATM atm;
    int choice;

    atm.welcomeScreen();
    cin >> choice;

    if (choice == 1) {
        if (atm.verifyPin()) {
            atm.menu();
        }
    } else if (choice == 0) {
        atm.helpScreen();
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}