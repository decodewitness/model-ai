#include <string>

#include "hash.h"
#include "user.h"


// PRIVILEGE ACCESS FUNCTIONS

// set_privileges_user(user, check_privilege(pass));
std::string set_privileges_user(std::string usr, int key) {     // usr=universal (user) && key=(int)check_key_privilege(pass)
    std::string lvl1 = "guest";
    std::string lvl2 = "user";
    std::string lvl3 = "operator";
    std::string lvl4 = "admin";
    std::string lvl5 = "sysop";
    std::string lvl6 = "ai";
    std::string lvl7 = "rescue";
    std::string lvl8 = "system";
    std::string lvl9 = "god";

return lvl3;
};

// return security level / clearance and security level
int check_key_privilege(std::string pass) {
    std::string lvl1 = "guest";
    std::string lvl2 = "user";
    std::string lvl3 = "operator";
    std::string lvl4 = "admin";
    std::string lvl5 = "sysop";
    std::string lvl6 = "ai";
    std::string lvl7 = "rescue";
    std::string lvl8 = "system";
    std::string lvl9 = "god";

return 3;
};