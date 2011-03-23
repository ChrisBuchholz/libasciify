#include "libasciify.h"
#include <iostream>

int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        libasciify l(argv[i]);
        std::cout << "ascii_str: " << l.ascii_str << std::endl;
    }
	return 0;
}
