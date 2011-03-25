#include "libasciify.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        std::string image_file = std::string(argv[i]);
        std::stringstream ss;
        ss << image_file << ".ascii";
        std::string ascii_file = ss.str();
        
        libasciify l(image_file);
        std::ofstream file(ascii_file.c_str());
        file << l.ascii_str;
        file.close();
    }
	return 0;
}
