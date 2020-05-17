//
// Created by Ridhwaan Anayetullah on 5/14/20.
//

#include "gapbuffer.h"
#include <string>
#include <dns_sd.h>


// the cursor should always be at the start of the gap
void GapBuffer::insert(string text){
    if(text.size() > getGapLength() || gap_start == gap_end){
        grow();
    }
        // do the actual insertion
        buffer.replace(gap_start, text.size(), text);
        // move gap start up
        gap_start += text.size();
}
// grow is called when text we want to insert into the gap is greater than the gap size
// grow gap size
void GapBuffer::grow(){
    string bigger_buffer(buffer.size()  * 2 , GAP);
    // text before gap
    for(int i = 0; i < gap_start; i++){
        bigger_buffer[i] = buffer[i];
    }

    // text after
    int backptr = 0;
    for(int i = buffer.size() - 1; i > gap_end ; i--){
        bigger_buffer[bigger_buffer.size() - 1 - backptr] = buffer[i];
        backptr++;
    }

    buffer = bigger_buffer;
    gap_end = bigger_buffer.size() - 1 - backptr;
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
    std::cout << "gap_len " << getGapLength() << std::endl;
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



