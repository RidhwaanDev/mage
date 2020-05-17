#include <iostream>

#include "gapbuffer.h"

using namespace std;

int main() {
    GapBuffer buffer(10);
    buffer.insert("hello");
    buffer.printBuffer();
    buffer.move(LEFT,3);
    buffer.printBuffer();
    buffer.insert("aa");
    buffer.insert("bb");
    buffer.printBuffer();
    buffer.insert("GROW");
    buffer.insert("GROW2");
    buffer.move(LEFT,8);
    buffer.printBuffer();
    buffer.printBufferPtrs();
    return 0;
}
