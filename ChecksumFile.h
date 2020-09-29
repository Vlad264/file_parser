#ifndef _CHECKSUM_FILE_H_
#define _CHECKSUM_FILE_H_

#include "FileParser.h"

class ChecksumFile : public FileParser<uint32_t> {
public:
    ChecksumFile(std::string fileName);
    ~ChecksumFile();

protected:
    uint32_t parseFile(std::ifstream &file);
};

#endif //_CHECKSUM_FILE_H_
