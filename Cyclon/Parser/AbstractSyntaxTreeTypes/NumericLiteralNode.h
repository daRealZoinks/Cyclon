#pragma once

#include "NodeType.h"
#include "ExpressionNode.h"

class NumericLiteralNode : public ExpressionNode
{
public:
	int value;

	NumericLiteralNode()
	{
		value = 0;
		nodeType = NodeType::NumericLiteral;
	}
};