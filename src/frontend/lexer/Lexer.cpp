#include "Lexer.h"
#include <string>
#include <unordered_map>
#include <cctype>

namespace Scorpia{

    static const std::unordered_map<std::string, TokenType> keywords = 
    {
        {"int", TokenType::Int},
        {"bool", TokenType::Bool},
        {"void", TokenType::Void},
        {"return", TokenType::Return},
        {"if", TokenType::If},
        {"else", TokenType::Else},
        {"while", TokenType::While},
        {"for", TokenType::For},
        {"const", TokenType::Const},
        {"true", TokenType::True},
        {"false", TokenType::False}
    };



    Lexer::Lexer(const std::string& source){
        this->source = source;

        position = 0;

        line = 1;

        column = 1;
    }

    char Lexer::currentChar(){
        if(position >= source.size()){
            return '\0';
        }
        return source[position];
    }

    char Lexer::peekChar(){
        if(position + 1 >= source.size()){
            return '\0';
        }
        return source[position+1];
    }


    void Lexer::advance(){
        if(currentChar() == '\n'){
            line++;
            column = 1;
        }else{
            column++;
        }
        position++;
    }

    Token Lexer::scanIdentifier(){
        std::string value;
        while(isalnum(currentChar()) || currentChar() == '_'){
            value += currentChar();
            advance();
        }
        auto it = keywords.find(value);
        if(it != keywords.end()){
            return Token(it->second,
                        value,
                        line,
                        column
            );
        }
        return Token(TokenType::Identifier,
                    value,
                    line,
                    column
        );
    }

    Token Lexer::scanNumber(){
        std::string value;
        while(isdigit(currentChar())){
            value += currentChar();
            advance();
        }
        return Token(TokenType::IntegerLiteral,
                value,
                line,
                column
                );
    }



    void Lexer::skipWhitespace(){
        while(isspace(currentChar())){
            advance();
        }
    }


    Token Lexer::nextToken(){
        skipWhitespace();

        char c = currentChar();

        if(c == '\0'){
            return Token(
                TokenType::EOF_TOKEN,
                ""
            );
        }

        if(isalpha(c) || c == '_'){
            return scanIdentifier();
        }

        if(isdigit(c)){
            return scanNumber();
        }

        switch(c){
            case '+':
                if(peekChar() == '+'){
                    advance();
                    advance();
                    return Token(
                        TokenType::PlusPlus,
                        "++"
                    );
                }else{
                    advance();
                    return Token(
                        TokenType::Plus,
                        "+"
                    );
                }

            case '-':
                if(peekChar() == '-'){
                    advance();
                    advance();
                    return Token(
                        TokenType::MinusMinus,
                        "--"
                    );
                }else{
                    advance();
                    return Token(
                        TokenType::Minus,
                        "-"
                    );
                }
            case '*':
                advance();
                return Token(
                    TokenType::Star,
                    "*"
                );
            case '/':
                advance();
                return Token(
                    TokenType::Slash,
                    "/"
                );
            case '%':
                advance();
                return Token(
                    TokenType::Percent,
                    "%"
                );
            case ',':
                advance();
                return Token(
                    TokenType::Comma,
                    ","
                );
            case ';':
                advance();
                return Token(
                    TokenType::Semicolon,
                    ";"
                );
            case '(':
                advance();
                return Token(
                    TokenType::LeftParen,
                    "("
                );
            case ')':
                advance();
                return Token(
                    TokenType::RightParen,
                    ")"
                );          
            case '{':
                advance();
                return Token(
                    TokenType::LeftBrace,
                    "{"
                );
            case '}':
                advance();
                return Token(
                    TokenType::RightBrace,
                    "}"
                );
            case '[':
                advance();
                return Token(
                    TokenType::LeftBracket,
                    "["
                );
            case ']':
                advance();
                return Token(
                    TokenType::RightBracket,
                    "]"
                );            
            case '=':
                if(peekChar() == '='){
                    advance();
                    advance();
                    return Token(
                        TokenType::EqualEqual,
                        "=="
                    );
                }else{
                    advance();
                    return Token(
                        TokenType::Assign,
                        "="
                    ); 
                }
            case '>':
                if(peekChar() == '='){
                    advance();
                    advance();
                    return Token(
                        TokenType::GreaterEqual,
                                ">="
                    );
                }else{
                    advance();
                    return Token(
                        TokenType::Greater,
                                ">"
                    );
                }
            case '<':
                if(peekChar() == '='){
                    advance();
                    advance();
                    return Token(
                        TokenType::LessEqual,
                                "<="
                    );
                }else{
                    advance();
                    return Token(
                        TokenType::Less,
                                "<"
                    );
                }
            case '!':
                if(peekChar() == '='){
                    advance();
                    advance();
                    return Token(
                        TokenType::NotEqual,
                                "!="
                    );
                }else{
                    advance();
                    return Token(
                        TokenType::Not,
                                "!"
                    );
                }
            case '&':
                if(peekChar() == '&'){
                    advance();
                    advance();
                    return Token(
                        TokenType::AndAnd,
                                "&&"
                    );                        
                }else{
                    advance();
                    return Token(
                        TokenType::BitAnd,
                                "&"
                    );
                }
            case '|':
                if(peekChar() == '|'){
                    advance();
                    advance();
                    return Token(
                        TokenType::OrOr,
                                "||"
                    ); 
                }else{
                    advance();
                    return Token(
                        TokenType::BitOr,
                                "|"
                    );
                }
            
            }         
            advance();
            return Token(TokenType::Unknown, std::string(1,c));
    }







} //namespace