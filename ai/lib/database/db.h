// AI/LIB/DATABASE/DB.H -   USED BY "AI/LIB/DATABASE/DB.CPP

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


const int str_length = 256; // length of data in cells
const int max_rows = 256;   // maximum number of rows // horizontal
const int max_columns = 256;    // maximum number of columns // vertical

class DB {
private:
    // database rows and columns
    int row;
    int column;

    int xy[2];

    int count;

    int prev_x;
    int prev_y;

    // database content
    char db_xy[max_rows][max_columns][str_length];
    
    // active matrix
    // of rows and columns
    int xy_x[max_rows*max_columns];
    int xy_y[max_rows*max_columns];
    
    int xy_prev_x;
    int xy_prev_y;
    
    // active cell
    char current_cell[32];

    // vector 1 and 2
    int vector_rc_1[2];
    int vector_rc_2[2];

    std::string assign_label;


public:
    
    // constructor
    DB();

    // rows & colums
    void set_xy(int x, int y);  // manually set the x and y // aka row and column
    void prep_xy();     // prepares this->xy[2] with row and column number

    void setrow(int x);
    void setcolumn(int x);

    int getrow();
    int getcolumn();

    // setters
    void setrc1_x(int x);

    void setrc1_y(int x);

    void setrc2_x(int x);
    void setrc2_y(int x);

    // getters
    int getrc1_x();
    
    int getrc1_y();

    int getrc2_x();

    int getrc2_y();

    // assign_label
    void set_al(std::string s);
    std::string get_al();
};