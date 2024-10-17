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
    DAA = 281,                     /* DAA  */
    ANA = 282,                     /* ANA  */
    ANI = 283,                     /* ANI  */
    XRA = 284,                     /* XRA  */
    XRI = 285,                     /* XRI  */
    ORA = 286,                     /* ORA  */
    ORI = 287,                     /* ORI  */
    CMP = 288,                     /* CMP  */
    CPI = 289,                     /* CPI  */
    RLC = 290,                     /* RLC  */
    RRC = 291,                     /* RRC  */
    RAL = 292,                     /* RAL  */
    RAR = 293,                     /* RAR  */
    CMA = 294,                     /* CMA  */
    CMC = 295,                     /* CMC  */
    STC = 296,                     /* STC  */
    JMP = 297,                     /* JMP  */
    JC = 298,                      /* JC  */
    JNC = 299,                     /* JNC  */
    JZ = 300,                      /* JZ  */
    JNZ = 301,                     /* JNZ  */
    JP = 302,                      /* JP  */
    JM = 303,                      /* JM  */
    JPE = 304,                     /* JPE  */
    JPO = 305,                     /* JPO  */
    CALL = 306,                    /* CALL  */
    CC = 307,                      /* CC  */
    CNC = 308,                     /* CNC  */
    CZ = 309,                      /* CZ  */
    CNZ = 310,                     /* CNZ  */
    CP = 311,                      /* CP  */
    CM = 312,                      /* CM  */
    CPE = 313,                     /* CPE  */
    CPO = 314,                     /* CPO  */
    RET = 315,                     /* RET  */
    RC = 316,                      /* RC  */
    RNC = 317,                     /* RNC  */
    RZ = 318,                      /* RZ  */
    RNZ = 319,                     /* RNZ  */
    RP = 320,                      /* RP  */
    RM = 321,                      /* RM  */
    RPE = 322,                     /* RPE  */
    RPO = 323,                     /* RPO  */
    PUSH = 324,                    /* PUSH  */
    POP = 325,                     /* POP  */
    XTHL = 326,                    /* XTHL  */
    SPHL = 327,                    /* SPHL  */
    IN = 328,                      /* IN  */
    OUT = 329,                     /* OUT  */
    EI = 330,                      /* EI  */
    DI = 331,                      /* DI  */
    HLT = 332,                     /* HLT  */
    NOP = 333,                     /* NOP  */
    RST = 334,                     /* RST  */
    ORG = 335,                     /* ORG  */
    END = 336,                     /* END  */
    EQU = 337,                     /* EQU  */
    DB = 338,                      /* DB  */
    DW = 339,                      /* DW  */
    DS = 340,                      /* DS  */
    IF = 341,                      /* IF  */
    ENDIF = 342,                   /* ENDIF  */
    SET = 343,                     /* SET  */
    PCHL = 344,                    /* PCHL  */
    A = 345,                       /* A  */
    B = 346,                       /* B  */
    C = 347,                       /* C  */
    D = 348,                       /* D  */
    E = 349,                       /* E  */
    H = 350,                       /* H  */
    L = 351,                       /* L  */
    M = 352,                       /* M  */
    SP = 353,                      /* SP  */
    TOK_EOL = 354,                 /* TOK_EOL  */
    MODULO = 355,                  /* MODULO  */
    NOT = 356,                     /* NOT  */
    AND = 357,                     /* AND  */
    OR = 358,                      /* OR  */
    XOR = 359,                     /* XOR  */
    SHR = 360,                     /* SHR  */
    SHL = 361,                     /* SHL  */
    NAME = 362,                    /* NAME  */
    HEX_NUMBER = 363,              /* HEX_NUMBER  */
    DEC_NUMBER = 364,              /* DEC_NUMBER  */
    OCT_NUMBER = 365,              /* OCT_NUMBER  */
    BIN_NUMBER = 366,              /* BIN_NUMBER  */
    STR_CONST = 367,               /* STR_CONST  */
    CHAR = 368,                    /* CHAR  */
    UMINUS = 369                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "grammar/parser.y"

    char*   string_val;
    char    char_val;
    uint16_t int_val;
    uint8_t opcode;

#line 185 "include/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_PARSER_H_INCLUDED  */
