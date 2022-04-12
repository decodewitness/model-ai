#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string nref_store_file = "ai/lib/queries/refs";

struct nref {
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

void store_nref(nref x) {
    std::ofstream store;

    std::cout << std::endl;
    std::cout << "~:: store_nrefs() :" << std::endl;

    store.open(nref_store_file, std::ios::app);

    if (store.is_open() == true) {
        std::cout << "\t~:: storing nrefs." << std::endl;

        // store nref data
        store << "\"" << x.nr << "\"";
        store << ",";
        store << "\"" << x.concept << "\"";
        store << ",";
        store << "\"" << x.description << "\"";
        store << ",";
        store << "\"" << x.short_label << "\"";
        store << ",";
        store << "\"" << x.rel1 << "\"";
        store << ",";
        store << "\"" << x.rel2 << "\"";
        store << ",";
        store << "\"" << x.rel3 << "\"";
        store << ",";
        store << "\"" << x.rel4 << "\"";
        store << ",";
        store << "\"" << x.rel5 << "\"";
        store << ",";
        store << "\"" << x.rel_string << "\"";
        store << ";" << std::endl;

        // close file      
        store.close();
    } else {
        std::cout << std::endl;
        std::cout << "~:!:~ (error) - nrefs file not open." << std::endl;
    }

    if (store.is_open() == false) {
        std::cout << "~:: stored nrefs." << std::endl;
    }
};

nref read_nrefs(std::string filename, int nr=0) {  // filename with nrefs ;; nr of nref
    // positions in string
    int pos=0;    // first position of char elements
    int pos2=0;   // second position of char elements
    int pos3=0;
    
    // counter
    int i=0;
    
    // file streams
    std::ifstream file; // file stream

    // strings
    std::string str;    // used for lines of "filename"
    std::string s;  // used as temp var for units in "str"

    // references
    nref x;  // temp reference structure

    // function prototypes
    void assign_sub(nref &x, std::string sub, int count);    // function that assigns to the temporary reference

    // function read_nrefs()
    std::cout << std::endl;
    std::cout << "~:: read_nrefs() :" << std::endl;

    file.open(filename);

    if (file.is_open() == true) {
        std::cout << "\t~:: opened nrefs file." << std::endl;

        while (getline(file, str)) {
            std::cout << "\t\t~:: process nref[] ::" << std::endl;
            std::cout << "\t\t\t" << str << std::endl;
            std::cout << std::endl;
  
            // std::stringstream ss(str);
            
            // find end of string
            pos3 = str.find_first_of(";");

            for (i=0; pos2 = str.find_first_of(",") + 1; i++) {
                if (i == 10) {
                    std::cout << std::endl;
                    std::cout << "~:!:~ (error) - anomaly ;; check your nrefs data on element size (max. 10)." << std::endl;
                    std::cout << std::endl;
                    break;
                }

                s = str.substr(pos, pos2);
                str.erase (pos,pos2);
                s.pop_back();

                std::cout << "\t\t" << i << ") sub : " << s << std::endl;
                std::cout << "\t\t\t~:: processed." << std::endl;
                std::cout << std::endl;

                // assign sub to x element i
                assign_sub(x, s, i);
            }
            // THIS IS ADDED FOR THE PREVIOUS LOOP ::
                // index the last element in the string str
            s = str.substr(pos, pos3 - 1);
            s.pop_back();
            std::cout << "\t\t" << i << ") sub : " << s << std::endl;
            std::cout << "\t\t\t~:: processed." << std::endl;
            std::cout << std::endl;
            // assign last sub element to x element i
            assign_sub(x, s, i);
        }
        // close file stream
        file.close();
    }
    std::cout << "~:: done processing nrefs." << std::endl;
    std::cout << std::endl;
return x;
};

void assign_sub(nref &x, std::string sub, int count) {
    // anounce function
    std::cout << std::endl;
    std::cout << "\t~:: assign() : " << std::endl;
    
    // anounce sub
    std::cout << "\t\tassigning: " << sub << std::endl;

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
    std::cout << "\t\t\t~:: done." << std::endl;
    std::cout << std::endl;
};

nref build_custom_nref() {
    // reference
    nref x;
    
    // anounce function
    std::cout << std::endl;
    std::cout << "~:: build_custom_nref() :" << std::endl;
    std::cout << std::endl;

    // read in reference
    std::cout << "nr : ";
    std::getline(std::cin, x.nr); // number of this reference
    std::cout << "concept : ";
    std::getline(std::cin, x.concept);    // name of this nref/concept
    std::cout << "description : ";
    std::getline(std::cin, x.description);    // summary or brief description of gained attributes
    std::cout << "short_label : ";
    std::getline(std::cin, x.short_label);    // short label for reference
    std::cout << "rel1 : ";
    std::getline(std::cin, x.rel1);   // relation 1
    std::cout << "rel2 : ";
    std::getline(std::cin, x.rel2);   // relation 2
    std::cout << "rel3 : ";
    std::getline(std::cin, x.rel3);   // relation 3
    std::cout << "rel4 : ";
    std::getline(std::cin, x.rel4);   // relation 4
    std::cout << "rel5 : ";
    std::getline(std::cin, x.rel5);   // relation 5
    std::cout << "rel_string : ";
    std::getline(std::cin, x.rel_string); // additional relations

return x;
};

void print_nref(nref x) {
    // anounce function
    std::cout << std::endl;
    std::cout << "~:: print_nref() :" << std::endl;
    std::cout << std::endl;

    // print reference
    std::cout << "\tnr : " << x.nr << std::endl; // number of this reference
    std::cout << "\tconcept : " << x.concept << std::endl;    // name of this ref/concept
    std::cout << "\tdescription : " << x.description << std::endl;    // summary or brief description of gained attributes
    std::cout << "\tshort_label : " << x.short_label << std::endl;    // short label for reference
    std::cout << "\trel1 : " << x.rel1 << std::endl;   // relation 1
    std::cout << "\trel2 : " << x.rel2 << std::endl;   // relation 2
    std::cout << "\trel3 : " << x.rel3 << std::endl;   // relation 3
    std::cout << "\trel4 : " << x.rel4 << std::endl;   // relation 4
    std::cout << "\trel5 : " << x.rel5 << std::endl;   // relation 5
    std::cout << "\trel_string : " << x.rel_string << std::endl; // additional relations
    
    // print newline character
    std::cout << std::endl;
};

// eof