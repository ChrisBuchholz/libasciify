#!/bin/bash

echo -e "running libasciify tests\n"

make

./build/main man_face.jpg

echo -e "--------------------\ntests done"
