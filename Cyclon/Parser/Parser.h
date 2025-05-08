#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

#include "AbstractSyntaxTreeTypes/ExpressionNode.h"
#include "AbstractSyntaxTreeTypes/IdentifierNode.h"
#include "AbstractSyntaxTreeTypes/NumericLiteralNode.h"
#include "AbstractSyntaxTreeTypes/ProgramNode.h"
#include "AbstractSyntaxTreeTypes/StatementNode.h"
#include "../Lexer/Lexer.h"
#include "../Lexer/Token.h"
#include "../Lexer/TokenType.h"

class Parser
{
public:
	ProgramNode ProduceAbstractSyntaxTree(std::string sourceCode)
	{
		ProgramNode programNode;

		tokens = tokenize(sourceCode);

		programNode.bodyArraySize = tokens.size();
		int k = 0;
		programNode.bodyArray = new StatementNode * [programNode.bodyArraySize];

		for (size_t i = 0; i < programNode.bodyArraySize; i++)
		{
			Token token = tokens[i];
			programNode.bodyArray[k++] = parseStatement(token);
		}

		return programNode;
	}

private:
	StatementNode* parseStatement(Token token)
	{
		return	parseExpression(token);
	}

	ExpressionNode* parseExpression(Token token)
	{
		return	parsePrimaryExpression(token);
	}

	ExpressionNode* parsePrimaryExpression(Token token)
	{
		TokenType tokenType = token.tokenType;

		switch (tokenType)
		{
			case TokenType::number:
			{
				NumericLiteralNode* numericLiteralNode = new NumericLiteralNode();
				numericLiteralNode->value = std::stoi(token.value);

				return numericLiteralNode;
				break;
			}
			case TokenType::identifier:
			{
				IdentifierNode* identifierNode = new IdentifierNode();
				identifierNode->symbol = token.value;

				return identifierNode;
				break;
			}
			case TokenType::equals:
				break;
			case TokenType::openParenthesis:
				break;
			case TokenType::closedParenthesis:
				break;
			case TokenType::binaryOperator:
				break;
			case TokenType::automatic:
				break;
			case TokenType::endOfStatement:
				break;
			default:
				std::cout << "Unexpected token found during parsing: "<< token.value << std::endl;
				exit(1);
				StatementNode* statementNode = new StatementNode();
					

				return (ExpressionNode*)statementNode;
				break;
		}
	}

private:
	std::vector<Token> tokens;
};