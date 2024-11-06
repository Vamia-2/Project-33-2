#pragma once
#include <iostream>
#include <string>
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