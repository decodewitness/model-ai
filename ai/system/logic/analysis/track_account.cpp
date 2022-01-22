// AI/LOGIC/ANALYSIS/TRACK_ACCOUNT.CPP    - USED BY "AI/AI.H"

#include "track_account.h"

Track_Account::Track_Account() {
    this->account_nr = 0;
    coin = coin1;

    for (int i=0; i<max_accounts; i++) {
        this->accounts[i] = 0.00;
    }
}

void Track_Account::add(float x) {
    this->accounts[this->account_nr] += x;
};

void Track_Account::subtract(float x) {
    this->accounts[this->account_nr] -= x;
};

float Track_Account::getAccount() {
    return this->account_nr;
};

void Track_Account::setAccount(int x) {
    this->account_nr = x;
};

void Track_Account::print() {
    std::cout << std::endl << "- account: (" << this->account_nr << ") :: $" << accounts[this->account_nr] << " " << coin1 << "." << std::endl << std::endl;
};