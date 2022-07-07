#include "analogscan.h"

AnalogScan::AnalogScan(const std::string& _path) {
    path = _path;
    file_contents = readRawFile(path);
}

void AnalogScan::decoder(){
    
}