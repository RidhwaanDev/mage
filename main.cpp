#include <iostream>

#include "gapbuffer.h"

using namespace std;

int main() {
    GapBuffer buffer(40);
    buffer.insert("hello");
    buffer.printBuffer();
    buffer.move(LEFT,3);
    buffer.printBuffer();
    buffer.move(RIGHT,3);
    buffer.printBuffer();
    buffer.printBufferPtrs();
    return 0;
}
