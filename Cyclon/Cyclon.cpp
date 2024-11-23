#include <string>
#include <iostream>
#include <fstream>
#include <iosfwd>
#include <vector>

#include "Token.h"
#include "Lexer.h"

std::string readFromFile(std::string fileName)
{
	std::string text;

	std::ifstream inputFileStream(fileName);

	getline(inputFileStream, text);

	inputFileStream.close();

	return text;
}

int main()
{
	std::string sourceCode = readFromFile("main.cy");

	std::vector<Token> tokens = tokenize(sourceCode);

	for (auto &token : tokens)
	{
		std::cout << token.tokenType << std::endl;
	}

	return 0;
}
