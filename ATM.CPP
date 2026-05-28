#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ATM {
private:
    int pin = 281104;
    double balance = 5000.0;
    vector<string> history;

public:

    bool login() {
        int enteredPin;

        cout << "=====================================\n";
        cout << "         ATM SIMULATOR\n";
        cout << "=====================================\n";

        cout << "Enter your PIN: ";
        cin >>  enteredPin;

        if ( enteredPin == pin) {
            cout << "\nLogin Successful!\n";
            return true;
        } else {
            cout << "\nIncorrect PIN!\n";
            return false;
        }
    }

    void checkBalance() {
        cout << "\nCurrent Balance: Rs. " << balance << endl;
        history.push_back("Checked Balance");
    }

    void deposit() {
        double amount;

        cout << "\nEnter amount to deposit: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "Deposit Successful!\n";
            history.push_back("Deposited Rs. " + to_string((int)amount));
        } else {
            cout << "Invalid Amount!\n";
        }
    }

    void withdraw() {
        double amount;

        cout << "\nEnter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
            history.push_back("Withdrew Rs. " + to_string((int)amount));
        } else {
            cout << "Insufficient Balance or Invalid Amount!\n";
        }
    }

    void transfer() {
        double amount;
        string receiver;

        cout << "\nEnter receiver name: ";
        cin >> receiver;

        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Transfer Successful to " << receiver << "!\n";

            history.push_back("Transferred Rs. " +
                              to_string((int)amount) +
                              " to " + receiver);
        } else {
            cout << "Transfer Failed!\n";
        }
    }

    void showHistory() {

        cout << "\n========== TRANSACTION HISTORY ==========\n";

        if (history.empty()) {
            cout << "No transactions available.\n";
        } else {
            for (string record : history) {
                cout << "- " << record << endl;
            }
        }
    }
};

int main() {

    ATM atm;

    if (!atm.login()) {
        return 0;
    }

    int choice;

    do {

        cout << "\n=====================================\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";
        cout << "=====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                atm.checkBalance();
                break;

            case 2:
                atm.deposit();
                break;

            case 3:
                atm.withdraw();
                break;

            case 4:
                atm.transfer();
                break;

            case 5:
                atm.showHistory();
                break;

            case 6:
                cout << "\nThank You for Using ATM Simulator!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}


