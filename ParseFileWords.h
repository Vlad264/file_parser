#ifndef _PARSE_FILE_WORDS_H_
#define _PARSE_FILE_WORDS_H_

#include "FileParser.h"

class ParseFileWords : public FileParser<uint32_t> {
public:
    ParseFileWords(std::string fileName, std::string word);
    ~ParseFileWords();

protected:
    uint32_t parseFile(std::ifstream &file);

private:
    std::string inputWord;
};

#endif //_PARSE_FILE_WORDS_H_
