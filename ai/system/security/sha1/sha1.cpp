
// SHA1.CPP: Save as "sha1.cpp" then compile with the following flags:
// -----
// Compiling:
// -----
// g++ -Wall -Wextra -Werror sha1.cpp -Lopenssl/openssl-0.9.8k/ -lssl -lcrypto -Iopenssl/openssl-0.9.8k/include
// -----

#include <openssl/sha.h> //For genrating Hash function
#include <fstream> // for reading file
#include <iostream>
#include <array>

std::string& getFile() {
	std::string *s = new std::string;
	s->reserve(1024);
	std::fstream fp;

	fp.open("ai/bin/runtime",std::ios::in);
	if(!(fp.is_open())){
		fprintf(stderr,"~!~ :: Unable to open the file; sha1.cpp\n");
		exit(EXIT_FAILURE);
	}
	else {
		std::string line;
		while(fp >> line){
			s->append(line);
		}
	}
	fp.close();
	return *s;
}

int main() {

	std::string *buffer = &(getFile());

	//std::cout << "Contents of file: " << std::endl;
	//std::cout << *buffer << std::endl;

	//Generating hash of the file
	std::array<unsigned char,SHA_DIGEST_LENGTH> digest;
	SHA_CTX ctx;

	//Initializing
	SHA1_Init(&ctx);
	SHA1_Update(&ctx,buffer->c_str(),buffer->size());
	SHA1_Final(digest.data(),&ctx);

	delete buffer;

	std::array<char,SHA_DIGEST_LENGTH * 2 +1> mdString;

	for(int i = 0 ; i < SHA_DIGEST_LENGTH ; ++i) {
		sprintf(&(mdString[i*2]),"%02x",(unsigned int)digest[i]);
	}

	fprintf(stdout,"\n(debug)\nHash: %s\n" ,mdString.data());

return 0;
}
