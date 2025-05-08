#include <string>
#include <iostream>
#include <fstream>
#include <iosfwd>

#include "Parser/Parser.h"
#include "Parser/AbstractSyntaxTreeTypes/NodeType.h"
#include "Parser/AbstractSyntaxTreeTypes/NumericLiteralNode.h"
#include "Parser/AbstractSyntaxTreeTypes/ProgramNode.h"
#include "Parser/AbstractSyntaxTreeTypes/StatementNode.h"
#include <vector>
#include "Lexer/Lexer.h"
#include "Lexer/Token.h"

static std::string readFromFile(std::string fileName)
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
	//std::string sourceCode = "10";

	std::vector<Token> tokens = tokenize(sourceCode);

	for (auto &token : tokens)
	{
		std::cout << token.tokenType << std::endl;
	}

	Parser parser;
	ProgramNode program = parser.ProduceAbstractSyntaxTree(sourceCode);

	for (size_t i = 0; i < program.bodyArraySize; i++)
	{
		StatementNode* node = program.bodyArray[i];

		switch (node->nodeType)
		{
			case Program:
				break;
			case NumericLiteral:
			{
				NumericLiteralNode* numericLiteralNode = static_cast<NumericLiteralNode*>(node);
				std::cout << numericLiteralNode->value << std::endl;
				break;
			}
			case Identifier:
			{
				//IdentifierNode numericLiteralNode = dynamic_cast<IdentifierNode*>(*node);
				break;
			}
			case BinaryExpression:
				break;
			default:
				break;
		}
	}

	return 0;
}
