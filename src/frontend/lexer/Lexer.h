#pragma once

#include "Token.h"
#include <string>

namespace Scorpia{

class Lexer{
    public:
        Lexer(const std::string& source);

        Token nextToken();

    private:
        char currentChar();

        char peekChar();

        void advance();

        void skipWhitespace();

        Token scanNumber();

        Token scanIdentifier();

    private:
        std::string source;

        size_t position;

        unsigned int line;

        unsigned int column;
};

} //namespace