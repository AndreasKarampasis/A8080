#include "expr.h"
#include <stdlib.h>
#include <string.h>

Expr* new_expr(ExprType t) {
    Expr* e = (Expr*)malloc(sizeof(Expr));
    memset(e, 0, sizeof(Expr));
    e->type = t;
    return e;
}

Expr* new_number_const_expr(const uint16_t num) {
    Expr* e = new_expr(NUM_CONST);
    e->number_const = num;
    return e;
}

Expr* new_string_const_expr(const char* s) {
    Expr* e = new_expr(STRING_CONST);
    e->str_const = strdup(s);
    return e;
}
