#include <iostream>

#include "gapbuffer.h"
#include "file.h"

using namespace std;

int main() {
    GapBuffer buffer(2);
    GBFile::readFileIntoGapBuffer(buffer,"test.js");
    buffer.printBuffer();
    buffer.printBufferPtrs();
    return 0;
}
