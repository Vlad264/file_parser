#ifndef _FILE_PARSER_H_
#define _FILE_PARSER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>

class FileParser {
public:
    FileParser(std::string fileName);
    ~FileParser();

    uint32_t parse();

protected:
    virtual uint32_t parseFile(std::ifstream &file) = 0;

private:
    std::string inputFile;
};

#endif //_FILE_PARSER_H_
