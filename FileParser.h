#ifndef _FILE_PARSER_H_
#define _FILE_PARSER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>

template <typename T>
class FileParser {
public:
    FileParser(std::string fileName);
    ~FileParser();

    T parse();

protected:
    virtual T parseFile(std::ifstream &file) = 0;

private:
    std::string inputFile;
};

#endif //_FILE_PARSER_H_
