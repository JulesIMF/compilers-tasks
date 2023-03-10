#pragma once

#include <lex/token.hpp>
#include <lex/token_type.hpp>

#include <map>
#include <string>

#include <fmt/core.h>

namespace Lex
{
class IdentTable
{
public:
    IdentTable()
    {
        Populate();
    }

    // Use-of-string-view-for-map-lookup
    // https://stackoverflow.com/questions/35525777

    TokenType
    LookupWord(const std::string word)
    {
        auto it = type_.find(word);
        if (it == type_.end())
            return TokenType::NONE;

        return it->second;
    }

private:
    void
    Populate()
    {
        //
        // Pseudo tokens
        //

        type_[" "]        = TokenType::WS;
        type_["\t"]       = TokenType::WS;
        type_["\n"]       = TokenType::WS;
        type_["\r"]       = TokenType::WS;
        type_["#"]        = TokenType::COMMENT;

        //
        // Delimiters
        //

        type_["("]        = TokenType::LPAREN;
        type_[")"]        = TokenType::RPAREN;
        type_["["]        = TokenType::LBRACK;
        type_["]"]        = TokenType::RBRACK;
        type_["{"]        = TokenType::LBRACE;
        type_["}"]        = TokenType::RBRACE;
        type_[","]        = TokenType::COMMA;
        type_["."]        = TokenType::DOT;
        type_[";"]        = TokenType::SEMICOLON;
        type_[":"]        = TokenType::COLON;

        //
        // Operators
        //

        type_["+"]        = TokenType::ADD;
        type_["-"]        = TokenType::SUB;
        type_["*"]        = TokenType::MUL;
        type_["/"]        = TokenType::DIV;
        type_["%"]        = TokenType::REM;
        type_["&"]        = TokenType::AND;
        type_["|"]        = TokenType::OR;
        type_["!"]        = TokenType::NOT;
        type_["&&"]       = TokenType::LAND;
        type_["||"]       = TokenType::LOR;
        type_["<"]        = TokenType::LSS;
        type_[">"]        = TokenType::GTR;
        type_["<="]       = TokenType::LEQ;
        type_[">="]       = TokenType::GEQ;
        type_["=="]       = TokenType::EQL;
        type_["!="]       = TokenType::NEQ;

        //
        // Assignation
        //

        type_["="]        = TokenType::ASGN;
        type_["+="]       = TokenType::ADD_ASGN;
        type_["-="]       = TokenType::SUB_ASGN;
        type_["*="]       = TokenType::MUL_ASGN;
        type_["/="]       = TokenType::DIV_ASGN;
        type_["%="]       = TokenType::REM_ASGN;
        type_["&="]       = TokenType::AND_ASGN;
        type_["|="]       = TokenType::OR_ASGN;
        type_["&&="]      = TokenType::LAND_ASGN;
        type_["||="]      = TokenType::LOR_ASGN;

        //
        // Keywords
        //

        type_["function"] = TokenType::FUNCTION;
        type_["while"]    = TokenType::WHILE;
        type_["for"]      = TokenType::FOR;
        type_["break"]    = TokenType::BREAK;
        type_["continue"] = TokenType::CONTINUE;
        type_["if"]       = TokenType::IF;
        type_["else"]     = TokenType::ELSE;
        type_["switch"]   = TokenType::SWITCH;
        type_["case"]     = TokenType::CASE;
        type_["default"]  = TokenType::DEFAULT;
        type_["struct"]   = TokenType::STRUCT;
        type_["return"]   = TokenType::RETURN;
        type_["true"]     = TokenType::TRUE;
        type_["false"]    = TokenType::FALSE;
    }

private:
    // What-are-transparent-comparators
    // https://stackoverflow.com/questions/20317413

    std::map<std::string, TokenType, std::less<>> type_;
};

}  // namespace Lex
