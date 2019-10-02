// TODO: include guards
#include <string>
#include <iostream>
#include <vector>

class Token
{
  public:
    Token(std::string_view);

    enum TOKEN_TYPE
    {
        INSTRUCTION,
        NUMBER,
        LABEL_DEF,
        LABEL_REF
    } token_type;

    enum INSTRUCTION_TYPE
    {
        LDCONST,
        STLOC,
        LDLOC,
        POP,
        OUT,
        ADD,
        MUL,
        SUB,
        DIV,
        LT,
        GT,
        GOTO,
        BRT,
        BRF,
    };
    // TODO: putting string in an union deletes the destructor, would have to write one explicitly
    // union {
    INSTRUCTION_TYPE instruction_type;
    std::string label;
    int num;
    // };
};

class Lexer
{
  public:
    static std::vector<Token> lex_line(std::string_view line)
    {
        std::vector<Token> tokens;
        std::string buffer = "";

        // TODO: pass starting index to Token for better error msgs
        for (char c : line)
        {
            if (c == '#') // comment found
                break;
            if (c == ' ' || c == '\t') // whitespace found
            {
                if (buffer != "")
                {
                    tokens.push_back(Token(buffer));
                    buffer = "";
                }
                continue;
            }
            buffer += c;
        }

        // // ended, but buffer can still be non-empty
        if (buffer != "")
            tokens.push_back(Token(buffer));


        // GRAMMAR CHECK
        // done runtime!

        // if (tokens.size() == 0)
        //     return tokens; // empty line

        // if (tokens[0].token_type != Token::INSTRUCTION || tokens[0].token_type != Token::LABEL_DEF)
        //     throw std::runtime_error("Each non-empty line has to start with an instruction.");
        // if (tokens[0].instruction_type == Token::STLOC || tokens[0].instruction_type == Token::LDCONST)
        // {
        //     if (tokens.size() < 2)
        //         throw std::runtime_error("Missing argument.");
        //     // TODO: move the constants somewhere else
        //     if (tokens[1].token_type != Token::NUMBER || tokens[1].num < 0 || tokens[1].num > 10)
        //         throw std::runtime_error("STLOC and LDCONST instructions have to be followed by a register number");
        //     if (tokens.size() > 2)
        //         throw std::runtime_error("Too many arguments.");
        // }
        // if (tokens[0].instruction_type == Token::GOTO || tokens[0].instruction_type == Token::BRT || tokens[0].instruction_type == Token::BRF)
        // {
        //     if (tokens.size() < 2)
        //         throw std::runtime_error("Missing argument.");
        //     // TODO: move the constants somewhere else
        //     if (tokens[1].token_type != Token::LABEL_REF)
        //         throw std::runtime_error("GOTO, BRT and BRF instructions have to be followed by a label ref.");
        //     if (tokens.size() > 2)
        //         throw std::runtime_error("Too many arguments.");
        // }

        return tokens;
    };
};