//
// Created by Ridhwaan Anayetullah on 5/14/20.
//

#ifndef MAGE_GAPBUFFER_H
#define MAGE_GAPBUFFER_H
#include <string>
#include <iostream>

using string = std::string;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

class GapBuffer {
public:
    GapBuffer(int len) : gap_start(0), gap_end(len), gap_len(gap_end - gap_start + 1), cursor_pos(0){
        string buf(len, '_');
        buffer = buf;
    }
    void insert(string text);
    void move(Direction d);
    void printBufferWithIndexPtrs();
    string printBuffer();

private:
    string buffer;
    int gap_start;
    int gap_end;
    int gap_len;
    int cursor_pos;

};

#endif //MAGE_GAPBUFFER_H
