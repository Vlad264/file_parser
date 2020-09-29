#include "ParseFileWords.h"

ParseFileWords::ParseFileWords(std::string fileName, std::string word) : 
        FileParser(fileName),
        inputWord(word) {}

ParseFileWords::~ParseFileWords() {}

uint32_t ParseFileWords::parseFile(std::ifstream &file) {
    uint32_t sum = 0;
    std::string word;
    while (file >> word) {
        if (word == inputWord) {
            ++sum;
        }
    }
    return sum;
}
