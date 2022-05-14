// AI/FUNC.H    -   USED BY "AI/AI.H"

#include <vector>

// vectors
std::vector<std::string> ev;

// function collusion() ;; takes data from other functions and stores it in public <vector> ev.
void collusion(std::string& ref) {
    std::cout << std::endl;
    std::cout << "~:: collusion()." << std::endl;
    ev.push_back(ref);
};

// function readref()   ;;  reads out ev <vector>
void readref() {
    if (ev.size() > 0) {
        std::cout << "~:: readref() :" << std::endl;
        for (auto &ref : ev) {
            std::cout << ":: " << ref << std::endl;
        }
        std::cout << std::endl;
    }
}