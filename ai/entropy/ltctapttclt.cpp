//  "AI/ENTROPY/LTCTAPTTCLT.CPP" USED BY "AI.H"

#include <fstream>

void fcltaptaptap() {
    
    char str[10] = "data.txt";
    
    //std::cout << "Enter the name of an existing text file: ";
    //std::cin.get (str,256);    // get c-string
    
    std::ifstream is(str);     // open file
    char c;
    
    while (is.get(c))          // loop getting single characters
        std::cout << c;
    
    is.close();                // close file
}

// title panel                          //t1
/* int t1() {;}                             //tl
 * void tl() {;}                //1tlt1tl
 * void lt1tlt1() {;}           //t1tl      (THE B3HIv3)
 * void t1tl() {;} */           //tl
// trousers                     //t1
/* void lt1tlt1(int t) {;}
 * void tlt1(int t) {;}
 * int t1(int t) {;}
 */
// // title panel
// void lt1tlt1() {std::cout << "holy";}
// void t1tl() {std::cout << "taplc";}
// void tl() { std::cout << "ltct";}
// int t1() { std::cout << "tapsh";}
// // trousers
// void lt1tlt1(int t) {std::cout << "tap";}
// void tlt1(int t) {std::cout << "tap";}
// int t1(int t) {std::cout << "tap";}

// eof