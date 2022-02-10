// AI/MATRIX/MATRIX.H - MATRIX / FILTER - USED BY "AI/MATRIX/MATRIX.CPP"

class AI_Matrix {
    private:

    int x, y, z;

        bool square[10];
        int a, b, c;

        float square_A[10]; // a,a1;
        float square_B[10]; // a,b2;
        float square_C[10]; // a,b3;
    
        // decimal plane
        float decimal_A[30]; // 30 decimals
        float decimal_B[30]; // 30 decimals
        float decimal_C[30]; // 30 decimals

        float float_A[30];      // 30 floats
        float float_B[30];      // 30 floats
        float float_C[30];      // 30 floats

    public:
    AI_Matrix(int x=1, int y=1, int z=1) {};    // constructor    
};

// AI/MATRIX/CMD/CMD.CPP - USED BY "/AI/MATRIX/AI_MATRIX.H"

char punch[10][8] = { "one", "two", "three",
                            "four", "five", "six",
                                "seven", "eight", "nine", "zero" };

// eof