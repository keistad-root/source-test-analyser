#ifndef DACSCAN_H
#define DACSCAN_H

#include "test.h"

class DACScan : public Tests {
private:
    std::string filename;
    std::string file_contents;
    std::vector<int> vresetp;
    std::vector<int> vresetd;
    std::vector<int> vcasp;
    std::vector<int> vcasn;
    std::vector<int> vpulseh;
    std::vector<int> vpulsel;
    std::vector<int> vcasn2;
    std::vector<int> vclip;
    std::vector<int> vtemp;
    std::vector<int> iaux2;
    std::vector<int> ireset;
    std::vector<int> idb;
    std::vector<int> ibias;
    std::vector<int> ithr;
    std::vector<TGraph*> graph;

public:
    DACScan(std::string _filename) {
        filename = _filename;
        openFile();
    }
    void openFile();
    void insertVoltageToVector(const std::string& voltageKind,
                               int voltageValue);
    TGraph* drawGraph(std::vector<int>& arr);
    void printGraph();
};

#endif