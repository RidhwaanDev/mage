#include <iostream>

#include "gapbuffer.h"

using namespace std;

int main() {
    GapBuffer buffer(40);
    buffer.insert("h");
    buffer.printBuffer();
    return 0;
}
