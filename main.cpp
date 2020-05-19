#include <iostream>
#include <ncurses.h>

#include "gapbuffer.h"
#include "file.h"

using namespace std;

int main() {
    GapBuffer buffer(20);
    GBFile::readFileIntoGapBuffer(buffer,"test.js");

    int ch;

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
    noecho();			/* Don't echo() while we do getch */
    // render loop
    while((ch = getch()) != 48){
        clear();
        char letter = (char) ch;
        buffer.insert(string(letter, 1));			/* If raw() hadn't been calle
					 * we have to press enter before it
					 * gets to the program 		*/
        attron(A_BOLD);
        printw(buffer.printBuffer().c_str());
        attroff(A_BOLD);
        refresh();			/* Print it on to the real screen */
    }
    endwin();			/* End curses mode		  */
    buffer.printBuffer();
    cout << buffer;

    return 0;
}
