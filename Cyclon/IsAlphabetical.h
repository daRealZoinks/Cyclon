#pragma once

#include <string>
#include <cctype>

bool isAlphabetical(std::string& source)
{
	for (char character : source)
	{
		if (!isalpha(character))
		{
			return false;
		}
	}

	return true;
}