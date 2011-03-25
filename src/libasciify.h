#ifndef LIBASCIIFY_H
#define LIBASCIIFY_H

#include <iostream>
#include <vector>

class libasciify {
    public:
        libasciify(std::string);
        std::string getAscii();
        bool isProcessing();
        int getProgress();

    protected:
        void updateProgress(int, int, int, int);
        std::vector<std::string> grayscale_chars;
        std::vector<int> grayscale_bounds;
        std::string ascii_str;
        bool is_processing;
        int current_progress; // percentage

};

#endif
