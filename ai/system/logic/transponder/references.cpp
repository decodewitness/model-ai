#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string stored_nrefs_file = "ai/lib/queries/references";

struct nref {
    std::string nr; // number of this reference
    std::string concept;    // name of this ref/concept
    std::string description;    // summary or brief description of gained attributes
    std::string short_label;    // short label for reference
    std::string rel_string; // additional relations
    std::string rel1;   // relation 1
    std::string rel2;   // relation 2
    std::string rel3;   // relation 3
    std::string rel4;   // relation 4
    std::string rel5;   // relation 5
};

void store_nref(nref x) {
    std::ofstream store;

    std::cout << std::endl;
    std::cout << "~:: store_nrefs() :" << std::endl;

    store.open(stored_nrefs_file, std::ios::app);

    if (store.is_open() == true) {
        // debugging output
        // std::cout << "\t~:: storing nrefs." << std::endl;

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

nref read_nrefs_from_file(std::string filename, int nr=0) {  // filename with nrefs ;; nr of nref
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
            if (str.compare("\n") == false) {
                continue;
            }

            if (str.length() > 0) {
                std::cout << "\t\t~:: process nref[] ::" << std::endl;
                std::cout << "\t\t\t: " << str << std::endl;
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
                    // std::cout << std::endl;

                    // assign sub to x element i
                    assign_sub(x, s, i);
                }
            } else {
                break;
            }
        }

        // if (s.length() > 0) {
        //     s = str.substr(pos, pos3 - 1);
        //     s.pop_back();
        //     std::cout << "\t\t" << i << ") sub : " << s << std::endl;
        //     std::cout << "\t\t\t~:: processed." << std::endl;
        //     // std::cout << std::endl;
        //     // assign last sub element to x element i
        //     assign_sub(x, s, i);
        //     // close file stream
        // }
    }
    if (file.is_open() == true) {
        file.close();
    }
 
    std::cout << "~:: done processing nrefs." << std::endl;
    std::cout << std::endl;
return x;
};

void assign_sub(nref &x, std::string sub, int count) {
    
    // debugging output
        // anounce function
    // std::cout << std::endl;
    // std::cout << "\t~:: assign() : " << std::endl;
    
    // debugging output
        // anounce sub
    // std::cout << "\t\tassigning: " << sub << std::endl;

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
    // debugging output
    // std::cout << "\t\t\t~:: done." << std::endl;
    // std::cout << std::endl;
};

nref build_custom_nref() {
    // reference
    nref x;
    
    // anounce function
    std::cout << std::endl;
    std::cout << "~:: building custom nref :" << std::endl;
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

nref return_nref(int x) {   // return nref structure "x"
    // ints
    int i;
    int n=0;
    int pos=0;
    int pos2=0;
    int pos3=0;
    
    // strings
    std::string line;
    std::string s;

    // file streams
    std::ifstream file;

    // temp reference structure
    nref y;

    file.open(stored_nrefs_file);

    // loop file
    if (file.is_open() == true) {
        while (std::getline(file, line)) {
            n++;

            if (n > x) {
                break;
            } else if (n < x) {
                continue;
            } else if (n == x && line.length() > 0) {
                // std::cout << "\t\t~:: process nref[] ::" << std::endl;
                // std::cout << "\t\t\t: " << line << std::endl;
                std::cout << std::endl;

                // std::stringstream ss(str);
                
                // find end of string
                pos3 = line.find_first_of(";");

                for (i=0; pos2 = line.find_first_of(",") + 1; i++) {
                    if (i == 10) {
                        std::cout << std::endl;
                        std::cout << "~:!:~ (error) - anomaly ;; check your nrefs data on element size (max. 10)." << std::endl;
                        std::cout << std::endl;
                        break;
                    }

                    s = line.substr(pos, pos2);
                    line.erase (pos,pos2);

                    if (s.length() > 0) {
                        s.pop_back();
                    }

                    // std::cout << "\t\t" << i << ") sub : " << s << std::endl;
                    // std::cout << "\t\t\t~:: processed." << std::endl;
                    // std::cout << std::endl;

                    // assign sub to x element i
                    assign_sub(y, s, i);
                }
                // THIS IS ADDED FOR THE PREVIOUS LOOP ::
                    // index the last element in the string str
            }

            s = line.substr(pos, pos3 - 1);

            if (s.length() > 0) {
                s.pop_back();
                // std::cout << "\t\t" << i << ") sub : " << s << std::endl;
                // std::cout << "\t\t\t~:: processed." << std::endl;
                // assign last sub element to x element i
                assign_sub(y, s, i);
                // close file stream
            }
        }

        // close the file
        file.close();
    }
return y;
};

nref construct_ref(std::string nr, std::string concept, std::string description, std::string short_label, std::string rel1, std::string rel2, std::string rel3, std::string rel4, std::string rel5, std::string rel_string) {

    nref x;

    // todo CHECK for STRINGS HERE!!!
    x.nr = nr;
    x.concept = concept;
    x.description = description;
    x.short_label = short_label;
    x.rel_string = rel_string;
    x.rel1 = rel1;
    x.rel2 = rel2;
    x.rel3 = rel3;
    x.rel4 = rel4;
    x.rel5 = rel5;

return x;
};
    // // print reference
    // std::cout << "\tnr : " << x.nr << std::endl; // number of this reference
    // std::cout << "\tconcept : " << x.concept << std::endl;    // name of this ref/concept
    // std::cout << "\tdescription : " << x.description << std::endl;    // summary or brief description of gained attributes
    // std::cout << "\tshort_label : " << x.short_label << std::endl;    // short label for reference
    // std::cout << "\trel1 : " << x.rel1 << std::endl;   // relation 1
    // std::cout << "\trel2 : " << x.rel2 << std::endl;   // relation 2
    // std::cout << "\trel3 : " << x.rel3 << std::endl;   // relation 3
    // std::cout << "\trel4 : " << x.rel4 << std::endl;   // relation 4
    // std::cout << "\trel5 : " << x.rel5 << std::endl;   // relation 5
    // std::cout << "\trel_string : " << x.rel_string << std::endl; // additional relations
    
    // // print newline character
    // std::cout << std::endl;

void read_last_ref() {
    // chars
    char ch;

    // strings
    std::string lastLine;            
    
    // file pointers
    std::ifstream file;

    std::cout << std::endl;
    std::cout << "~:: read_last_ref() : " << std::endl;

    file.open(stored_nrefs_file);
    
    if(file.is_open()) {
        file.seekg(-1, std::ios_base::end);                // go to one spot before the EOF

        bool keepLooping = true;
        while(keepLooping) {
            file.get(ch);                            // Get current byte's data

            if((int)file.tellg() <= 1) {             // If the data was at or before the 0th byte
                file.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if(ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                file.seekg(-2, std::ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }

        std::getline(file,lastLine);                      // Read the current line

        std::cout << "~::\t* nref sequence : " << lastLine << std::endl;     // Display it
        std::cout << std::endl;

        if (file.is_open() == true) {
            file.close();
        }
    }
};


int return_last_ref_nr() {  // returns the number of lines
    int x=0;
    std::string line;
    std::ifstream file;
    
    file.open(stored_nrefs_file);

    // loop over file
    if (file.is_open() == true) {
        while (getline(file, line)) {
            x++;
        }
    }

  return x;  
};
// eof