// "/AI/USER.H" -- lesser store x credentials pairs and individual user

// CREDENTIAL PAIRS (STILL NEEDS HASHED CREDENTIALS)
std::string udb[2] = {"ai", "ai"};

// USER CONFIGURATION CRED.+ PW
std::string user = udb[0];
std::string pw = udb[1];

// STORE HASHES (NEEDS A CATALOGUE TO STORE IN THE HASHED CREDENTIALS)
std::string userh = "CRC32";
std::string passh = "CRC32";
