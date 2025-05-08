#pragma once

#include "StatementNode.h"
#include "NodeType.h"

class ProgramNode : public StatementNode
{
public:
	StatementNode** bodyArray;
	size_t bodyArraySize;

	ProgramNode()
	{
		nodeType = NodeType::Program;
	}
};