#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string/trim.hpp>

#include "CommandLineParser.h"

CommandLineParser::CommandLineParser() :
        options(""),
        inputFile(""),
        inputMode(""),
        inputWord("") 
{
    setup();
}

CommandLineParser::~CommandLineParser() {}

CommandLineParser::returnStatus_t CommandLineParser::parse(int argc, char *argv[]) {
    po::variables_map varMap;
    char fileName[5000];

    try {
        po::store(po::parse_command_line(argc, argv, options), varMap);
        po::notify(varMap);

        if (varMap.count("help")) {
            return HELP;
        }

        boost::algorithm::trim(inputFile);
        boost::algorithm::trim(inputMode);
        boost::algorithm::trim(inputWord);

        if (varMap.count("file")) {
            realpath(inputFile.c_str(), fileName);
            inputFile = fileName;
            if (!validateFile()) {
                std::cout << "ERROR: Input file provided does not exist [" << inputFile << "]" << std::endl;
                return FAILURE;
            }

            if (varMap.count("mode") <= 0) {
                std::cout << "ERROR: Input mode must be specified" << std::endl;
                return FAILURE;
            }

            if (inputMode == "words") {
                if (varMap.count("word") <= 0) {
                    std::cout << "ERROR: Input word must be specified" << std::endl;
                    return FAILURE;
                }
                return WORDS;
            } else if (inputMode == "checksum") {
                return CHECKSUM;
            } else {
                std::cout << "ERROR: Unknown mode" << std::endl << std::endl;
                std::cout << *this << std::endl;
                return FAILURE;
            }
        }

    } catch (std::exception &e) {
        std::cout << "ERROR: " << e.what() << std::endl;
        return FAILURE;
    }
    std::cout << "ERROR: Unknown operation" << std::endl;
    std::cout << *this << std::endl;
    return FAILURE;
}

void CommandLineParser::setup() {
    po::options_description tempOptions("Program Options");
    tempOptions.add_options()
        ("help,h", "Display help menu.")
        ("file,f", po::value<std::string>(&inputFile), "User-specified input file.")
        ("mode,m", po::value<std::string>(&inputMode), "User-specified program mode.")
        ("word,v", po::value<std::string>(&inputWord), "User-specified program word." );

    options.add(tempOptions);
}

bool CommandLineParser::validateFile() {
    return boost::filesystem::is_regular_file(inputFile);
}

std::ostream &operator<<(std::ostream &os, const CommandLineParser& obj) {
    os << "Name" << std::endl;
    os << "\tparse - parse file to find number of words or count checksum" << std::endl;
    os << "Synopsis" << std::endl;
    os << "\tparse [-h]" << std::endl;
    os << "\t      [-f] [-m]" << std::endl;
    os << "\t      [-f] [-m] [-v]" << std::endl;
    os << obj.options << std::endl;
    return os;
}
