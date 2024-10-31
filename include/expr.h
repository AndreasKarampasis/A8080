#ifndef __EXPR_H__
#define __EXPR_H__

#include <stdint.h>
typedef enum expr_type {
    STRING_CONST,
    NUM_CONST
} ExprType;

typedef struct expr {
    ExprType type;
    char *str_const;
    uint16_t number_const;
} Expr;

Expr* new_number_const_expr(const uint16_t num);

Expr* new_string_const_expr(const char* s);

#endif
