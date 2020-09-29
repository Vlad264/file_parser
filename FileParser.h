#ifndef _FILE_PARSER_H_
#define _FILE_PARSER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <stdexcept> 

template <typename T>
class FileParser {
public:
    FileParser(std::string fileName) : inputFile(fileName) {};
    ~FileParser() {};

    T parse();

protected:
    virtual T parseFile(std::ifstream &file) = 0;

private:
    std::string inputFile;
};

template <typename T>
T FileParser<T>::parse() {
        std::ifstream file(inputFile);
        if (!file.is_open()) {
                throw std::invalid_argument("Error: Couldn't open input file");
        }
        T res = parseFile(file);
        file.close();
        return res;
}

#endif //_FILE_PARSER_H_
