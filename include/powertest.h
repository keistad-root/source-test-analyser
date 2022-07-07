#ifndef POWERTEST_H
#define POWERTEST_H

#include "test.h"

class PowerTest : public Tests {
private:
    std::string filename;
    std::string file_contents;
    std::vector<float> analogVoltage;
    std::vector<float> digitalVoltage;
    float analogVoltageMin;
    float analogVoltageMax;
    float digitalVoltageMin;
    float digitalVoltageMax;

public:
    PowerTest(std::string _filename) {
        filename = _filename;
        openFile();
        findMinMaxValues();
    }
    void openFile();
    void findMinMaxValues();
    bool isErrorPowerTest();
    void printError();
    void printGraph(int binNumber);
};

#endif