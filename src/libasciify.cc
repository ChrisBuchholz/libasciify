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
  *     ChrisBuchholz <http://chrisbuchholz.me>
  **/

                                    #include "libasciify.h"
#include "CImg.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace cimg_library;

libasciify::libasciify(std::string filename) {
    this->current_progress = 0;
    this->filename = filename;
    this->process(false);
}

libasciify::libasciify(std::string filename, Monitor *callee) {
    this->current_progress = 0;
    this->m_callee = callee;
    this->filename = filename;
    this->process(true);
}

void libasciify::process(bool isMonitoring) {
    // set is_processing to on before we continue
    this->is_processing = true;

    // create a map that defines tonal-level=>character
    // for the pixel conversion
    // this map corresponds to a grayscale image, not color
    std::map<int, char> grayscale_table;
    std::map<int, char>::iterator grayscale_pick;
    grayscale_table[0] = ' ';
    grayscale_table[25] = '.';
    grayscale_table[50] = '-';
    grayscale_table[100] = '+';
    grayscale_table[150] = '=';
    grayscale_table[190] = '0';
    grayscale_table[220] = '@';
    grayscale_table[255] = '#';

    /*grayscale_table[0] = ' ';
    grayscale_table[28] = '.';
    grayscale_table[56] = '^';
    grayscale_table[84] = '-';
    grayscale_table[114] = '|';
    grayscale_table[142] = '+';
    grayscale_table[170] = '=';
    grayscale_table[198] = 'O';
    grayscale_table[226] = '@';
    grayscale_table[255] = '#';*/

    // initiate string
    std::string str;

    // load image into cimg object
    CImg<unsigned char> image(this->filename.c_str()); // CImg depends on Imagemagick for
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
        // iterate over each pixel in the horizontal line 
        for(x = 0; x < width; x++) {
            // if isMonitoring true, call the
            // update-progressor function
            if(isMonitoring) {
                this->updateProgress(width, height, x, y);
            }

            // cimg object operator returns pixel value
            // located a x, y, z, v
            int r = (int)image(x, y, 0, 0),
                g = (int)image(x, y, 0, 1),
                b = (int)image(x, y, 0, 2);

            //float bw = (r+g+b)/3; // simple but not as precise
            float bw = (r * 0.30) + (g * 0.59) + (b * 0.11);

            // pick the horse, dumb dumb
            grayscale_pick = grayscale_table.lower_bound(bw);

            // second as in value (key=>value)
            str += (*grayscale_pick).second;

        }
        // newline
        str += "\n";
    }
    
    // release memory
    //grayscale_table.erase(grayscale_pick);

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
    width = width - 1;
    height = height - 1;
    int total = width * height,
        current = x + (y * width),
        overall = current * 100 / total;
    this->current_progress = overall;
    this->m_callee->update(overall);
}

int libasciify::getProgress() {
    // return current progress
    return this->current_progress;
}
