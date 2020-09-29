CC=g++
CLIB=-l boost_program_options -l boost_filesystem
CSTD=-std=c++11
CFLAG=-Wall
NAME=parse

SOURCES=main.cpp CommandLineParser.h CommandLineParser.cpp FileParser.h ChecksumFile.h ChecksumFile.cpp ParseFileWords.h ParseFileWords.cpp

all:
	$(CC) $(SOURCES) $(CLIB) $(CFLAG) $(CSTD) -o $(NAME)

clean:
	rm -rf parse
