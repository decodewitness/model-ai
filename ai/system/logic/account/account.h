// AI/LOGIC/ANALYSIS/ACCOUNT.H    - USED BY "AI/LOGIC/ANALYSIS/TRACK_ACCOUNT.CPP"

#include <iostream>

// #define _TRANSACTION_LOG "ai/log/account-transactions.txt"

// maximum number of accounts
const int max_accounts = 1024;

// names for the transaction log and account information log
const char _TRANSACTION_LOG[] = "ai/log/account-transactions.txt";
const char _ACCOUNT_INFORMATION[] = "ai/log/account-information.txt";

// name for the exported file for the accounts
const std::string exp_account = "export_account.txt";
const std::string imp_account = exp_account;

// std::string coin;

// std::string coin_symbol = "$";
// std::string coin1 = "US dollar";
// std::string coin2 = "EURO";
// std::string coin3 = "Yen";
// std::string coins4 = "Canadian dollar";
// std::string coins5 = "Kroons";

int coin_no = 0;

char coin_symbol[][4] = { "$", "EUR", "Y", "$", "Kr" };
char coin[][16] = { "US dollar", "EURO", "Yen", "Canadian dollar", "Kroons" };

class Track_Account {
private:
    int account_nr;
    float accounts[max_accounts];

public:
    Track_Account();

    void add(float x);  // adds amount 'x' to active account
    void subtract(float x); // subtracts amount 'x' from active account

    int getAccount(); // returns the active account number
    void setAccount(int x); // sets the active account to 'x'
    
    void print();   // prints balance without any additional information but valuta
    void printn();  // prints (balance / account info) and some additional information

    void combined_total();  // lists total amount in accounts

    void list_positives();  // lists accounts with positive balance
    void list_negatives();  // lists accounts with negative balance

    void store_accounts();  // stores accounts to disk
    void store_accounts_details();  // stores account details to disk

    void transfer_account(int src, int dst, float amount);

    void import_accounts(std::string filen);    // import accounts (account #, amount, coin_nr) from importable format
    void export_accounts(std::string filen="accounts.txt"); // export accounts in an importable format
};
