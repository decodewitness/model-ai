// AI/LOGIC/ANALYSIS/ACCOUNT.CPP    - USED BY "AI/AI.H"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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
    std::cout << "balance: [" << accounts[this->account_nr] << " " << coin[coin_no] << "].";    
};

void Track_Account::printn() {  // prints balance receipt with additional information

    std::cout << std::endl << "- account: (" << this->getAccount() << ") --> ";

    // if (accounts[this->account_nr] < 0) {
    //     std::cout << "-/";
    // }

    this->print();
    // std::cout << accounts[this->account_nr] << " " << coin[coin_no] << ").";
    std::cout << std::endl << std::endl;
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

    std::cout << "- accounts with a positive balance:" << std::endl;
    std::cout << std::endl;

    for (int i=0; i<max_accounts; i++) {
        if (accounts[i] > 0) {
            std::cout << "#(" << i << "). --> (" << coin_symbol[coin_no] << " "<< accounts[i] << " " << coin[coin_no] << ")." << std::endl; 
        }        
    }
};

void Track_Account::list_negatives() {

    std::cout << "- accounts with a negative balance:" << std::endl;
    std::cout << std::endl;

    for (int i=0; i<max_accounts; i++) {
        if (accounts[i] < 0) {
            std::cout << "#(" << i << "). --> (" << coin_symbol[coin_no] << " "<< accounts[i] << " " << coin[coin_no] << ")." << std::endl; 
        }        
    }
};

void Track_Account::transfer_account(int src, int dst, float amount) {
    
    bool logging=false;

    int current_account = getAccount();
    int saldo1 = accounts[account_nr];
    int saldo2;

    std::ofstream af;
    af.open(_TRANSACTION_LOG);
    if (af.is_open() == true) {
        std::cout << "(debug) ~:: successfully opened: \"" << _TRANSACTION_LOG << "\"." << std::endl;
        logging = true;
    }

    this->setAccount(src);  // change to src account and subtract amount
    this->subtract(amount);

    this->setAccount(dst);  // change to dst account and add amount
    saldo2 = accounts[account_nr];
    this->add(amount);

    // check new saldo

    // output
    std::cout << std::endl;
    std::cout << "~: transfer from account: (" << src << ")->(" << dst << ")" << std::endl << std::endl;
    std::cout << "\tINITIAL SALDO: (#" << src << ")[" << coin_symbol[coin_no] << " " << saldo1 << "] -&- (#" << dst << ")[" << coin_symbol[coin_no] << " " << saldo2 << "]:" << std::endl;
    std::cout << "\t\t-: amount in transfer: (" << amount << ") " << coin[coin_no] << "." << std::endl;
    std::cout << std::endl;
    std::cout << "\t#1 new saldo: account(" << src << ") => [[ " << coin[coin_no] << " " << (saldo1 - amount) << "]]" << std::endl;
    std::cout << "\t\t#2 new saldo: account(" << dst << ") => [[ " << coin[coin_no] << " " << (saldo2 + amount) << "]]" << std::endl;
    std::cout << std::endl << std::endl;

    // change account back to original account
    this->setAccount(current_account);

    // log to transaction log _TRANSACTION_LOG
    if (logging == true) {
        af << "Transaction:" << std::endl << "-----" << std::endl;
        af << "account: " << src << " ;; new saldo: " << (saldo1 - amount) << std::endl;
        af << "account: " << dst << " ;; new saldo: " << (saldo2 + amount) << std::endl;
        af << "< - > amount transferred: " << amount << coin[coin_no] << std::endl;
        af << std::endl;

        // close file stream
        af.close();
    }
};

void Track_Account::store_accounts() {
    
    std::ofstream fs;
    //std::string filen = "accounts.txt";

    fs.open(_ACCOUNT_INFORMATION);

    if (fs.is_open() == true) {
        std::cout << "~:: storing accounts information --> (" << _ACCOUNT_INFORMATION << ")." << std::endl;
        std::cout << "\t~:: writing accounts:" << std::endl << "\t\t";

        fs << "valuta type: #" << coin_no << " --> " << coin[coin_no] << std::endl << std::endl;

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

void Track_Account::store_accounts_details() {
    
    std::ofstream fs;
    // std::string filen = "accounts.txt";

    fs.open(_ACCOUNT_INFORMATION);

    std::cout << "~:: storing accounts information --> (" << _ACCOUNT_INFORMATION << ")." << std::endl;

    if (fs.is_open() == true) {
        
        std::cout << "\t~:: writing accounts:" << std::endl << "\t\t";
        
        fs << "valuta type: (#" << coin_no << ") --> " << coin[coin_no] << std::endl << std::endl;

        for (int i=0; i<max_accounts; i++) {
            if (accounts[i] < 0.00 || accounts[i] > 0.00) {
                fs << "account: (" << i << ")" << std::endl;
                fs << "- balance: " << coin_symbol[coin_no] << " " << accounts[i] << " " << coin[coin_no] << std::endl;
                std::cout << ".";
            }
        }

        std::cout << std::endl << "\t~:: closing file." << std::endl;
        fs.close();

        std::cout << "~:: successfully stored accounts information." << std::endl;
    }
};

void Track_Account::export_accounts(std::string filen) {
    
    std::ofstream fs;
    //std::string filen = "accounts.txt";

    fs.open(filen);

    if (fs.is_open() == true) {
        std::cout << "~:: exporting accounts information for later imports." << std::endl;
        
        int exported = 0;

        for (int i=0; i<max_accounts; i++) {
            
            if (accounts[i] > 0.00) {
                exported++;

                fs << i << ":";
                fs << accounts[i] << ":";
                fs << coin_no;
                fs << std::endl;
            }
        }

        fs.close();

        std::cout << "~:: exported (" << exported << ") account(s) to: \"" << filen << "\"" << std::endl;
    }
};

// needs fixing
void Track_Account::import_accounts(std::string filen) {

    std::cout << std::endl;
    std::cout << "~:: importing account(s) from: \"" << filen << "\"." << std::endl;

    std::string line;
    std::ifstream infile;
    std::vector<int> vect;

    infile.open(filen);

    if (infile.is_open() == true) {
        while (infile >> line) {
            std::stringstream ss(line);

            for (int i; ss >> i;) {
                vect.push_back(i);    
                if (ss.peek() == ':') {
                    ss.ignore();
                }
            }

            std::cout << "\t- importing account: ";

            for (std::size_t i = 0; i < vect.size(); i++) {
                
                // STILL need to convert this to a number!!!
                    // AND import it into the correct account.
                
                std::cout << vect[i] << " ";
            }
        
            std::cout << std::endl;
        }

        infile.close();
    }
};