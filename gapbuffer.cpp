//
// Created by Ridhwaan Anayetullah on 5/14/20.
//

#include "gapbuffer.h"
#include <string>


// the cursor should always be at the start of the gap

void GapBuffer::insert(string text){
    if(text.size() > gap_len){
        // grow the gap
    } else {
        // do the actual insertion
        buffer.replace(gap_start, text.size(), text);
        // move gap start up
        gap_start += text.size();
    }
}

// backspace erase
void GapBuffer::erase(int amount){
 // just move the gap start back
 if(gap_start <= 0){
     return;
 }
 while(amount > 0){
     gap_start = gap_start - 1;
     buffer[gap_start] = GAP;
     amount = amount - 1;
 }
}

std::ostream& operator<<(std::ostream& os, const GapBuffer& gb){
   for(int i = 0; i < gb.gap_start; i++){
       os << gb.buffer[i];
   }
    for(int i = gb.gap_end + 1; i < gb.buffer.size(); i++){
        os << gb.buffer[i];
    }
    return os;
}

void GapBuffer::printBufferPtrs(){
    std::cout << std::endl;
    std::cout << "gap_start " << gap_start << std::endl;
    std::cout << "gap_end " << gap_end << std::endl;
    std::cout << "gap_len " << gap_len << std::endl;
    std::cout << "buffer_len " << buffer.size() << std::endl;
}
// moves the cursor
void GapBuffer::move(Direction d, int amount = 1){
    switch(d){
        case RIGHT:
            if (gap_end >= buffer.size() - 1)
                return;
            // he...llo
            //   ^ ^
            // hel...lo
            // move the cursor right copying elements from the right into the left
                while(amount > 0) {
                if (gap_end != buffer.size() - 1) {
                    buffer[gap_start] = buffer[gap_end + 1];
                    buffer[gap_end + 1] = GAP;
                    gap_start  = gap_start + 1;
                    gap_end = gap_end + 1;
                }
                amount = amount - 1;
            }
            break;
        case LEFT:
            if(gap_start <= 0){
                return;
            }
            // he...llo
            //   ^ ^
            // h...ello
            while(amount > 0) {
                if (gap_start > 0) {
                    buffer[gap_end] = buffer[gap_start - 1];
                    buffer[gap_start - 1] = GAP;
                    gap_start = gap_start -  1;
                    gap_end = gap_end -  1;
                }
                amount = amount - 1;
            }
            break;
        case UP:
            break;
        case DOWN :
            break;
    }
}


string GapBuffer::printBuffer() const {
    std::cout << buffer << std::endl;
    return buffer;
}



