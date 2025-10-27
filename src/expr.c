#include "expr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

extern int yylineno;

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

void comp_error(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    fprintf(stderr, "\033[1;31mError:\033[0m%d ", yylineno);
    vfprintf(stderr, fmt, args);

    fprintf(stderr, "\nHint: Ensure the expression is valid for the given context.\n");

    va_end(args);
    exit(EXIT_FAILURE);
}


void expr_check_arith(Expr *e, const char *context) {
    if (e->type == STRING_CONST) {
        comp_error(
            "Illegal expression used in %s.\n"
            "  | Details: String constant encountered where a numeric value is required.",
            context
        );
    }
}
