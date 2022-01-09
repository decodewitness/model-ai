#include "ai_matrix.h"

AI_Matrix::AI_Matrix(int x, int y, int z) { // square measure (3, 3, 3)
        // x=top y=middle z=bottom (section of square of 9) (max: 3)
        
        bool square[10];
        int a, b, c;

        //     a    b    c
        // 1 ixxx ixxx ixxx
        // 2  xxx  xxx  xxx
        // 3  xxx  xxx  xxx

        // legend for the matrix a,b,c[0] = N_square[n]=x,y,z
        /* 
         * case n: A_square[0] = x;     // first number
         *         A_square[1] = 0;     // second number
         *         A_square[2] = 0;     // 3rd number or quotations
         *         A_square[3] = 0;     // minus fractions
         *         A_square[4] = 0;     // level of quotation
         *         A_square[5] = 0;     // integral sum of all numbers
         *         A_square[6] = 0;     // size of accumulated number fractions
         *         A_square[7] = 0;     // length of decimals (nnnth)
         *         A_square[8] = 0;     // planar scales
         *         A_square[9] = 0;     // size of strings in quotation
         * break;
         *         B_square[0] = y;     // spreading values over B_square[array];
         *         B_square[9] = x;
         * 
         *         decimalA[0] = B*(z/n*2);     // measures in plane
         *         decimalA[9] = B*(z/n*2);
         *
         *         decimalB[9] = z;
         *
         *         decimalC[0] = z;
         */

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

        // alpha computations
        square_A[0] = x;
        square_A[1] = y;
        square_A[2] = z;

        // beta computations
        square_B[0] = y;
        square_B[9] = z;

        // calculations
        square_C[9] = x;

        // draw decimal equations
        decimal_A[0] = x+x;
        decimal_A[1] = x*x;
        decimal_A[2] = x/x;
        decimal_A[3] = x*2;
        decimal_A[4] = x/2;
        decimal_A[5] = x/3;
        decimal_A[6] = x/1.5;
        decimal_A[7] = x/4;
        decimal_A[8] = x/10;
        decimal_A[9] = x/100;

        decimal_B[0] = y+y;
        decimal_B[1] = y*y;
        decimal_B[2] = y/y;
        decimal_B[3] = y*2;
        decimal_B[4] = y/2;
        decimal_B[5] = y/3;
        decimal_B[6] = y/1.5;
        decimal_B[7] = y*2.5;
        decimal_B[8] = y/10;
        decimal_B[9] = y/100;

        decimal_C[0]  = x+y;
        decimal_C[1]  = x-y;
        decimal_C[2]  = x*y;
        decimal_C[3]  = x/y;
        decimal_C[4]  = y/x;
        decimal_C[5]  = x + (x+y);
        decimal_C[6]  = x + (x-y);
        decimal_C[7]  = x + (x*y);
        decimal_C[8]  = x + (x/y);
        decimal_C[9]  = x + (y-x);
        decimal_C[10] = x + (y/x);
        decimal_C[11] = x + (y*2);
        decimal_C[12] = x + (x*y*2);
        decimal_C[13] = x + (y*2);
};
