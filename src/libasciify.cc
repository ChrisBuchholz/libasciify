#include "libasciify.h"
#include "CImg.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace cimg_library;

libasciify::libasciify(std::string filename) {
    // set is_processing to on before we continue
    this->is_processing = true;

    // create a map that defines tonal-level=>character
    // for the pixel conversion
    // this map corresponds to a grayscale image, not color
    std::map<int, char> grayscale_table;
    std::map<int, char>::iterator grayscale_pick;
    grayscale_table[15] = '.';
    grayscale_table[30] = ',';
    grayscale_table[60] = ';';
    grayscale_table[100] = 'j';
    grayscale_table[160] = 'E';
    grayscale_table[210] = 'W';
    grayscale_table[250] = 'K';
    
    // initiate string
    std::string str;

    // load image into cimg object
    CImg<unsigned char> image(filename.c_str()); // CImg depends on Imagemagick for
                                                 // loading some image types

    // scale image to thumbnail size
    // 96px in height
    // we do this by setting a basewidth and
    // then computing what percentage the
    // basewidth is of the original width,
    // and then multiplying the original
    // height by that percentage
    int width = 96;
    float wpercent = width / (float)image.width();
    int height = (float)image.height() * wpercent;
    image.resize(width, height);

    int x = 0,
        y = 0;

    // iterate over each vertical line in the image
    for(y = 0; y < height; y++) {
        this->updateProgress(width, height, x, y);
        // iterator over each pixel in the horizontal line 
        for(x = 0; x < width; x++) {
            this->updateProgress(width, height, x, y);
            // cimg object operator returns pixel value
            // located a x, y, z, v
            int r = (int)image(y, x, 0, 0),
                g = (int)image(y, x, 0, 1),
                b = (int)image(y, x, 0, 2);

            //float bw = (r+g+b)/3; // simple but not as precise
            float bw = (r * 0.3) + (g * 0.59) + (b + 0.11);
            
            // pick the horse, dumb dumb
            grayscale_pick = grayscale_table.lower_bound(bw);

            // second as in value (key=>value)
            str += (*grayscale_pick).second;
        }
        // newline
        str += "\n";
    }

    // set public member ascii string
    this->ascii_str = str;

    // set is_processing to false because it's done
    this->is_processing = false;
}

std::string libasciify::getAscii() {
    // returns the ascii string
    return this->ascii_str;
}

bool libasciify::isProcessing() {
    // return true if progress is running
    // false if not
    return this->is_processing;
}

void libasciify::updateProgress(int width, int height, int x, int y) {
    // calculate the process' progress by comparing
    // width and height (number of pixels) with x and y (how many pixels
    // has been processed)
    int total = width * height,
        current = x * y,
        progress = current * 100 / total;
    this->current_progress = progress;
}

int libasciify::getProgress() {
    // return current progress
    return this->current_progress;
}
