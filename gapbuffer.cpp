//
// Created by Ridhwaan Anayetullah on 5/14/20.
//

#include "gapbuffer.h"
#include <string>


// the cursor should always be at the start of the gap

void GapBuffer::insert(string text ){
    if(text.size() > gap_len){
        // grow();
    } else {
        // do the actual insertion
        buffer.replace(gap_start, text.size(), text);
        // move gap start up
        gap_start += text.size();
        // move cursor
        cursor_pos = gap_start;
    }
}


string GapBuffer::printBuffer(){
    std::cout << buffer;
    return buffer;
}



