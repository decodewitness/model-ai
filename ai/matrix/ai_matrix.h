// AI/MATRIX/MATRIX.H - MATRIX / FILTER - USED BY "AI/MATRIX/MATRIX.CPP"

class AI_Matrix {
private:
    double x, y, z;
    double a, b, c;
    bool square[32];

    double square_A[16]; // a,a1;
    double square_B[16]; // a,b2;
    double square_C[16]; // a,b3;

    // decimal plane
    double decimal_A[32]; // 30 decimals
    double decimal_B[32]; // 30 decimals
    double decimal_C[32]; // 30 decimals

    double double_A[32];      // 30 floats
    double double_B[32];      // 30 floats
    double double_C[32];      // 30 floats

public:
    // constructor
    AI_Matrix(int x=0, int y=0, int z=0) {};    // constructor
    
    // setter functions
    void assign_a(int b) { this->a = b; }
    void assign_b(int b) { this->b = b; }
    void assign_c(int b) { this->c = b; }
    void assign_x(int b) { this->x = b; }
    void assign_y(int b) { this->y = b; }
    void assign_z(int b) { this->z = b; }

    // getter functions
    int get_a() { return this->a; }
    int get_b() { return this->b; }
    int get_c() { return this->c; }
    int get_x() { return this->x; }
    int get_y() { return this->y; }
    int get_z() { return this->z; }

    // different setter functions
    void setSquares();
    
    // set squares functions
    void decA();
    void decB();
    void decC();

    // increment/decrement var &n by 1
    void inc(double &n) { n++; }
    void dec(double &n) { n--; }
    void incn(double &n, double m) { n += m; }
    void decn(double &n, double m) { n -= m; }

    // abc+xyz increment/decrement by 1
    void inca() { this->a++; }
    void deca() { this->a--; }
    void incb() { this->b++; }
    void decb() { this->b--; }
    void incc() { this->c++; }
    void decc() { this->c--; }
    void incx() { this->x++; }
    void decx() { this->x--; }
    void incy() { this->y++; }
    void decy() { this->y--; }
    void incz() { this->z++; }
    void decz() { this->z--; }

    // abc increment/decrement by n
    void incan(double &n) { this->a += n; }
    void decan(double &n) { this->a += n; }
    void incbn(double &n) { this->b += n; }
    void decbn(double &n) { this->b += n; }
    void inccn(double &n) { this->c += n; }
    void deccn(double &n) { this->c += n; }

    // xyz increment/decrement by n    
    void incxn(double &n) { this->x += n; }
    void decxn(double &n) { this->x += n; }
    void incyn(double &n) { this->y += n; }
    void decyn(double &n) { this->y += n; }
    void inczn(double &n) { this->z += n; }
    void deczn(double &n) { this->z += n; }
};

// AI/MATRIX/CMD/CMD.CPP - USED BY "/AI/MATRIX/AI_MATRIX.H"

char punch[10][8] = { "one", "two", "three",
                            "four", "five", "six",
                                "seven", "eight", "nine", "zero" };

// eof