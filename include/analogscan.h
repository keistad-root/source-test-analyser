#ifndef ANALOGSCAN_H
#define ANALOGSCAN_H

#include "test.h"

class AnalogScan : public Tests {
private:
    std::string path;
    std::string file_contents;

public:
    AnalogScan(const std::string& _path);
    void decoder();
};

#endif