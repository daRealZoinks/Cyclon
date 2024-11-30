#pragma once

#include <vector>
#include <string>

enum NodeType
{
	program,
	numberLiteral,
	identifier,
	binaryExpression,
};

struct Statement
{
	NodeType nodeType;
};

struct Program : public Statement
{
	std::vector<Statement> body;

	Program()
	{
		nodeType = NodeType::program;	
	}
};

struct Expression : public Statement
{
};

struct BinaryExpression : public Expression
{
	Expression left;
	Expression right;
	std::string operatorValue;

	BinaryExpression()
	{
		nodeType = NodeType::binaryExpression;
	}
};

struct Identifier : public Expression
{
	std::string symbol;

	Identifier()
	{
		nodeType = NodeType::identifier;
	}
};

struct NumberLiteral : public Expression
{
	int value;

	NumberLiteral()
	{
		nodeType = NodeType::numberLiteral;
	}
};