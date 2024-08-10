/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INCLUDE_PARSER_H_INCLUDED
# define YY_YY_INCLUDE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MOV = 258,                     /* MOV  */
    MVI = 259,                     /* MVI  */
    LXI = 260,                     /* LXI  */
    LDA = 261,                     /* LDA  */
    STA = 262,                     /* STA  */
    LHLD = 263,                    /* LHLD  */
    SHLD = 264,                    /* SHLD  */
    LDAX = 265,                    /* LDAX  */
    STAX = 266,                    /* STAX  */
    XCHG = 267,                    /* XCHG  */
    ADD = 268,                     /* ADD  */
    ADI = 269,                     /* ADI  */
    ADC = 270,                     /* ADC  */
    ACI = 271,                     /* ACI  */
    SUB = 272,                     /* SUB  */
    SUI = 273,                     /* SUI  */
    SBB = 274,                     /* SBB  */
    SBI = 275,                     /* SBI  */
    INR = 276,                     /* INR  */
    DCR = 277,                     /* DCR  */
    INX = 278,                     /* INX  */
    DCX = 279,                     /* DCX  */
    DAD = 280,                     /* DAD  */
    ANA = 281,                     /* ANA  */
    ANI = 282,                     /* ANI  */
    XRA = 283,                     /* XRA  */
    XRI = 284,                     /* XRI  */
    ORA = 285,                     /* ORA  */
    ORI = 286,                     /* ORI  */
    CMP = 287,                     /* CMP  */
    CPI = 288,                     /* CPI  */
    RLC = 289,                     /* RLC  */
    RRC = 290,                     /* RRC  */
    RAL = 291,                     /* RAL  */
    RAR = 292,                     /* RAR  */
    CMA = 293,                     /* CMA  */
    CMC = 294,                     /* CMC  */
    STC = 295,                     /* STC  */
    JMP = 296,                     /* JMP  */
    JC = 297,                      /* JC  */
    JNC = 298,                     /* JNC  */
    JZ = 299,                      /* JZ  */
    JNZ = 300,                     /* JNZ  */
    JP = 301,                      /* JP  */
    JM = 302,                      /* JM  */
    JPE = 303,                     /* JPE  */
    JPO = 304,                     /* JPO  */
    CALL = 305,                    /* CALL  */
    CC = 306,                      /* CC  */
    CNC = 307,                     /* CNC  */
    CZ = 308,                      /* CZ  */
    CNZ = 309,                     /* CNZ  */
    CP = 310,                      /* CP  */
    CM = 311,                      /* CM  */
    CPE = 312,                     /* CPE  */
    CPO = 313,                     /* CPO  */
    RET = 314,                     /* RET  */
    RC = 315,                      /* RC  */
    RNC = 316,                     /* RNC  */
    RZ = 317,                      /* RZ  */
    RNZ = 318,                     /* RNZ  */
    RP = 319,                      /* RP  */
    RM = 320,                      /* RM  */
    RPE = 321,                     /* RPE  */
    RPO = 322,                     /* RPO  */
    PUSH = 323,                    /* PUSH  */
    POP = 324,                     /* POP  */
    XTHL = 325,                    /* XTHL  */
    SPHL = 326,                    /* SPHL  */
    IN = 327,                      /* IN  */
    OUT = 328,                     /* OUT  */
    EI = 329,                      /* EI  */
    DI = 330,                      /* DI  */
    HLT = 331,                     /* HLT  */
    NOP = 332,                     /* NOP  */
    ORG = 333,                     /* ORG  */
    END = 334,                     /* END  */
    EQU = 335,                     /* EQU  */
    DB = 336,                      /* DB  */
    DW = 337,                      /* DW  */
    DS = 338,                      /* DS  */
    IF = 339,                      /* IF  */
    ENDIF = 340,                   /* ENDIF  */
    SET = 341,                     /* SET  */
    A = 342,                       /* A  */
    B = 343,                       /* B  */
    C = 344,                       /* C  */
    D = 345,                       /* D  */
    E = 346,                       /* E  */
    H = 347,                       /* H  */
    L = 348,                       /* L  */
    PC = 349,                      /* PC  */
    SP = 350,                      /* SP  */
    COMMA = 351,                   /* COMMA  */
    COLON = 352,                   /* COLON  */
    EOL = 353,                     /* EOL  */
    PLUS = 354,                    /* PLUS  */
    MINUS = 355,                   /* MINUS  */
    STAR = 356,                    /* STAR  */
    SLASH = 357,                   /* SLASH  */
    L_PAREN = 358,                 /* L_PAREN  */
    R_PAREN = 359,                 /* R_PAREN  */
    DOLLAR = 360,                  /* DOLLAR  */
    NAME = 361,                    /* NAME  */
    NUMBER = 362,                  /* NUMBER  */
    STR_CONST = 363                /* STR_CONST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "grammar/parser.y"

    char*   string_val;
    int     int_val;

#line 177 "include/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_PARSER_H_INCLUDED  */
