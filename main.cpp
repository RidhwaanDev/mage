#include <iostream>

#include "gapbuffer.h"

using namespace std;

int main() {
    GapBuffer buffer(40);
    buffer.insert("hello");
    buffer.move(LEFT,3);
    buffer.insert("hi");
    cout << buffer;
    buffer.printBufferPtrs();
    return 0;
}
