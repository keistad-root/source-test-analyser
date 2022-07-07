#ifndef FIFOTEST_H
#define FIFOTEST_H

#include "test.h"

class FifoTest : public Tests {
private:
    std::string filename;
    std::string file_contents;

public:
    FifoTest(std::string _filename) {
        filename = _filename;
        openFile();
    }
    void openFile();
    void printError();
};

#endif