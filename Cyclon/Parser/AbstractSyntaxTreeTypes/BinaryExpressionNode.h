#pragma once

#include <string>

#include "ExpressionNode.h"
#include "NodeType.h"

class BinaryExpressionNode : public ExpressionNode
{
public:
	ExpressionNode left;
	ExpressionNode right;
	std::string operatorValue;

	BinaryExpressionNode()
	{
		nodeType = NodeType::BinaryExpression;
	}
};