// AI/SYSTEM/MENU/MENU.CPP -   USED BY "AI/AI.H"

#include "menu.h"

// this file has: display(), action(), doMenuAction(), drawMenu()

void display() {
    // display menu
    std::cout << std::endl;
    std::cout << "[] (Model-Ai) -- (Menu Options) []" << std::endl;
    std::cout << std::endl;

    for (unsigned int i=0; i<menuSize; i++) {
        std::cout << menuOption[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "(input?):-- :: ";
};

char action(void) {
    // variables
    char ch;

    // read in menu choice
    cin >> ch;

    // check menu choice validity
    if (ch != 'n' && ch != 'N'
     && ch != 'l' && ch != 'L'
     && ch != 's' && ch != 'S'
     && ch != 'd' && ch != 'D'
     && ch != 'q' && ch != 'Q') {
         std::cout << std::endl << "(wrong input): choose a valid menu option." << std::endl;
         return 1;
     } else {
        return ch;
     }
};

bool doMenuAction(char c) {
    
    bool quitloops = false;
    std::string input;
    
    switch (c) {
        case 'n':
        case 'N':
            std::cout << "- opening new file." << std::endl;
            break;

        case 'd':
        case 'D':
            std::cout << "- deleting file." << std::endl;
            break;
        
        case 's':
        case 'S':
            std::cout << "(search) : " << std::endl;
            std::getline(cin, input);
            
            std::cout << std::endl << "- searching: " << input << std::endl;
            break;
        
        case 'l':
        case 'L':
            std::cout << "(load) : " << std::endl;
            std::getline(cin, input);

            std::cout << std::endl;
            std::cout << "- loading: \"" << input << "\"";
            std::cout << std::endl;
            break;
        
        case 'q':
        case 'Q':
            quitloops = true;
            break;
        
        default:
            std::cout << std::endl;
            std::cout << "~:!:~ (error) - no such implementation ready in function doMenuAction(char).";
            std::cout << std::endl;
            break;
    };

    return quitloops;
};

// draws the menu on the screen
void drawMenu() {

    // functions declarations
    void display();
    char action(void);
    bool doMenuAction(char c);

    // variables
    char ch;
    bool x;
    // display menu

    
    do {    
        display();
        ch = action();
        
        if (ch != '1') {
            x = doMenuAction(ch);
        }        
    } while (ch == '1');
};

// eof