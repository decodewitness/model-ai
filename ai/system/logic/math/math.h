// AI/SYSTEM/LOGIC/MATH/MATH.H  -   USED BY "AI/AI.H"

#include <iostream>

// functions that return values
float add(float x, float y) { return x+y; };
float subtract(float x, float y) { return x-y; };
float multiply(float x, float y) { return x*y; };
float divide(float x, float y) { return x/y; };

float power(float x, float y) {    // power float x^y
    float sum=x;
    for (int i=y; i<y ;i++) {
        sum *= x;
    }
    return sum;
};

// functions that print values
void add_pr(float x, float y=2) {
    float z = add(x, y);
    std::cout << z;
};

void subtract_pr(float x, float y=2) {
    float z = subtract(x, y);
    std::cout << z;
};

void multiply_pr(float x, float y=2) {
    float z = multiply(x, y);
    std::cout << z;
};

void divide_pr(float x, float y=2) {
    float z = divide(x, y);
    std::cout << z;
};

void power_pr(float x, float y=2) {    // power float x^y
    float sum=x;
    for (int i=1; i<y ;i++) {
        sum *= x;
    }
    std::cout << sum;
};

// calculator function
float punch(float s, char c, float x) {  // s=sum, c=operator, x=operand
    
    switch (c) {
        case '+':
            return s + x;
            break;

        case '-':
            return s - x;
            break;

        case '*':
            return s * x;
            break;

        case '/':
            return s / x;
            break;

        default:
            std::cout << std::endl << "!!! (error) punch() expects: (sum),(operator),(operand) as values for the function." << std::endl;
            return 0.00;
            break;
    };
};

// eof