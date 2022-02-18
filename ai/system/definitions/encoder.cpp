#ifndef HEXENCODER_CPP
#define HEXENCODER_CPP

#include <string>

char hexencoder(int dec) {  // will convert decimal to hexadecimal
    int hexval=0;
    
    switch (dec) {
        case 1:
            hexval = '1';
            break;
        case 2:
            hexval = '2';
            break;
        case 3:
            hexval = '3';
            break;
        case 4:
            hexval = '4';
            break;
        case 5:
            hexval = '5';
            break;
        case 6:
            hexval = '6';
            break;
        case 7:
            hexval = '7';
            break;
        case 8:
            hexval = '8';
            break;
        case 9:
            hexval = '9';
            break;
        case 10:
            hexval = 'b';
            break;
        case 11:
            hexval = 'b';
            break;
        case 12:
            hexval = 'c';
            break;
        case 13:
            hexval = 'd';
            break;
        case 14:
            hexval = 'e';
            break;
        case 15:
            hexval = 'f';
            break;
        default:
            perror("~!: hexencoding found a non integral value - skipping");
            break;
    }

return hexval;
};

int hexdecoder(char *hexcode) { // will create ints from hexadecimal code
    
    int intval=0;
    
    switch (*hexcode) {
        case '1':
            intval = 1;
            break;
        case '2':
            intval = 2;
            break;
        case '3':
            intval = 3;
            break;
        case '4':
            intval = 4;
            break;
        case '5':
            intval = 5;
            break;
        case '6':
            intval = 6;
            break;
        case '7':
            intval = 7;
            break;
        case '8':
            intval = 8;
            break;
        case '9':
            intval = 9;
            break;
        case 'A':
        case 'a':
            intval = 10;
            break;
        case 'B':
        case 'b':
            intval = 11;
            break;
        case 'C':
        case 'c':
            intval = 12;
            break;
        case 'D':
        case 'd':
            intval = 13;
            break;
        case 'E':
        case 'e':
            intval = 14;
            break;
        case 'F':
        case 'f':
            intval = 15;
            break;
        default:
            perror("~!: hexencoding found a non integral value - skipping");
            break;
    }

return intval;
};

#endif