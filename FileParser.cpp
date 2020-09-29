#include <iostream>

#include "FileParser.h"

template class FileParser<uint32_t>;

template <typename T>
FileParser<T>::FileParser(std::string fileName) : inputFile(fileName) {}

template <typename T>
FileParser<T>::~FileParser() {}

template <typename T>
T FileParser<T>::parse() {
        std::ifstream file(inputFile);
        if (!file.is_open()) {
                std::cout << "Error: Couldn't open input file" << std::endl;
                return 0;
        }
        T res = parseFile(file);
        file.close();
        return res;
}
