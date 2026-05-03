#include <iostream>
using namespace std;

int main() {
    int pin;                          // for PIN input 
    int fixed_pin = 1234;             // fixed PIN 
    int attempts = 0;                 // login attempts
    float balance = 1000.0;           // total balance
    float amount = 0.0;               // for deposit
    char last_transaction_type = 'N'; // 'N' = None, 'D' = Deposit, 'W' = Withdraw
    float last_transaction_amount = 0;
    bool isRunning = true;            // bool used for program loop

    // Welcome Screen
    cout << "=====================================\n";
    cout << "       Welcome to Simple ATM     \n";
    cout << "======================================\n";
    cout << "Please insert your card and enter your PIN  \n\n";

    //  PIN Verification using while loop  max 3 attempts
    while (attempts < 3) {
        cout << "Enter PIN: ";
        cin >> pin;
        //if-else 
        if (pin == fixed_pin) {
            cout << "\nLogin successful!\n";
            break; // exit loop if PIN correct
        }
        else {
            attempts++;
            cout << "Incorrect PIN. Attempts left: " << (3 - attempts) << "\n";
        }

        if (attempts == 3) {
            cout << "\n Your atm card has been locked due to multiple wrong attempts  \n";
            return 0;
        }
    }

    // Main Menu Loop 
    do {
        cout << "\n=========== MAIN MENU ===========\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Mini Statement\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        // switch 
        switch (choice) {
        case 1: // Check Balance
            cout << "\nYour current balance is: " << balance << " PKR\n";
            break;

        case 2: // Deposit Money
            cout << "\nEnter amount to deposit: ";
            cin >> amount;

            // Overflow check    if condition
            if (balance + amount < balance) {
                cout << "Error: Balance overflow detected!\n";
            }
            else {
                balance += amount; // update balance
                last_transaction_type = 'D';
                last_transaction_amount = amount;
                cout << "Successfully deposited " << amount << " PKR.\n";
            }
            break;

        case 3: // Withdraw Money
            cout << "\nEnter amount to withdraw: ";
            cin >> amount;

            if (amount > balance) {
                cout << "Insufficient funds. Transaction cancelled.\n";
            }
            else {
                balance -= amount; // update balance
                last_transaction_type = 'W';
                last_transaction_amount = amount;
                cout << "Successfully withdrew " << amount << " PKR.\n";
            }
            break;

        case 4: // Mini Statement
            if (last_transaction_type == 'N') {
                cout << "\nNo transactions yet.\n";
            }
            else {
                cout << "\nLast Transaction: ";
                if (last_transaction_type == 'D') {
                    cout << "Deposit of " << last_transaction_amount << " PKR\n";
                }
                else if (last_transaction_type == 'W') {
                    cout << "Withdrawal of " << last_transaction_amount << " PKR\n";
                }
                cout << "Your current balance is: " << balance << " PKR\n";
                
                // Prefix (++x) and Postfix (x--) operators could be demonstrated separately
                // but here we keep the balance unchanged for accuracy.
            }
            break;

        case 5: // Exit
            cout << "\nThank you for using our ATM. Goodbye!\n";
            isRunning = false;
            break;

        default:
            cout << "\nInvalid option. Please try again.\n";
        }

    } while (isRunning); // do-while keeps running until Exit is chosen

    return 0;
}
 
