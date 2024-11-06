#include <iostream>
#include <string>

using namespace std;

class BankException {
public:
    virtual string showMessage() = 0;
};

class InvalidAmountException : public BankException {
public:
    string showMessage() override {
        return "Неправильна сума. Введіть додатнє число.";
    }
};

class InsufficientFundsException : public BankException {
public:
    string showMessage() override {
        return "Недостатньо коштів на рахунку.";
    }
};

class BankAccount {
private:
    double balance;
    int accountNumber;

public:
    BankAccount(int number, double initialBalance) : accountNumber(number), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount < 0) {
            throw InvalidAmountException();
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw InvalidAmountException();
        }
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    setlocale(0, "");
    BankAccount account(12345, 1000);

    while (true) {
        cout << "Вітаємо в банківській системі!\n";
        cout << "Виберіть дію:\n";
        cout << "1. Поповнити рахунок\n";
        cout << "2. Зняти кошти\n";
        cout << "3. Перевірити баланс\n";
        cout << "4. Вихід\n";

        int choice;
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                double amount;
                cout << "Введіть суму для поповнення: ";
                cin >> amount;
                account.deposit(amount);
                break;
            }
            case 2: {
                double amount;
                cout << "Введіть суму для зняття: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            }
            case 3:
                cout << "Поточний баланс: " << account.getBalance() << endl;
                break;
            case 4:
                return 0;
            default:
                cout << "Неправильний вибір.\n";
            }
        }
        catch (BankException& ex) {
            cout << "Помилка: " << ex.showMessage() << endl;
        }
    }
}