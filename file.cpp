//
// Created by Ridhwaan Anayetullah on 5/17/20.
//

#include <fstream>
#include <iostream>
#include "file.h"

FileIOStatus GBFile::readFileIntoGapBuffer(GapBuffer &buffer, const std::string& filename) {
    string line;
    std::ifstream file(filename);
    if(file.is_open()){
      while(getline(file,line)){
           buffer.insert(line);
      }
    } else {
        return ERROR;
    }
}

FileIOStatus GBFile::writeGapBufferToFile(const GapBuffer &buffer, const std::string &filename) {

}




