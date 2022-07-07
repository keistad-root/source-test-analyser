#ifndef TESTS_H
#define TESTS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "/Users/yongjunchoi/Sources/root_build/include/TCanvas.h"
#include "/Users/yongjunchoi/Sources/root_build/include/TGraph.h"
#include "/Users/yongjunchoi/Sources/root_build/include/TH1.h"
#include "/Users/yongjunchoi/Sources/root_build/include/TStyle.h"
#include "/Users/yongjunchoi/Sources/root_build/include/TMultiGraph.h"

enum Voltage {
    VRESETP,
    VRESETD,
    VCASP,
    VCASN,
    VPULSEH,
    VPULSEL,
    VCASN2,
    VCLIP,
    VTEMP,
    IAUX2,
    IRESET,
    IDB,
    IBIAS,
    ITHR,
    NONAME
};


class Tests {
public:
    std::string readFileIntoString(const std::string& path);
    Voltage stoV(const std::string& str);
    std::string readRawFile(const std::string& path);
    virtual void printError() {}
    virtual void printGraph(int i) {}
    virtual void printGraph() {}
};

#endif