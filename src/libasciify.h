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
  *     ChrisBuchholz <http://chrisbuchholz.me/>
  **/

#ifndef LIBASCIIFY_H
#define LIBASCIIFY_H

#include <iostream>
#include <vector>

class Monitor {
    public:
        virtual void update(int) = 0;
};

class libasciify {
    public:
        libasciify(std::string);
        libasciify(std::string, Monitor*);
        std::string getAscii();
        bool isProcessing();
        int getProgress();

    protected:
        Monitor *m_callee;
        std::string filename;
        void process(bool);
        void updateProgress(int, int, int, int);
        std::vector<std::string> grayscale_chars;
        std::vector<int> grayscale_bounds;
        std::string ascii_str;
        bool is_processing;
        int current_progress; // percentage
};

#endif
