#include <iostream>

#include "FileParser.h"

FileParser::FileParser(std::string fileName) :
        inputFile(fileName) {}

FileParser::~FileParser() {}

uint32_t FileParser::parse() {
        std::ifstream file(inputFile);
        if (!file.is_open()) {
                std::cout << "Error: Couldn't open input file" << std::endl;
                return 0;
        }
        uint32_t res = parseFile(file);
        file.close();
        return res;
}
