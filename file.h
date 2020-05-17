//
// Created by Ridhwaan Anayetullah on 5/17/20.
//

#ifndef MAGE_FILE_H
#define MAGE_FILE_H

#include "gapbuffer.h"

// handles FILE i/o for GapBuffer
enum FileIOStatus{
   ERROR,
   SUCCESS,
   IDEK
};

namespace GBFile {
    FileIOStatus readFileIntoGapBuffer(GapBuffer& buffer, const std::string& filename);
    FileIOStatus writeGapBufferToFile(const GapBuffer& buffer, const std::string& filename);
}

#endif //MAGE_FILE_H
