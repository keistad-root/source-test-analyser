#include "fifotest.h"

void FifoTest::openFile() {
    file_contents = readFileIntoString(filename);
}

void FifoTest::printError() {
    size_t nPos = file_contents.find("Done");
    if (file_contents.substr(nPos, 29) == "Done. FIFO test prime passed.")
        std::cout << "fifo test 이상없음" << std::endl;
    else
        std::cout << "fifo test 이상있음" << std::endl;
}
