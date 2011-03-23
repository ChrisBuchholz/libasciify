#include "libasciify.h"
#include <iostream>
#include <vector>

libasciify::libasciify(std::string filename) {
    std::string greyscale_chars_con = ".,;jEWK"; 
    greyscale_chars.push_back(greyscale_chars_con);
    int greyscale_bounds_arr[] = {15, 30, 60, 100, 160, 210, 250}; 
    greyscale_bounds.assign(greyscale_bounds_arr, greyscale_bounds_arr+sizeof(greyscale_bounds_arr)/sizeof(int));
    this->ascii_str = "something something";
}
