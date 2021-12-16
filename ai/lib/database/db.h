#include <string>

// database settings
    // increase "max_entries" after testing
const std::string DATA = "data/data";
const int max_entries = 128; // will use # keys for key:data pairs

// database access
const std::string dbuser = "model_ai";
const std::string dbpassword = "model_ai";

// database values  (row and columned defined elsewhere)
const std::string table = "model_ai";
const std::string value = "model_ai";
const std::string keyVal = "model_ai";
const std::string atIndex = "model_ai";

// credentials for your database += these are template...
const std::string mysqldata = "mysql,mysql";
const std::string postgresdata = "postgres,postgres";

// database connection strings
const std::string db_connection_string = "connection_string_here";
const std::string mysql_db_connection_string = "connection_string_here";
const std::string postgres_db_connection_string = "connection_string_here";
