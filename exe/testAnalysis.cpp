#include "test.h"
#include "powertest.h"
#include "fifotest.h"
#include "dacscan.h"
#include "analogscan.h"
#include <vector>

int main() {
    std::vector<Tests*> r;
    // r.push_back(new PowerTest("Data/chip1/0Vbb/power-20220620_134659.txt"));
    // r.push_back(new FifoTest("Data/chip1/0Vbb/fifo-20220620_134710.txt"));
    r.push_back(new DACScan("Data/chip1/0Vbb/dacscan-20220620_135039.txt"));
    
    // r[0]->printError();
    // r[1]->printError();
    // r[0]->printGraph(20);
    r[0]->printGraph();
}