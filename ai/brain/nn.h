#include "nlp/brain.cpp"

std::string Brain::sorter(std::string st, int level) {

    std::string combined;
    std::cout << "~:: debug :: sorter()." << std::endl;

    //this->search(query_string, 3);
    std::cout << "\t~:: sorter() :: " << this->search_index_code(st) << std::endl;

    // combine label

    combined = ">> ";

    return combined;
};

// std::string Brain::sorter(std::string st, int level) {

//     std::cout << "~:: debug :: sorter()." << std::endl;

//     // std::string combined = st;
//     std::string combined = "sorter :: needs \"combine\".";
//     std::string word;
//     std::string line;
//     int counter=0;
//     int line_count=0;

//     // close this.access file
//     if (this->access.is_open() == true) {
//         this->access.close();
//     }
    
//     // file access to data
//     this->file_access(3);
//     this->data.seekg(SEEK_SET);

//     if (this->data.is_open() == true) {
//         std::cout << std::endl << "- (debug)::sorter() data is open." << std::endl;
//     } else {
//         std::cout << std::endl << "- (debug)::sorter() Error! data DID NOT open." << std::endl;
//     }

//     while (std::getline(data, line)) { line_count++;};
    
//     if (this->data.is_open()) {
//         this->data.close();
//     }
//     file_access(3);
//     data.seekg(SEEK_SET);

//     for (int i=0; i<line_count; i++) {
//         //this->data >> word;
        
//         // debug
//         std::cout << std::endl << "(debug): line_count: << " << line_count << std::endl;

//         // read rest of line here
//         std::getline(data, line);

//         // debug section (std::cout ;; sleep(1))
//         //std::cout << line << std::endl;
//         //sleep(1);
        
//         stringstream iss(line);
        
//         while (iss >> word) {
//             cout << word << endl;
//         }

//         // continue
//         if (word.compare(st) == 0) {
//             std::cout << std::endl << ">> hit(" << i << ")" << std::endl;
//             counter++;

//             // do logic
//             //this->store_reference(line);    // stores the line in temporary catalogue or vector

//             // give option
//             std::cout << line << std::endl;
//             sleep(1);

//             combined = st + " :-L|| ";
//             combined = combined + line;
//         }
//     }   

//     return combined;
// };
    // this->data >> word;
    // this->data >> line;
    
    // std::cout << "debug )))---> st=" << st << " word=" << word << " line=" << line << std::endl;

    // if (word.compare(st) == 0) {    // needs string
    //     std::cout << " hit("; //<< i << ")";
    //     //counter++;

    //     // do logic
    //     this->store_reference(line);    // stores the line in temporary catalogue or vector

    //     // give option
    //     std::cout << line << std::endl;
    //     sleep(1);
    // }

    // combined = "!:1)";
    // combined = combined + word;
    // combined = combined + line;

//     return combined;
// };

    // need data
        // lookup word
    // for (int i=0; i<4; i++) {

    //     // needs fix
    //     this->data >> word;
    //     std::getline(data, line);
            
    //     if (word.compare(st) == false) {
    //         // this->data >> word;
    //         // this->data >> line;
    //         std::cout << "~:: debug (sorter):cmp flag = false" << std::endl;
    //     }
        
    //     if (word.compare(st) == true) {
    //         std::cout << "~:: debug (sorter):cmp flag = true" << std::endl;
    //     }

    //     if (word.compare("eot") == false) {
    //         // debugging output
    //         std::cout << "~:: debug (sorter) : " << std::endl;
    //         std::cout << "\t" << word << std::endl;
    //         std::cout << "\t" << line << std::endl;
    //     } else {
    //         break;
    //     }
    // }
   
    //this->search_index_code(word, line, level);
        // lookup tab or sentence
        // lookup data maybe in another function
    
    // set total and return value
    // st = combined;

//     return combined;
// };

std::string Brain::string_next_logic(std::string ssh) {
    // std::string sorter(std::string st, int level);
    
    std::string ss = "string_next_logic() :: ";
    // ss = ssh;
    
    // 1st layer in neural net
    std::string hmac = this->sorter(ssh, 1);
    // 2nd layer in neural net
    
    // debugging
    std::cout << ss << " ssh: " << ssh << std::endl;
    
    
    //std::string chmac = search_index_code(hmac);
    
    ss.append(hmac);
    // ss.append(" ");
    ss.append(ssh);
    ss.append(" is ");

    //ss.append(", ");
    //ss.append(chmac);

    return ss;
};

void Brain::neural_net(std::string s, std::string h="h", int cumulator=1) {   // acts like a neural net

    std::string hmac = string_next_logic(s);
    std::cout << std::endl << "HMAC : " << hmac << std::endl << std::endl;

    this->search(query_string, 7);

    // for (int i=0; i<cumulator; i++) {
        // hmac.append(string_next_logic(s));
        // hmac.append(search_index_code(s));
        //hmac.append(string_next_logic(s));
        //hmac.append(string_next_logic(h));
    // }
};
