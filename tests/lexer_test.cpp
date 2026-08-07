#include "Lexer.h"

#include <iostream>


using namespace Scorpia;


int main()
{
    std::string source = R"(

        int main()
        {
            int a >= 10;

            return a;
        }

    )";


    Lexer lexer(source);


    while(true)
    {
        Token token = lexer.nextToken();


        std::cout
            << "Token: "
            << static_cast<int>(token.type)
            << "  "
            << token.lexeme
            << std::endl;


        if(token.type == TokenType::EOF_TOKEN)
        {
            break;
        }
    }


    return 0;
}