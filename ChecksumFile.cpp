#include "ChecksumFile.h"

ChecksumFile::ChecksumFile(std::string fileName) : FileParser(fileName) {}

ChecksumFile::~ChecksumFile() {}

uint32_t ChecksumFile::parseFile(std::ifstream &file) {
    uint32_t sum = 0;
    uint32_t word = 0;
    while (file.read(reinterpret_cast<char *> (&word), sizeof(word))) {
        sum += word;
        word = 0;
    }

    sum += word;
    return sum;
}
