#include <iostream>

#include "CommandLineParser.h"
#include "ChecksumFile.h"
#include "ParseFileWords.h"

int main(int argc, char *argv[]) {
    CommandLineParser commandLineParser;
    CommandLineParser::returnStatus_t ret = commandLineParser.parse(argc, argv);
    switch (ret) {
        case CommandLineParser::WORDS: {
                ParseFileWords wordNumber(commandLineParser.getInputFile(), commandLineParser.getInputWord());
                std::cout << "Number of \"" << commandLineParser.getInputWord()<< "\": " << wordNumber.parse() << std::endl;
            }
            break;
        case CommandLineParser::CHECKSUM: {
                ChecksumFile checksum(commandLineParser.getInputFile());
                std::cout << "Checksum: " << checksum.parse() << std::endl;
            }
            break;
        case CommandLineParser::HELP:
            std::cout << commandLineParser << std::endl;
            break;
        case CommandLineParser::FAILURE:
            break;
    }
    return 0;
}