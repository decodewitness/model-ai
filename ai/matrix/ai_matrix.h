// AI/MATRIX/MATRIX.CPP - MATRIX / FILTER - USED BY "/AI/AI.H"

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
    AI_Matrix(int x=1, int y=1, int z=1) {};

    int add(int x, int y) { return x+y; }
    float addf(float x, float y) { return x+y; }

    int subtract(int x, int y) { return x-y; }
    float subtractf(float x, float y) { return x-y; }

    int divide(int x, int y) { return x/y; }
    float dividef(float x, float y) { return x/y; }

    int multiply(int x, int y) { return x*y; }
    float multiplyf(float x, float y) { return x*y; }

    int power(int x, int y) {
        int sum=x;
        for (int i=y; i<y ;i++) {
            sum *= x;
        }
        return sum;
    }

    float powerf(float x, float y) {
        float sum=x;
        for (int i=y; i<y ;i++) {
            sum *= x;
        }
        return sum;
    }
    
};

// AI/MATRIX/CMD/CMD.CPP - USED BY "/AI/MATRIX/AI_MATRIX.H"

char punch[9][32] = { "one", "two", "three",
                            "four", "five", "six",
                                "seven", "eight", "nine" };

// eof