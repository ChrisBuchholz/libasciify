/**
  * This file is part of libasciify.
  *
  * libasciify is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * libasciify is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with libasciify. If not, see <http://www.gnu.org/licenses/>.
  **/

/**
  * authors:
  *     ChrisBuchholz <http://chrisbuchholz.dk>
  **/

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
        file << l.getAscii();
        file.close();
    }
	return 0;
}
