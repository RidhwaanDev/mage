//
// Created by Ridhwaan Anayetullah on 5/19/20.
//

#ifndef MAGE_WINDOW_H
#define MAGE_WINDOW_H

#include <string>

class Screen;

// represents a window in the editor
class Window {

public:
    Window(int _width , int _height) : width(_width), height(_height) {}
    void drawContents(const Screen& screen);
private:
    int width;
    int height;
    std::string window_contents;
};


#endif //MAGE_WINDOW_H
