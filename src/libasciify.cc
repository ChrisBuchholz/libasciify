#include "libasciify.h"
#include "CImg.h"
#include <iostream>
#include <string>
#include <map>

using namespace cimg_library;

libasciify::libasciify(char* filename) {
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
    CImg<unsigned char> image(filename); // CImg depends on Imagemagick for
                                         // loading some image types

    // scale image to thumbnail size
    // 96px in height
    // we do this by setting a basewidth and
    // then computing what percentage the
    // basewidth is of the original width,
    // and then multiplying the original
    // height by that percentage
    int basewidth = 96;
    float wpercent = basewidth / (float)image.width();
    int hsize = (float)image.height() * wpercent;
    image.resize(basewidth, hsize);

    // iterate over each vertical line in the image
    for(int h = 0; h < hsize; h++) {
        // iterator over each pixel in the horizontal line 
        for(int w = 0; w < basewidth; w++) {
            // cimg object operator returns pixel value
            // located a x, y, z, v
            int r = (int)image(h, w, 0, 0),
                g = (int)image(h, w, 0, 1),
                b = (int)image(h, w, 0, 2);

            //float bw = (r+g+b)/3; // simple but not as precise
            float bw = (r * 0.30) + (g * 0.59) + (b + 0.11);
            
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
}
