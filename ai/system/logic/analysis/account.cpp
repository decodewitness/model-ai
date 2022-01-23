// AI/LOGIC/ANALYSIS/ACCOUNT.CPP    - USED BY "AI/AI.H"

#include <fstream>

#include "account.h"

Track_Account::Track_Account() {
    this->account_nr = 1;   // sets account number (account_nr)
    coin_no = 1;    // changes valuta { 1=dollar; 2=euro; 3=yen; 4=canadian dollar; 5=kroons; }

    for (int i=0; i<max_accounts; i++) {
        this->accounts[i] = 0.00;
    }
}

void Track_Account::add(float x) {  // add money to account
    this->accounts[this->account_nr] += x;
};

void Track_Account::subtract(float x) { // substract money from account
    this->accounts[this->account_nr] -= x;
};

int Track_Account::getAccount() { // returns account number (account_nr)
    return this->account_nr;
};

void Track_Account::setAccount(int x) { // sets account number (account_nr)
    this->account_nr = x;
};

void Track_Account::print() {   // prints balance without line break '\n'
    if (accounts[this->account_nr] < 0) {
        std::cout << "-/";
    }
    std::cout << accounts[this->account_nr] << " " << coin[coin_no];
};

void Track_Account::printn() {  // prints balance receipt with additional information
    std::cout << std::endl << "- account: (" << this->getAccount() << ") --> (" << coin_symbol[coin_no] << ". ";
    if (accounts[this->account_nr] < 0) {
        std::cout << "-/";
    }
    std::cout << accounts[this->account_nr] << " " << coin[coin_no] << ")." << std::endl << std::endl;
};

void Track_Account::combined_total() {  // calculates the total across all accounts
    float sum=0.00;

    for (int i=0; i<max_accounts; i++) {
        sum += this->accounts[i];
    }

    std::cout << "- total accross accounts: (" << coin_symbol[coin_no] << " ";
    
    if (accounts[this->account_nr] < 0) {
        std::cout << "-/";
    }

    std::cout << sum << ")" << std::endl << std::endl;
};

void Track_Account::list_positives() {
    for (int i=0; i<max_accounts; i++) {
        if (accounts[i] > 0) {
            std::cout << "#(" << i << "). --> (" << coin_symbol[coin_no] << " "<< accounts[i] << " " << coin[coin_no] << ")." << std::endl; 
        }        
    }
};

void Track_Account::list_negatives() {
    for (int i=0; i<max_accounts; i++) {
        if (accounts[i] < 0) {
            std::cout << "#(" << i << "). --> (" << coin_symbol[coin_no] << " "<< accounts[i] << " " << coin[coin_no] << ")." << std::endl; 
        }        
    }
};

void Track_Account::store_accounts() {
    
    std::ofstream fs;
    std::string filen = "accounts.txt";

    fs.open(filen);

    std::cout << "~:: storing accounts information --> (" << filen << ")." << std::endl;

    if (fs.is_open() == true) {
        
        std::cout << "\t~:: writing accounts:" << std::endl << "\t\t";

        fs << "valuta: " << coin_no << " " << coin[coin_no] << std::endl << std::endl;

        for (int i=0; i<max_accounts; i++) {
            if (accounts[i] < 0.00 || accounts[i] > 0.00) {
                fs << i << ":" << accounts[i] << std::endl;
                std::cout << ".";
            }
        }

        std::cout << std::endl << "\t~:: closing file." << std::endl;
        fs.close();

        std::cout << "~:: successfully stored accounts information." << std::endl;
    }
};

void Track_Account::store_account_details() {
    
    std::ofstream fs;
    std::string filen = "accounts.txt";

    fs.open(filen);

    std::cout << "~:: storing accounts information --> (" << filen << ")." << std::endl;

    if (fs.is_open() == true) {
        
        std::cout << "\t~:: writing accounts:" << std::endl << "\t\t";
        
        fs << "valuta: " << coin_no << " " << coin[coin_no] << std::endl << std::endl;

        for (int i=0; i<max_accounts; i++) {
            if (accounts[i] < 0.00 || accounts[i] > 0.00) {
                fs << "account: " << i << "\tbalance: " << coin_symbol[coin_no] << " " << accounts[i] << " " << coin[coin_no] << std::endl;
                std::cout << ".";
            }
        }

        std::cout << std::endl << "\t~:: closing file." << std::endl;
        fs.close();

        std::cout << "~:: successfully stored accounts information." << std::endl;
    }
};