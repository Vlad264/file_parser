#ifndef _COMMAND_LINE_PARSER_H_
#define _COMMAND_LINE_PARSER_H_

#include <string>
#include <boost/program_options.hpp>
namespace po = boost::program_options;

class CommandLineParser {
public:
    enum returnStatus_t {
        WORDS,
        CHECKSUM,
        HELP,
        FAILURE
    };

    CommandLineParser();
    ~CommandLineParser();
    returnStatus_t parse(int argc, char *argv[]);

    inline const std::string &getInputFile() const {return inputFile;};
    inline const std::string &getInputMode() const {return inputMode;};
    inline const std::string &getInputWord() const {return inputWord;};

    friend std::ostream &operator<<(std::ostream &os, const CommandLineParser& obj);

protected:
    void setup();
    bool validateFile();
    
private:
    po::options_description options;
    std::string inputFile;
    std::string inputMode;
    std::string inputWord;
};



#endif //_COMMAND_LINE_PARSER_H_
