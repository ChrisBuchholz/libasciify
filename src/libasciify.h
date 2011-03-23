#ifndef LIBASCIIFY_H
#define LIBASCIIFY_H

#include <iostream>
#include <vector>

class libasciify {
    public:
        libasciify(std::string);
        // container of ascii
        std::string ascii_str;

    protected:
        std::vector<std::string> greyscale_chars;
        std::vector<int> greyscale_bounds;
};

#endif
