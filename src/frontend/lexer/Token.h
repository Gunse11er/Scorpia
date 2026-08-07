#pragma once

#include <string>

namespace Scorpia{

enum class TokenType{
    Int,            // int
    Bool,           // bool 
    Void,           // void
    Return,         // return
    If,             // if
    Else,           // else
    While,          // while
    For,            // for  
    Const,          // const

    Identifier,

    IntegerLiteral,
    True,
    False,

    Plus,           // +
    Minus,          // -
    Star,           // *
    Slash,          // /
    Percent,        // %

    Assign,         // =

    EqualEqual,     // ==
    NotEqual,       // !=

    Less,           // <
    LessEqual,      // <=

    Greater,        // >
    GreaterEqual,   // >=


    BitAnd,         // &
    BitOr,          // |
    AndAnd,         // &&
    OrOr,           // ||
    Not,            // !

    PlusPlus,       // ++
    MinusMinus,     // --

    LeftParen,      // (
    RightParen,     // )

    LeftBrace,      // {
    RightBrace,     // }

    LeftBracket,    // [
    RightBracket,   // ]

    Comma,          // ,
    Semicolon,      // ;

    EOF_TOKEN,

    Unknown
};


struct Token{
    TokenType type;
    std::string lexeme;
    int line;
    int column;
    Token(TokenType type,
        std::string lexeme,
        int line = 0,
        int column = 0
    ):
        type(type),
        lexeme(lexeme),
        line(line),
        column(column)
        {}
};

} //namespace