#pragma once

#include <string>

#include "TokenType.h"

struct Token
{
	std::string value;
	TokenType tokenType = TokenType::identifier;
};