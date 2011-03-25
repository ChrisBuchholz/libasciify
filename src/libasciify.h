#ifndef LIBASCIIFY_H
#define LIBASCIIFY_H

#include <iostream>
#include <vector>

class libasciify {
    public:
        libasciify(std::string);
        // ascii string
        std::string ascii_str;

    protected:
        std::vector<std::string> grayscale_chars;
        std::vector<int> grayscale_bounds;
};

#endif
