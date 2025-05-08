#pragma once

#include <string>

#include "ExpressionNode.h"
#include "NodeType.h"

class IdentifierNode : public ExpressionNode
{
public:
	std::string symbol;

	IdentifierNode()
	{
		nodeType = NodeType::Identifier;
	}
};