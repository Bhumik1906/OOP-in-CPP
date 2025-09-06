#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer {
private:
    int customerID;
    string customerName;

public:
    Customer(int id, string name) {
        customerID = id;
        customerName = name;
    }

    Customer() : Customer(0, "Unknown") {}

    int getID() {
        return customerID;
    }

    string getName() {
        return customerName;
    }

    void displayCustomer() {
        cout << "Customer Details --> \n";
        cout << "Customer Name: " << customerName << "\n";
        cout << "Customer ID: " << customerID << "\n";
    }
};

class Transaction {
private:
    int transactionID;
    string type;
    double amount;

public:
    Transaction(int id, string type, double amount) {
        this->transactionID = id;
        this->type = type;
        this->amount = amount;
    }

    void displayTransaction() {
        cout << "Transaction Details -> \n";
        cout << "Transaction ID: " << transactionID << "\n";
        cout << "Transaction Type: " << type << "\n";
        cout << "Transaction Amount: " << amount << "\n";
    }

    string toString() {
        return to_string(transactionID) + ", " + type + ", " + to_string(amount);
    }
};

class Account {
private:
    int accountNumber;
    double accountBalance;
    Customer Owner;
    vector<Transaction> transactions;

public:
    Account(int accNo, double bal, Customer c) {
        accountNumber = accNo;
        accountBalance = bal;
        Owner = c;
    }

    Account() : Account(0, 0.0, Customer()) {}

    void deposit(double amount) {
        accountBalance += amount;
        transactions.push_back(Transaction(transactions.size() + 1, "Deposit", amount));
    }

    void withdraw(double amount) {
        if (amount <= accountBalance) {
            accountBalance -= amount;
            transactions.push_back(Transaction(transactions.size() + 1, "Withdraw", amount));
        } else {
            cout << "Insufficient Balance! \n";
        }
    }

    void transfer(Account& receiver, double amount) {
        if (amount > accountBalance) {
            cout << "Transfer Failed! (Insufficient Balance) \n";
        } else {
            accountBalance -= amount;
            receiver.accountBalance += amount;
            transactions.push_back(Transaction(transactions.size() + 1, "Transfer", amount));
            cout << "Transfer Successful! \n";
        }
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void displayAccountInfo() {
        cout << "Account Info --> \n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << accountBalance << "\n";
        Owner.displayCustomer();
    }
};

int main() {
    int num, ops;
    cout << "Enter The Number Of Accounts: \n";
    cin >> num;

    vector<Account> accounts;
    for (int i = 0; i < num; i++) {
        int id, accNumber;
        string name;
        double bal;
        cout << "Customer ID: \n";
        cin >> id;
        cout << "Customer Name: \n";
        cin >> name;
        cout << "Customer Account Number: \n";
        cin >> accNumber;
        cout << "Customer Balance: \n";
        cin >> bal;
        accounts.push_back(Account(accNumber, bal, Customer(id, name)));
    }

    cout << "Enter The Number Of Operations: \n";
    cin >> ops;

    for (int i = 0; i < ops; i++) {
        int choice;
        cout << "***Banking Menu*** --> \n";
        cout << "1. Deposit\n2. Withdraw\n3. Transfer\n4. Show All Accounts\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int no;
            double amt;
            cout << "Enter AccountNo and Amount: ";
            cin >> no >> amt;
            for (auto& a : accounts)
                if (a.getAccountNumber() == no) a.deposit(amt);
        }
        else if (choice == 2) {
            int no;
            double amt;
            cout << "Enter AccountNo and Amount: ";
            cin >> no >> amt;
            for (auto& a : accounts)
                if (a.getAccountNumber() == no) a.withdraw(amt);
        }
        else if (choice == 3) {
            int s, r;
            double amt;
            cout << "Enter SenderAccNo ReceiverAccNo Amount: ";
            cin >> s >> r >> amt;
            Account* A = nullptr, * B = nullptr;
            for (auto& a : accounts) {
                if (a.getAccountNumber() == s) A = &a;
                if (a.getAccountNumber() == r) B = &a;
            }

            if (A && B) A->transfer(*B, amt);
            else cout << "Invalid accounts!\n";
        }
         else if (choice == 4) {
            for (auto& a : accounts) a.displayAccountInfo();
        }
         else {
            cout << "Invalid choice! \n";
        }
    }

    cout << "All operations completed. \n";
    return 0;
}
