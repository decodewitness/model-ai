// (inside AI directory) AI/LOGIC/ALGORITHMS.CPP - USED BY "AI/AI.H" FOR THE MODEL AI

#include <cmath>
#include <algorithm>
#include <cstdio>

//#include "assembly/input.cpp"

using namespace std;

/***	MATH FUNCTIONS	***
Function 	Description
abs(x) 		Returns the absolute value of x
acos(x) 	Returns the arccosine of x
asin(x) 	Returns the arcsine of x
atan(x) 	Returns the arctangent of x
cbrt(x) 	Returns the cube root of x
ceil(x) 	Returns the value of x rounded up to its nearest integer
cos(x) 		Returns the cosine of x
cosh(x) 	Returns the hyperbolic cosine of x
exp(x) 		Returns the value of Ex
expm1(x) 	Returns ex -1
fabs(x) 	Returns the absolute value of a floating x
fdim(x, y) 	Returns the positive difference between x and y
floor(x) 	Returns the value of x rounded down to its nearest integer
hypot(x, y) 	Returns sqrt(x2 +y2) without intermediate overflow or underflow
fma(x, y, z) 	Returns x*y+z without losing precision
fmax(x, y) 	Returns the highest value of a floating x and y
fmin(x, y) 	Returns the lowest value of a floating x and y
fmod(x, y) 	Returns the floating point remainder of x/y
pow(x, y) 	Returns the value of x to the power of y
sin(x) 		Returns the sine of x (x is in radians)
sinh(x) 	Returns the hyperbolic sine of a double value
tan(x) 		Returns the tangent of an angle
tanh(x) 	Returns the hyperbolic tangent of a double value
***/

// pi function
double pi() { double p = 3.141592653589793238462; return p; }

//overrided functions
int maximum(int a=0, int b=0) { int number=std::max(a,b); return number; }
int minimum(int a=0, int b=0) { int number=std::min(a,b); return number; }
int square(int x=0) { int number=sqrt(x); return number; }


// LIST OF OWN PARAMETERS
// THE WAY IT WORkS IS DUBLICATE ONE FUNCTION ENTRY THEN
// MODIFY THE CODE TO ADJUST ITS BEHAVIOR.

// MATH FUNCTIONS

void cosinF(double param) {
    double result;
    result = cos ( param * pi() / 180.0 );
    printf ("The cosine of %f degrees is %f.\n", param, result );
};

void sinF(double param) {
    double result;
    result = sin (param*pi()/180);
    printf ("The sine of %f degrees is %f.\n", param, result );
};

void tanF(double param)
{
  double result;
  
  result = tan ( param * pi() / 180.0 );
  printf ("The tangent of %f degrees is %f.\n", param, result );
};

void acosF(double param)
{
  double result;  
  result = acos (param) * 180.0 / pi();
  printf ("The arc cosine of %f is %f degrees.\n", param, result);
};

void asinF(double param)
{
    double result;
    result = asin (param) * 180.0 / pi();
    printf ("The arc sine of %f is %f degrees\n", param, result);
};

void atanF(double param)
{
  double result;
  result = atan (param) * 180 / pi();
  printf ("The arc tangent of %f is %f degrees\n", param, result );
};

void pythagorasF(double h, double w) {
  double result;
  result = (h*h) + (w*w);
  result /= 2;
  printf("The length of the diagonal is %f\n", result);
};

void pythagorasBaseF(double h, double d) {
  double result;
  result = d * d;
  result -= (h * h);
  result /= 2;
  printf("The width is %f\n", result);
}

void pythagorasHeightF(double w, double d) {
  double result;
  result = d * d;
  result -= (w * w);
  result /= 2;
  printf("The height is %f", result);
}

void circleFromRadiusF(double r) {
  double result = 2 * r;
  result = result * pi();
  printf("The circumreference is %f\n", result);
};

void radiusFromCircleF(double c) {
  double result = c / pi();
  result = result / 2;
  printf("The radius is %f\n", result);
};