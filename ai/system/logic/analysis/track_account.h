// AI/LOGIC/ANALYSIS/TRACK_ACCOUNT.H    - USED BY "AI/LOGIC/ANALYSIS/TRACK_ACCOUNT.CPP"

#include <iostream>

const int max_accounts = 1024;

std::string coin;

std::string coin1 = "US dollar";
std::string coin2 = "EURO";
std::string coin3 = "Yen";
std::string coins4 = "Canadian dollar";
std::string coins5 = "Kroons";

class Track_Account {
private:
    int account_nr;
    float accounts[max_accounts];

public:
    Track_Account();

    void add(float x);
    void subtract(float x);

    float getAccount();
    void setAccount(int x);
    
    float getAccountNr(int x);
    void print(); 
};
