#pragma once

bool isSkippable(char character)
{
	return character == ' ' || character == '\n' || character == '\t';
}