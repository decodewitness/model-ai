#include "ai_matrix.h"

AI_Matrix::AI_Matrix(int x, int y, int z) { // square measure (3, 3, 3)
    // x=top y=middle z=bottom (section of square of 9) (max: 3)
    bool square[10];
    int a, b, c;

    //     a    b    c
    // 1 ixxx ixxx ixxx
    // 2  xxx  xxx  xxx
    // 3  xxx  xxx  xxx

    int A_square[10]; // a,a1;
    int B_square[10]; // a,b2;
    int C_square[10]; // a,b3;
    int decimal[30]; // 30 decimals
   
    switch (x) { // 120 A_square units {x+y+z=360}
        
        case 0: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = -2;
                break;

        case 1: A_square[0] = 1;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 2: A_square[0] = 2;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;
        
        case 3: A_square[0] = 3;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 4: A_square[0] = 4;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 5: A_square[0] = 5;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;
                
        case 6: A_square[0] = 6;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 7: A_square[0] = 7;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;
                
        case 8: A_square[0] = 8;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 9: A_square[0] = 9;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;     
                break;

        case 10:
                A_square[0] = 10;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;     
                break;

        default:
                A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 1;
            break;
    };

    switch (y) {
         case 0: A_square[0] = 0;
                 A_square[1] = 1;
                 A_square[2] = 0;
                 A_square[3] = 0;
                 A_square[4] = 0;
                 A_square[5] = 0;
                 A_square[6] = 0;
                 A_square[7] = 0;
                 A_square[8] = 0;
                 A_square[9] = -2;
                 break;
         
         case 1: A_square[0] = 0;
                 A_square[1] = 1;
                 A_square[2] = 0;
                 A_square[3] = 0;
                 A_square[4] = 0;
                 A_square[5] = 0;
                 A_square[6] = 0;
                 A_square[7] = 0;
                 A_square[8] = 0;
                 A_square[9] = 0;
                 break;

        case 2: A_square[0] = 0;
                A_square[1] = 2;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 3: A_square[0] = 0;
                A_square[1] = 3;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;
        
        case 4: A_square[0] = 0;
                A_square[1] = 4;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 5: A_square[0] = 0;
                A_square[1] = 5;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 6: A_square[0] = 0;
                A_square[1] = 6;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;
                
        case 7: A_square[0] = 0;
                A_square[1] = 7;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 8: A_square[0] = 0;
                A_square[1] = 8;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;
                
        case 9: A_square[0] = 0;
                A_square[1] = 9;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 10:
                A_square[0] = 0;
                A_square[1] = 10;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;     
                break;

        default:
                A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 1;
            break;
    };

    switch (z) {
        case 0: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = -2;
                break;
         
        case 1: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 1;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 2: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 2;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 3: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 3;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;
        
        case 4: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 4;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 5: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 5;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 6: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 6;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;
                
        case 7: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 7;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 8: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 8;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;
                
        case 9: A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 9;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 0;
                break;

        case 10: A_square[0] = 0;
                 A_square[1] = 0;
                 A_square[2] = 10;
                 A_square[3] = 0;
                 A_square[4] = 0;
                 A_square[5] = 0;
                 A_square[6] = 0;
                 A_square[7] = 0;
                 A_square[8] = 0;
                 A_square[9] = 0;     
                 break;

        default:
                A_square[0] = 0;
                A_square[1] = 0;
                A_square[2] = 0;
                A_square[3] = 0;
                A_square[4] = 0;
                A_square[5] = 0;
                A_square[6] = 0;
                A_square[7] = 0;
                A_square[8] = 0;
                A_square[9] = 1;
            break;
    };
};
