//
// Created by Ridhwaan Anayetullah on 5/14/20.
//

#ifndef MAGE_GAPBUFFER_H
#define MAGE_GAPBUFFER_H

#include <string>
#include <iostream>


#define GAP '_';

using string = std::string;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

class GapBuffer {
public:
    GapBuffer(int len) : gap_start(0), gap_end(len - 1), gap_len(gap_end - gap_start) {
        string buf(len, '_');
        buffer = buf;
    }

    friend std::ostream& operator<<(std::ostream& os, const GapBuffer& buffer);

    void insert(string text);
    void erase(int amount);
    void move(Direction d, int amount);
    void printBufferPtrs();
    string printBuffer() const;

private:
    string buffer;
    int gap_start;
    int gap_end;
    int gap_len;

};

#endif //MAGE_GAPBUFFER_H
