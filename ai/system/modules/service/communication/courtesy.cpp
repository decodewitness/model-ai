// AI/SYSTEM/MODULES/SERVICE/COMMUNICATION/COURTESY.CPP -   USED BY "AI/SYSTEM/MODULES/SERVICE/SERVICE.CPP"

/* Courtesy
* 
* 1. the showing of politeness in one's attitude and behaviour towards others.
*    "he treated the players with courtesy and good humour"
*    Similar: politeness courteousness good manners civility respect
* 2. ARCHAIC
*   (a curtsy)
*/

#include <iostream>
#include <string>
#include <string.h>
// #include <

char protocols[5][16] = { "xml-data", "http-data", "https-data", "ftp-data", "www-data" };
char languages[11][16] = { "robot", "english", "german", "french", "russian", "dutch", "chinese", "japanese", "korean", "greek", "portugese" };

class Courtesy { // acts as filter for peer or device
private:

    int peers;  // number of peers in communication

    bool areFriend; // are speaking with authorized figure
    bool arePeer; // are speaking with anyone
    bool arePeerRelation; // peer referral to peer or device
    bool areDevice; // peer is device
    bool arePerson; // peer is a person
    bool areRobot;  // peer is a robot
    bool areTalking; // in communication
    bool areTalkingWithRobot; // peer (or friend)
    bool areTalkingWithPerson; // peer (or friend)
    bool areTalkingWithURL; // peer (or trusted domain)
    bool areTalkingWithFriend; // communication
    bool areTalkingWithDevice; // communication
    bool areTalkingWithPeer; // peer device in communication // mutual exchange // xml-data
    
    bool isTrustedDomain; // domain is trusted
    bool isSecure; // has tunnel encryption
    bool isInsecure; // lacks encryption

    bool hasCertificate; // certificate exchange
    bool hasPeerCertificate; // has peer certificate (Model-Ai certificate)
    bool vipCertificate; // Model-Ai vip certificate (Model-Ai certificate)
    bool hasSSLCertificate; // Secure Socket Layer (SSL) certificate
    bool hasPublicKey; // crypto three way handshake
    bool hasMyPublicKey; // authorization // verification by third handshake

    // bool areSearchingSubject; //
    // bool areFindingTopic; //
    // bool areRewardedForEffort; //
    
    int prot;   // protocol for devices
    int lang;   // language for peers
    int levelOfIntimacy; // for friends

    std::string language;   // speech language
    std::string protocol;   // propagation

public:
    Courtesy();
    ~Courtesy() {};

    int doHandshake(std::string peer);
    int sendAck() { /*ACK*/ return 1; };
    int sendSyn() { /*SYN*/ return 1; };
    int sendRst() { /*RST*/ return 1; };
    int sendNop() { /*NOP*/ return 1; };

    void switchLang(std::string lang);
    void switchProt(std::string prot);

    void switchLanguage(int n);
    void switchProtocol(int n);
};


Courtesy::Courtesy() {    // main constructor function for the Courtesy class
    // set initial protocol
        // could scan from "bay" or ""
    this->prot = 0;
    this->protocol = "xml-data";

    // set language instructions
    this->lang = 1;
    this->language = "english";

    // initialization
    this->peers = 0;
};

int Courtesy::doHandshake(std::string peer) {   // three-way-handshake
    return 1;
};

void Courtesy::switchProtocol(int n) {
    this->prot = n;
    this->protocol = protocols[n];
};

void Courtesy::switchLanguage(int n) {
    this->lang = n;
    this->language = languages[n];
};

void Courtesy::switchProt(std::string prot){
    for (size_t t=0; t<5; t++) {
        if (strncmp(protocols[t],prot.c_str(), 16) == 0) {
            this->prot = t;
            this->protocol = prot;
        } else {
            std::cout << "(!) - (error) no matching protocol!" << std::endl;
        }
    }
};

void Courtesy::switchLang(std::string lang) {
    for (size_t t=0; t<5; t++) {
        if (strncmp(languages[t],lang.c_str(), 16) == 0) {
            this->lang = t;
            this->language = lang;
        } else {
            std::cout << "(!) - (error) no matching protocol!" << std::endl;
        }
    }
};

// eof