#pragma once

#include <string>
#include <cctype>

bool isNumber(std::string& source)
{
	bool flag = true;

	for (char character : source)
	{
		if (!isdigit(character))
		{
			flag = false;
			break;
		}
	}

	return flag;
}