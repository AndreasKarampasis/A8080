#ifndef __TOKEN_H__
#define __TOKEN_H__

enum tokenType {
    INSTRUCTION,
    DIRECTIVE,
    NAME,
    LABEL,
    STR_CONST,
    INT_CONST,
    BINARY_CONST,
    HEX_CONST,
    OPERATOR,
    DELIMETER
};

struct token {
    tokenType type;
    char *value;
    int line;
    int col;
    char *fileName;
};

#endif