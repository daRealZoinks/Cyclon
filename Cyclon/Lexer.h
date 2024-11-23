#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iosfwd>
#include <iostream>
#include <map>

#include "TokenType.h"
#include "IsNumber.h"
#include "IsAlphabetical.h"
#include "IsSkippable.h"
#include <cstdlib>
#include "Token.h"

typedef std::map<std::string, TokenType> ReservedIdentifierMap;

ReservedIdentifierMap reservedIdentifierMap = {
    {"automatic", TokenType::automatic},
};

std::vector<std::string> splitString(std::string &sourceCode)
{
    std::vector<std::string> words;
    std::string word;

    for (auto &character : sourceCode)
    {
        if (character != ' ')
        {
            word += character;
        }
        else if (!word.empty())
        {
            words.push_back(word);
            word.clear();
        }
    }

    if (!word.empty())
    {
        words.push_back(word);
    }

    return words;
}

Token createToken(std::string source, TokenType tokenType)
{
    Token token;
    token.value = source;
    token.tokenType = tokenType;
    return token;
}

std::string shift(std::vector<std::string> &source)
{
    std::string current = source.front();
    source.erase(source.begin());
    return current;
}

std::vector<Token> tokenize(std::string &sourceCode)
{
    std::vector<Token> tokens;

    std::vector<std::string> source = splitString(sourceCode);

    while (!source.empty())
    {
        if (source.front() == "(")
        {
            tokens.push_back(createToken(shift(source), TokenType::openParenthesis));
        }
        else if (source.front() == ")")
        {
            tokens.push_back(createToken(shift(source), TokenType::closedParenthesis));
        }
        else if (source.front() == "+" || source.front() == "-" || source.front() == "*" || source.front() == "/" || source.front() == "%")
        {
            tokens.push_back(createToken(shift(source), TokenType::binaryOperator));
        }
        else if (source.front() == "=")
        {
            tokens.push_back(createToken(shift(source), TokenType::equals));
        }
        else if (source.front() == ";")
        {
            tokens.push_back(createToken(shift(source), TokenType::endOfStatement));
        }
        else
        {
            if (isNumber(source.front()))
            {
                std::string number;
                while (!source.empty() && isNumber(source.front()))
                {
                    number += shift(source);
                }

                tokens.push_back(createToken(number, TokenType::number));
            }
            else if (isAlphabetical(source.front()))
            {
                std::string identifier = shift(source);

                auto iterator = reservedIdentifierMap.find(identifier);

                if (iterator != reservedIdentifierMap.end())
                {
                    tokens.push_back(createToken(identifier, iterator->second));
                }
                else
                {
                    tokens.push_back(createToken(identifier, TokenType::identifier));
                }
            }
            else if (isSkippable(source.front()[0]))
            {
                shift(source);
            }
            else
            {
                std::cout << "Character unexpected!" << std::endl;
                exit(1);
            }
        }
    }

    return tokens;
}