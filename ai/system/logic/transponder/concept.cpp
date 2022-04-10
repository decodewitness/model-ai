#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string ref_store_file = "ai/lib/queries/refs";

typedef struct ref {
    std::string nr; // number of this reference
    std::string concept;    // name of this ref/concept
    std::string description;    // summary or brief description of gained attributes
    std::string short_label;    // short label for reference
    std::string rel1;   // relation 1
    std::string rel2;   // relation 2
    std::string rel3;   // relation 3
    std::string rel4;   // relation 4
    std::string rel5;   // relation 5
    std::string rel_string; // additional relations
};

void store_refs(ref x) {
    std::ofstream store;

    std::cout << std::endl;
    std::cout << "~:: store_refs() :" << std::endl;

    store.open(ref_store_file, std::ios::app);

    if (store.is_open() == true) {
        std::cout << "\t~:: storing refs." << std::endl;

        // store ref data
        store << x.nr;
        store << ",";
        store << "\"" << x.concept << "\"";
        store << ",";
        store << "\"" << x.description << "\"";
        store << ",";
        store << "\"" << x.short_label << "\"";
        store << ",";
        store << x.rel1;
        store << ",";
        store << x.rel2;
        store << ",";
        store << x.rel3;
        store << ",";
        store << x.rel4;
        store << ",";
        store << x.rel5;
        store << ",";
        store << "\"" << x.rel_string << "\"";
        store << ";" << std::endl;

        // close file      
        store.close();
    } else {
        std::cout << std::endl;
        std::cout << "~:!:~ (error) - refs file not open." << std::endl;
    }

    if (store.is_open() == false) {
        std::cout << "~:: stored refs." << std::endl;
    }
};

ref read_refs(std::string filename, int nr=0) {  // filename with refs ;; nr of ref
    // positions in string
    int pos=0;    // first position of char elements
    int pos2=0;   // second position of char elements

    // file streams
    std::ifstream file; // file stream

    // strings
    std::string str;    // used for lines of "filename"
    std::string s;  // used as temp var for units in "str"

    // references
    ref x;  // temp reference structure

    // function prototypes
    void assign_sub(ref &x, std::string sub, int count);    // function that assigns to the temporary reference

    // function read_refs()
    std::cout << std::endl;
    std::cout << "~:: read_refs() :" << std::endl;
    
    file.open(filename);

    if (file.is_open() == true) {
        std::cout << "~:: opened refs file." << std::endl;

        while (getline(file, str)) {
            std::cout << "\t~:: process ref[] ::" << std::endl << "\t\t" << str << std::endl;
  
            // std::stringstream ss(str);

            for (int i=0; pos2 = str.find_first_of(","); i++) {
                if (i == 10) {
                    std::cout << std::endl;
                    std::cout << "~:!:~ (error) - anomaly ;; check your refs data on element size (max. 9)." << std::endl;
                    std::cout << std::endl;
                    break;
                }

                s = str.substr(pos, pos2-1);
                str.erase (pos,pos2);

                std::cout << std::endl;
                std::cout << "\t-" << i << ") s : " << s << std::endl;
                std::cout << "~:: processed." << std::endl;
                std::cout << std::endl;

                // assign sub to x element i
                assign_sub(x, s, i);
            }
        }
        // close file stream
        file.close();
    }
    std::cout << "~:: done processing refs." << std::endl;
    std::cout << std::endl;
return x;
};

void assign_sub(ref &x, std::string sub, int count) {
    std::cout << std::endl;
    std::cout << "~:: assign() : " << std::endl;
    std::cout << "\t-assigning: " << sub << std::endl;

    switch (count) {
        case 0:
            x.nr = sub;
            break;
        case 1:
            x.concept = sub;
            break;
        case 2:
            x.description = sub;
            break;
        case 3:
            x.short_label = sub;
            break;
        case 4:
            x.rel1 = sub;
            break;
        case 5:
            x.rel2 = sub;
            break;
        case 6:
            x.rel3 = sub;
            break;
        case 7:
            x.rel4 = sub;
            break;
        case 8:
            x.rel5 = sub;
            break;
        case 9:
            x.rel_string = sub;
            break;
        default:
            std::cout << std::endl;
            std::cout << "~:!:~ (error) no such element." << std::endl;
            std::cout << std::endl;
            break;
    };
    std::cout << "~:: done." << std::endl;
    std::cout << std::endl;
};

// eof