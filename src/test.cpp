#include "test.h"

std::string Tests::readFileIntoString(const std::string& path) {
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '" << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::string((std::istreambuf_iterator<char>(input_file)),
                       std::istreambuf_iterator<char>());
}

Voltage Tests::stoV(const std::string& str) {
    if (str == "VRESETP")
        return VRESETP;
    else if (str == "VRESETD")
        return VRESETD;
    else if (str == "VCASP")
        return VCASP;
    else if (str == "VCASN")
        return VCASN;
    else if (str == "VPULSEH")
        return VPULSEH;
    else if (str == "VPULSEL")
        return VPULSEL;
    else if (str == "VCASN2")
        return VCASN2;
    else if (str == "VCLIP")
        return VCLIP;
    else if (str == "VTEMP")
        return VTEMP;
    else if (str == "IAUX2")
        return IAUX2;
    else if (str == "IRESET")
        return IRESET;
    else if (str == "IDB")
        return IDB;
    else if (str == "IBIAS")
        return IBIAS;
    else if (str == "ITHR")
        return ITHR;
    else
        return NONAME;
}

std::string Tests::readRawFile(const std::string& path) {
    std::ifstream input_file(path, std::ios::binary);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file = '" << path << "'" << std::endl;
    }
    return std::string((std::istreambuf_iterator<char>(input_file)),
                       std::istreambuf_iterator<char>());
}