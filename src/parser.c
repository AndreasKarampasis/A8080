/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar/parser.y"

#include "symboltable.h"
#include "instruction.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>

void yyerror (const char* msg);
extern int yylex(void);
extern int yylineno;
// extern int yyleng;
extern char *yytext;
extern FILE *yyin;
extern FILE *yyout;

Symboltable *symbolTable;
size_t LC = 0;

#line 92 "src/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MOV = 3,                        /* MOV  */
  YYSYMBOL_MVI = 4,                        /* MVI  */
  YYSYMBOL_LXI = 5,                        /* LXI  */
  YYSYMBOL_LDA = 6,                        /* LDA  */
  YYSYMBOL_STA = 7,                        /* STA  */
  YYSYMBOL_LHLD = 8,                       /* LHLD  */
  YYSYMBOL_SHLD = 9,                       /* SHLD  */
  YYSYMBOL_LDAX = 10,                      /* LDAX  */
  YYSYMBOL_STAX = 11,                      /* STAX  */
  YYSYMBOL_XCHG = 12,                      /* XCHG  */
  YYSYMBOL_ADD = 13,                       /* ADD  */
  YYSYMBOL_ADI = 14,                       /* ADI  */
  YYSYMBOL_ADC = 15,                       /* ADC  */
  YYSYMBOL_ACI = 16,                       /* ACI  */
  YYSYMBOL_SUB = 17,                       /* SUB  */
  YYSYMBOL_SUI = 18,                       /* SUI  */
  YYSYMBOL_SBB = 19,                       /* SBB  */
  YYSYMBOL_SBI = 20,                       /* SBI  */
  YYSYMBOL_INR = 21,                       /* INR  */
  YYSYMBOL_DCR = 22,                       /* DCR  */
  YYSYMBOL_INX = 23,                       /* INX  */
  YYSYMBOL_DCX = 24,                       /* DCX  */
  YYSYMBOL_DAD = 25,                       /* DAD  */
  YYSYMBOL_DAA = 26,                       /* DAA  */
  YYSYMBOL_ANA = 27,                       /* ANA  */
  YYSYMBOL_ANI = 28,                       /* ANI  */
  YYSYMBOL_XRA = 29,                       /* XRA  */
  YYSYMBOL_XRI = 30,                       /* XRI  */
  YYSYMBOL_ORA = 31,                       /* ORA  */
  YYSYMBOL_ORI = 32,                       /* ORI  */
  YYSYMBOL_CMP = 33,                       /* CMP  */
  YYSYMBOL_CPI = 34,                       /* CPI  */
  YYSYMBOL_RLC = 35,                       /* RLC  */
  YYSYMBOL_RRC = 36,                       /* RRC  */
  YYSYMBOL_RAL = 37,                       /* RAL  */
  YYSYMBOL_RAR = 38,                       /* RAR  */
  YYSYMBOL_CMA = 39,                       /* CMA  */
  YYSYMBOL_CMC = 40,                       /* CMC  */
  YYSYMBOL_STC = 41,                       /* STC  */
  YYSYMBOL_JMP = 42,                       /* JMP  */
  YYSYMBOL_JC = 43,                        /* JC  */
  YYSYMBOL_JNC = 44,                       /* JNC  */
  YYSYMBOL_JZ = 45,                        /* JZ  */
  YYSYMBOL_JNZ = 46,                       /* JNZ  */
  YYSYMBOL_JP = 47,                        /* JP  */
  YYSYMBOL_JM = 48,                        /* JM  */
  YYSYMBOL_JPE = 49,                       /* JPE  */
  YYSYMBOL_JPO = 50,                       /* JPO  */
  YYSYMBOL_CALL = 51,                      /* CALL  */
  YYSYMBOL_CC = 52,                        /* CC  */
  YYSYMBOL_CNC = 53,                       /* CNC  */
  YYSYMBOL_CZ = 54,                        /* CZ  */
  YYSYMBOL_CNZ = 55,                       /* CNZ  */
  YYSYMBOL_CP = 56,                        /* CP  */
  YYSYMBOL_CM = 57,                        /* CM  */
  YYSYMBOL_CPE = 58,                       /* CPE  */
  YYSYMBOL_CPO = 59,                       /* CPO  */
  YYSYMBOL_RET = 60,                       /* RET  */
  YYSYMBOL_RC = 61,                        /* RC  */
  YYSYMBOL_RNC = 62,                       /* RNC  */
  YYSYMBOL_RZ = 63,                        /* RZ  */
  YYSYMBOL_RNZ = 64,                       /* RNZ  */
  YYSYMBOL_RP = 65,                        /* RP  */
  YYSYMBOL_RM = 66,                        /* RM  */
  YYSYMBOL_RPE = 67,                       /* RPE  */
  YYSYMBOL_RPO = 68,                       /* RPO  */
  YYSYMBOL_PUSH = 69,                      /* PUSH  */
  YYSYMBOL_POP = 70,                       /* POP  */
  YYSYMBOL_XTHL = 71,                      /* XTHL  */
  YYSYMBOL_SPHL = 72,                      /* SPHL  */
  YYSYMBOL_IN = 73,                        /* IN  */
  YYSYMBOL_OUT = 74,                       /* OUT  */
  YYSYMBOL_EI = 75,                        /* EI  */
  YYSYMBOL_DI = 76,                        /* DI  */
  YYSYMBOL_HLT = 77,                       /* HLT  */
  YYSYMBOL_NOP = 78,                       /* NOP  */
  YYSYMBOL_RST = 79,                       /* RST  */
  YYSYMBOL_ORG = 80,                       /* ORG  */
  YYSYMBOL_END = 81,                       /* END  */
  YYSYMBOL_EQU = 82,                       /* EQU  */
  YYSYMBOL_DB = 83,                        /* DB  */
  YYSYMBOL_DW = 84,                        /* DW  */
  YYSYMBOL_DS = 85,                        /* DS  */
  YYSYMBOL_IF = 86,                        /* IF  */
  YYSYMBOL_ENDIF = 87,                     /* ENDIF  */
  YYSYMBOL_SET = 88,                       /* SET  */
  YYSYMBOL_PCHL = 89,                      /* PCHL  */
  YYSYMBOL_A = 90,                         /* A  */
  YYSYMBOL_B = 91,                         /* B  */
  YYSYMBOL_C = 92,                         /* C  */
  YYSYMBOL_D = 93,                         /* D  */
  YYSYMBOL_E = 94,                         /* E  */
  YYSYMBOL_H = 95,                         /* H  */
  YYSYMBOL_L = 96,                         /* L  */
  YYSYMBOL_M = 97,                         /* M  */
  YYSYMBOL_SP = 98,                        /* SP  */
  YYSYMBOL_TOK_EOL = 99,                   /* TOK_EOL  */
  YYSYMBOL_100_ = 100,                     /* ','  */
  YYSYMBOL_101_ = 101,                     /* ':'  */
  YYSYMBOL_102_ = 102,                     /* '+'  */
  YYSYMBOL_103_ = 103,                     /* '-'  */
  YYSYMBOL_104_ = 104,                     /* '*'  */
  YYSYMBOL_105_ = 105,                     /* '/'  */
  YYSYMBOL_106_ = 106,                     /* '('  */
  YYSYMBOL_107_ = 107,                     /* ')'  */
  YYSYMBOL_108_ = 108,                     /* '$'  */
  YYSYMBOL_MODULO = 109,                   /* MODULO  */
  YYSYMBOL_NOT = 110,                      /* NOT  */
  YYSYMBOL_AND = 111,                      /* AND  */
  YYSYMBOL_OR = 112,                       /* OR  */
  YYSYMBOL_XOR = 113,                      /* XOR  */
  YYSYMBOL_SHR = 114,                      /* SHR  */
  YYSYMBOL_SHL = 115,                      /* SHL  */
  YYSYMBOL_NAME = 116,                     /* NAME  */
  YYSYMBOL_HEX_NUMBER = 117,               /* HEX_NUMBER  */
  YYSYMBOL_DEC_NUMBER = 118,               /* DEC_NUMBER  */
  YYSYMBOL_OCT_NUMBER = 119,               /* OCT_NUMBER  */
  YYSYMBOL_BIN_NUMBER = 120,               /* BIN_NUMBER  */
  YYSYMBOL_STR_CONST = 121,                /* STR_CONST  */
  YYSYMBOL_CHAR = 122,                     /* CHAR  */
  YYSYMBOL_UMINUS = 123,                   /* UMINUS  */
  YYSYMBOL_YYACCEPT = 124,                 /* $accept  */
  YYSYMBOL_program = 125,                  /* program  */
  YYSYMBOL_line = 126,                     /* line  */
  YYSYMBOL_instruction = 127,              /* instruction  */
  YYSYMBOL_data_transfer = 128,            /* data_transfer  */
  YYSYMBOL_arithmetic = 129,               /* arithmetic  */
  YYSYMBOL_logical = 130,                  /* logical  */
  YYSYMBOL_branch = 131,                   /* branch  */
  YYSYMBOL_stack_io = 132,                 /* stack_io  */
  YYSYMBOL_control = 133,                  /* control  */
  YYSYMBOL_directives = 134,               /* directives  */
  YYSYMBOL_label = 135,                    /* label  */
  YYSYMBOL_expr = 136,                     /* expr  */
  YYSYMBOL_term = 137,                     /* term  */
  YYSYMBOL_primary = 138,                  /* primary  */
  YYSYMBOL_immediate = 139,                /* immediate  */
  YYSYMBOL_reg_pair = 140,                 /* reg_pair  */
  YYSYMBOL_register = 141                  /* register  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  124
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   369


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   108,     2,     2,     2,
     106,   107,   104,   102,   100,   103,     2,   105,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   101,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    59,    62,    63,    64,    65,    69,    70,
      71,    72,    73,    74,    75,    79,    85,    91,    97,   103,
     109,   115,   121,   127,   133,   142,   148,   154,   160,   166,
     172,   178,   184,   190,   196,   202,   208,   214,   220,   229,
     235,   241,   247,   253,   259,   265,   271,   277,   283,   289,
     295,   301,   307,   313,   322,   328,   334,   340,   346,   352,
     358,   364,   370,   376,   382,   388,   394,   400,   406,   412,
     418,   424,   430,   436,   442,   448,   454,   460,   466,   472,
     478,   484,   493,   499,   505,   511,   517,   523,   532,   538,
     544,   550,   556,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   577,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   596,   597,   598,   599,   604,   610,
     615,   616,   617,   618,   622,   623,   624,   625,   629,   630,
     631,   632,   633,   634,   635,   636
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MOV", "MVI", "LXI",
  "LDA", "STA", "LHLD", "SHLD", "LDAX", "STAX", "XCHG", "ADD", "ADI",
  "ADC", "ACI", "SUB", "SUI", "SBB", "SBI", "INR", "DCR", "INX", "DCX",
  "DAD", "DAA", "ANA", "ANI", "XRA", "XRI", "ORA", "ORI", "CMP", "CPI",
  "RLC", "RRC", "RAL", "RAR", "CMA", "CMC", "STC", "JMP", "JC", "JNC",
  "JZ", "JNZ", "JP", "JM", "JPE", "JPO", "CALL", "CC", "CNC", "CZ", "CNZ",
  "CP", "CM", "CPE", "CPO", "RET", "RC", "RNC", "RZ", "RNZ", "RP", "RM",
  "RPE", "RPO", "PUSH", "POP", "XTHL", "SPHL", "IN", "OUT", "EI", "DI",
  "HLT", "NOP", "RST", "ORG", "END", "EQU", "DB", "DW", "DS", "IF",
  "ENDIF", "SET", "PCHL", "A", "B", "C", "D", "E", "H", "L", "M", "SP",
  "TOK_EOL", "','", "':'", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'$'",
  "MODULO", "NOT", "AND", "OR", "XOR", "SHR", "SHL", "NAME", "HEX_NUMBER",
  "DEC_NUMBER", "OCT_NUMBER", "BIN_NUMBER", "STR_CONST", "CHAR", "UMINUS",
  "$accept", "program", "line", "instruction", "data_transfer",
  "arithmetic", "logical", "branch", "stack_io", "control", "directives",
  "label", "expr", "term", "primary", "immediate", "reg_pair", "register", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -99,   248,   -99,   -37,   -37,   -83,   -14,   -14,   -14,   -14,
     -83,   -83,   -99,   -37,   -14,   -37,   -14,   -37,   -14,   -37,
     -14,   -37,   -37,   -83,   -83,   -83,   -99,   -37,   -14,   -37,
     -14,   -37,   -14,   -37,   -14,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -83,
     -83,   -99,   -99,   -14,   -14,   -99,   -99,   -99,   -99,   -14,
     -14,   -99,   -99,   -14,   -14,   -14,   -99,   -99,   -99,   -99,
     -98,   -93,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     362,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -86,
     -84,   -99,   -99,   -99,   -99,   -80,   -14,   -14,   -14,   -99,
     -99,   -99,   -99,   -99,    24,   -99,   -99,   -99,    24,    24,
      24,   -99,   -99,   -99,    24,   -99,    24,   -99,    24,   -99,
      24,   -99,   -99,   -99,   -99,   -99,   -99,    24,   -99,    24,
     -99,    24,   -99,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,   -99,   -99,    24,    24,    24,    24,    24,    24,
      24,   -99,   -99,   -99,   -37,   -14,   -14,   -99,    10,   -99,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -99,    24,    24,   -99,    54,    54,   -99,   -99,   -99,    52,
      38,    38,   -99,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     7,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,     0,
       0,    84,    85,     0,     0,    88,    89,    91,    90,     0,
       0,    94,    95,     0,     0,     0,    99,   100,   101,    81,
       0,     0,     5,     8,     9,    10,    11,    12,    13,    14,
       6,   135,   128,   129,   130,   131,   132,   133,   134,     0,
       0,   124,   125,   126,   127,     0,     0,     0,     0,   118,
     120,   121,   122,   123,    18,   113,   117,   119,    19,    22,
      23,    20,    21,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    39,    40,    41,    42,
      43,    44,    45,    46,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    82,    83,    86,    87,    92,    93,    96,    97,
      98,   102,     2,     4,     0,     0,     0,   115,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,    17,   114,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   -99,   -78,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,    -7,   -99,   -99,   -99,    -6,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   124,   125,   126,   127,   115,   109
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     128,   129,   130,   181,   131,   132,   182,   134,   111,   136,
     112,   138,   113,   140,   184,   114,   185,   143,   144,   145,
     186,   147,   183,   149,     0,   151,     0,   153,     0,     0,
       0,     0,     0,     0,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,   172,   173,     0,   174,   175,     0,     0,
     110,     0,   176,   177,     0,     0,   178,   179,   180,   133,
       0,   135,     0,   137,     0,   139,     0,   141,   142,   116,
       0,     0,   117,   146,     0,   148,   118,   150,     0,   152,
       0,     0,   119,   120,   121,   122,   123,     0,     0,   187,
     188,   189,   190,   191,   192,   193,     0,   203,     0,   194,
       0,   195,   196,   197,   198,   199,   190,   191,   192,   193,
       0,     0,     0,   194,     0,   195,   196,   197,   198,   199,
     190,   191,   192,   193,     0,     0,     0,   194,     0,   195,
       0,     0,   198,   199,   190,   191,   192,   193,   192,   193,
       0,   194,     0,   194,     0,     0,   198,   199,   198,   199,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   202,
       0,     0,     0,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
     200,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89
};

static const yytype_int16 yycheck[] =
{
       7,     8,     9,   101,    10,    11,    99,    14,    91,    16,
      93,    18,    95,    20,   100,    98,   100,    23,    24,    25,
     100,    28,   100,    30,    -1,    32,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    -1,    69,    70,    -1,    73,    74,    -1,    -1,
       4,    -1,    79,    80,    -1,    -1,    83,    84,    85,    13,
      -1,    15,    -1,    17,    -1,    19,    -1,    21,    22,   103,
      -1,    -1,   106,    27,    -1,    29,   110,    31,    -1,    33,
      -1,    -1,   116,   117,   118,   119,   120,    -1,    -1,   116,
     117,   118,   102,   103,   104,   105,    -1,   107,    -1,   109,
      -1,   111,   112,   113,   114,   115,   102,   103,   104,   105,
      -1,    -1,    -1,   109,    -1,   111,   112,   113,   114,   115,
     102,   103,   104,   105,    -1,    -1,    -1,   109,    -1,   111,
      -1,    -1,   114,   115,   102,   103,   104,   105,   104,   105,
      -1,   109,    -1,   109,    -1,    -1,   114,   115,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,
      -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,
     184,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   125,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
     116,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    90,    91,    92,    93,    94,    95,    96,    97,   141,
     141,    91,    93,    95,    98,   140,   103,   106,   110,   116,
     117,   118,   119,   120,   136,   137,   138,   139,   136,   136,
     136,   140,   140,   141,   136,   141,   136,   141,   136,   141,
     136,   141,   141,   140,   140,   140,   141,   136,   141,   136,
     141,   136,   141,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   140,   140,   136,   136,   136,   136,   136,   136,
     136,   101,    99,   127,   100,   100,   100,   136,   136,   136,
     102,   103,   104,   105,   109,   111,   112,   113,   114,   115,
     141,   136,   136,   107,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   124,   125,   125,   126,   126,   126,   126,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   132,   132,   132,   132,   133,   133,
     133,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   137,   137,   137,   137,   138,   138,
     139,   139,   139,   139,   140,   140,   140,   140,   141,   141,
     141,   141,   141,   141,   141,   141
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     2,     1,
       1,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* line: label instruction  */
#line 62 "grammar/parser.y"
                         { ; }
#line 1425 "src/parser.c"
    break;

  case 5: /* line: instruction  */
#line 63 "grammar/parser.y"
                         { ; }
#line 1431 "src/parser.c"
    break;

  case 6: /* line: label  */
#line 64 "grammar/parser.y"
                         { ; }
#line 1437 "src/parser.c"
    break;

  case 15: /* data_transfer: MOV register ',' register  */
#line 80 "grammar/parser.y"
    { 
        uint8_t opcode =  0b01000000 | ((yyvsp[-2].int_val) << 3) | ((yyvsp[0].int_val));
        i_emit("MOV", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1447 "src/parser.c"
    break;

  case 16: /* data_transfer: MVI register ',' expr  */
#line 86 "grammar/parser.y"
    { 
        uint8_t opcode =  0b00000110 | ((yyvsp[-2].int_val) << 3);
        i_emit("MVI", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 1457 "src/parser.c"
    break;

  case 17: /* data_transfer: LXI reg_pair ',' expr  */
#line 92 "grammar/parser.y"
    { 
        uint8_t opcode =  0b00000001 | ( (yyvsp[-2].int_val) << 4);
        i_emit("LXI", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1467 "src/parser.c"
    break;

  case 18: /* data_transfer: LDA expr  */
#line 98 "grammar/parser.y"
    { 
        uint8_t opcode =  0b00111010;
        i_emit("LDA", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1477 "src/parser.c"
    break;

  case 19: /* data_transfer: STA expr  */
#line 104 "grammar/parser.y"
    {
        uint8_t opcode =  0b00110010;
        i_emit("STA", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1487 "src/parser.c"
    break;

  case 20: /* data_transfer: LDAX reg_pair  */
#line 110 "grammar/parser.y"
    { 
        uint8_t opcode =  0b00001010 | ( (yyvsp[0].int_val) << 4);
        i_emit("LDAX", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1497 "src/parser.c"
    break;

  case 21: /* data_transfer: STAX reg_pair  */
#line 116 "grammar/parser.y"
    { 
        uint8_t opcode =  0b00000010 | ( (yyvsp[0].int_val) << 4);
        i_emit("STAX", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1507 "src/parser.c"
    break;

  case 22: /* data_transfer: LHLD expr  */
#line 122 "grammar/parser.y"
    { 
        uint8_t opcode =  0b00101010;
        i_emit("LHLD", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1517 "src/parser.c"
    break;

  case 23: /* data_transfer: SHLD expr  */
#line 128 "grammar/parser.y"
    { 
        uint8_t opcode =  0b00100010;
        i_emit("SHLD", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1527 "src/parser.c"
    break;

  case 24: /* data_transfer: XCHG  */
#line 134 "grammar/parser.y"
    { 
        uint8_t opcode =  0b11101011;
        i_emit("XCHG", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1537 "src/parser.c"
    break;

  case 25: /* arithmetic: ADD register  */
#line 143 "grammar/parser.y"
    {
        uint8_t opcode =  0b10000000 | ((yyvsp[0].int_val));
        i_emit("ADD", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1547 "src/parser.c"
    break;

  case 26: /* arithmetic: ADI expr  */
#line 149 "grammar/parser.y"
    {
        uint8_t opcode =  0b11000110;
        i_emit("ADI", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 1557 "src/parser.c"
    break;

  case 27: /* arithmetic: ADC register  */
#line 155 "grammar/parser.y"
    {
        uint8_t opcode =  0b10001000 | ((yyvsp[0].int_val));
        i_emit("ADC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1567 "src/parser.c"
    break;

  case 28: /* arithmetic: ACI expr  */
#line 161 "grammar/parser.y"
    {
        uint8_t opcode =  0b11001110;
        i_emit("ACI", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 1577 "src/parser.c"
    break;

  case 29: /* arithmetic: SUB register  */
#line 167 "grammar/parser.y"
    {
        uint8_t opcode =  0b10010000 | ((yyvsp[0].int_val));
        i_emit("SUB", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1587 "src/parser.c"
    break;

  case 30: /* arithmetic: SUI expr  */
#line 173 "grammar/parser.y"
    {
        uint8_t opcode =  0b11010110;
        i_emit("SUI", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 1597 "src/parser.c"
    break;

  case 31: /* arithmetic: SBB register  */
#line 179 "grammar/parser.y"
    {
        uint8_t opcode =  0b10011000 | ((yyvsp[0].int_val));
        i_emit("SBB", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1607 "src/parser.c"
    break;

  case 32: /* arithmetic: SBI expr  */
#line 185 "grammar/parser.y"
    {
        uint8_t opcode =  0b11011110;
        i_emit("SBI", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 1617 "src/parser.c"
    break;

  case 33: /* arithmetic: INR register  */
#line 191 "grammar/parser.y"
    {
        uint8_t opcode =  0b00000100 | ((yyvsp[0].int_val) << 3);
        i_emit("INR", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1627 "src/parser.c"
    break;

  case 34: /* arithmetic: DCR register  */
#line 197 "grammar/parser.y"
    {
        uint8_t opcode =  0b00000101 | ((yyvsp[0].int_val) << 3);
        i_emit("DCR", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1637 "src/parser.c"
    break;

  case 35: /* arithmetic: INX reg_pair  */
#line 203 "grammar/parser.y"
    {
        uint8_t opcode =  0b00000011 | ((yyvsp[0].int_val) << 4);
        i_emit("INX", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1647 "src/parser.c"
    break;

  case 36: /* arithmetic: DCX reg_pair  */
#line 209 "grammar/parser.y"
    {
        uint8_t opcode =  0b00001011 | ((yyvsp[0].int_val) << 4);
        i_emit("DCX", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1657 "src/parser.c"
    break;

  case 37: /* arithmetic: DAD reg_pair  */
#line 215 "grammar/parser.y"
    {
        uint8_t opcode =  0b00001001 | ((yyvsp[0].int_val) << 4);
        i_emit("DAD", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1667 "src/parser.c"
    break;

  case 38: /* arithmetic: DAA  */
#line 221 "grammar/parser.y"
    {
        uint8_t opcode =  0b00100111;
        i_emit("DAA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1677 "src/parser.c"
    break;

  case 39: /* logical: ANA register  */
#line 230 "grammar/parser.y"
    {
        uint8_t opcode = 0b10100000 | (yyvsp[0].int_val);
        i_emit("ANA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1687 "src/parser.c"
    break;

  case 40: /* logical: ANI expr  */
#line 236 "grammar/parser.y"
    {
        uint8_t opcode = 0b11100110;
        i_emit("ANI", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 1697 "src/parser.c"
    break;

  case 41: /* logical: XRA register  */
#line 242 "grammar/parser.y"
    {
        uint8_t opcode = 0b10101000 | (yyvsp[0].int_val);
        i_emit("XRA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1707 "src/parser.c"
    break;

  case 42: /* logical: XRI expr  */
#line 248 "grammar/parser.y"
    {
        uint8_t opcode = 0b11101110;
        i_emit("XRI", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 1717 "src/parser.c"
    break;

  case 43: /* logical: ORA register  */
#line 254 "grammar/parser.y"
    {
        uint8_t opcode = 0b10110000| (yyvsp[0].int_val);
        i_emit("ORA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1727 "src/parser.c"
    break;

  case 44: /* logical: ORI expr  */
#line 260 "grammar/parser.y"
    {
        uint8_t opcode = 0b11110110;
        i_emit("ORI", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 1737 "src/parser.c"
    break;

  case 45: /* logical: CMP register  */
#line 266 "grammar/parser.y"
    {
        uint8_t opcode = 0b10111000| (yyvsp[0].int_val);
        i_emit("CMP", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1747 "src/parser.c"
    break;

  case 46: /* logical: CPI expr  */
#line 272 "grammar/parser.y"
    {
        uint8_t opcode = 0b11111110;
        i_emit("CPI", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 1757 "src/parser.c"
    break;

  case 47: /* logical: RLC  */
#line 278 "grammar/parser.y"
    {
        uint8_t opcode = 0b00000111;
        i_emit("RLC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1767 "src/parser.c"
    break;

  case 48: /* logical: RRC  */
#line 284 "grammar/parser.y"
    {
        uint8_t opcode = 0b00001111;
        i_emit("RRC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1777 "src/parser.c"
    break;

  case 49: /* logical: RAL  */
#line 290 "grammar/parser.y"
    {
        uint8_t opcode = 0b00010111;
        i_emit("RAL", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1787 "src/parser.c"
    break;

  case 50: /* logical: RAR  */
#line 296 "grammar/parser.y"
    {
        uint8_t opcode = 0b00001111;
        i_emit("RAR", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1797 "src/parser.c"
    break;

  case 51: /* logical: CMA  */
#line 302 "grammar/parser.y"
    {
        uint8_t opcode = 0b00101111;
        i_emit("CMA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1807 "src/parser.c"
    break;

  case 52: /* logical: CMC  */
#line 308 "grammar/parser.y"
    {
        uint8_t opcode = 0b00111111;
        i_emit("CMC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1817 "src/parser.c"
    break;

  case 53: /* logical: STC  */
#line 314 "grammar/parser.y"
    {
        uint8_t opcode = 0b00110111;
        i_emit("STC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 1827 "src/parser.c"
    break;

  case 54: /* branch: JMP expr  */
#line 323 "grammar/parser.y"
    {
        uint8_t opcode = 0b11000011;
        i_emit("JMP", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1837 "src/parser.c"
    break;

  case 55: /* branch: JC expr  */
#line 329 "grammar/parser.y"
    {
        uint8_t opcode = 0b11011010;
        i_emit("JC", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1847 "src/parser.c"
    break;

  case 56: /* branch: JNC expr  */
#line 335 "grammar/parser.y"
    {
        uint8_t opcode = 0b11010010;
        i_emit("JNC", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1857 "src/parser.c"
    break;

  case 57: /* branch: JZ expr  */
#line 341 "grammar/parser.y"
    {
        uint8_t opcode = 0b11001010;
        i_emit("JZ", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1867 "src/parser.c"
    break;

  case 58: /* branch: JNZ expr  */
#line 347 "grammar/parser.y"
    {
        uint8_t opcode = 0b11000010;
        i_emit("JNZ", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1877 "src/parser.c"
    break;

  case 59: /* branch: JP expr  */
#line 353 "grammar/parser.y"
    {
        uint8_t opcode = 0b11110010;
        i_emit("JP", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1887 "src/parser.c"
    break;

  case 60: /* branch: JM expr  */
#line 359 "grammar/parser.y"
    {
        uint8_t opcode = 0b11111010;
        i_emit("JM", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1897 "src/parser.c"
    break;

  case 61: /* branch: JPE expr  */
#line 365 "grammar/parser.y"
    {
        uint8_t opcode = 0b11101010;
        i_emit("JPE", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1907 "src/parser.c"
    break;

  case 62: /* branch: JPO expr  */
#line 371 "grammar/parser.y"
    {
        uint8_t opcode = 0b11100010;
        i_emit("JPO", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1917 "src/parser.c"
    break;

  case 63: /* branch: CALL expr  */
#line 377 "grammar/parser.y"
    {
        uint8_t opcode = 0b11001101;
        i_emit("CALL", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1927 "src/parser.c"
    break;

  case 64: /* branch: CC expr  */
#line 383 "grammar/parser.y"
    {
        uint8_t opcode = 0b11011100;
        i_emit("CC", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1937 "src/parser.c"
    break;

  case 65: /* branch: CNC expr  */
#line 389 "grammar/parser.y"
    {
        uint8_t opcode = 0b11010100;
        i_emit("CNC", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1947 "src/parser.c"
    break;

  case 66: /* branch: CZ expr  */
#line 395 "grammar/parser.y"
    {
        uint8_t opcode = 0b11001100;
        i_emit("CZ", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1957 "src/parser.c"
    break;

  case 67: /* branch: CNZ expr  */
#line 401 "grammar/parser.y"
    {
        uint8_t opcode = 0b11000100;
        i_emit("CNZ", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1967 "src/parser.c"
    break;

  case 68: /* branch: CP expr  */
#line 407 "grammar/parser.y"
    {
        uint8_t opcode = 0b11110100;
        i_emit("CP", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1977 "src/parser.c"
    break;

  case 69: /* branch: CM expr  */
#line 413 "grammar/parser.y"
    {
        uint8_t opcode = 0b11111100;
        i_emit("CM", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1987 "src/parser.c"
    break;

  case 70: /* branch: CPE expr  */
#line 419 "grammar/parser.y"
    {
        uint8_t opcode = 0b11101100;
        i_emit("CPE", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 1997 "src/parser.c"
    break;

  case 71: /* branch: CPO expr  */
#line 425 "grammar/parser.y"
    {
        uint8_t opcode = 0b11100100;
        i_emit("CPO", LC, opcode, (yyvsp[0].int_val) & 0xFF, (yyvsp[0].int_val) >> 8, DIRECT);
        LC = LC + DIRECT;
    }
#line 2007 "src/parser.c"
    break;

  case 72: /* branch: RET  */
#line 431 "grammar/parser.y"
    {
        uint8_t opcode = 0b11001001;
        i_emit("RET", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
#line 2017 "src/parser.c"
    break;

  case 73: /* branch: RC  */
#line 437 "grammar/parser.y"
    {
        uint8_t opcode = 0b11011000;
        i_emit("RC", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
#line 2027 "src/parser.c"
    break;

  case 74: /* branch: RNC  */
#line 443 "grammar/parser.y"
    {
        uint8_t opcode = 0b11010000;
        i_emit("RNC", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
#line 2037 "src/parser.c"
    break;

  case 75: /* branch: RZ  */
#line 449 "grammar/parser.y"
    {
        uint8_t opcode = 0b11001000;
        i_emit("RZ", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
#line 2047 "src/parser.c"
    break;

  case 76: /* branch: RNZ  */
#line 455 "grammar/parser.y"
    {
        uint8_t opcode = 0b11000000;
        i_emit("RNZ", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
#line 2057 "src/parser.c"
    break;

  case 77: /* branch: RP  */
#line 461 "grammar/parser.y"
    {
        uint8_t opcode = 0b11110000;
        i_emit("RP", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
#line 2067 "src/parser.c"
    break;

  case 78: /* branch: RM  */
#line 467 "grammar/parser.y"
    {
        uint8_t opcode = 0b11111000;
        i_emit("RM", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
#line 2077 "src/parser.c"
    break;

  case 79: /* branch: RPE  */
#line 473 "grammar/parser.y"
    {
        uint8_t opcode = 0b11101000;
        i_emit("RPE", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
#line 2087 "src/parser.c"
    break;

  case 80: /* branch: RPO  */
#line 479 "grammar/parser.y"
    {
        uint8_t opcode = 0b11100000;
        i_emit("RPO", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
#line 2097 "src/parser.c"
    break;

  case 81: /* branch: PCHL  */
#line 485 "grammar/parser.y"
    {
        uint8_t opcode = 0b11101001;
        i_emit("PCHL", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2107 "src/parser.c"
    break;

  case 82: /* stack_io: PUSH reg_pair  */
#line 494 "grammar/parser.y"
    {
        uint8_t opcode = 0b11000101 | ((yyvsp[0].int_val) << 4);
        i_emit("PUSH", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2117 "src/parser.c"
    break;

  case 83: /* stack_io: POP reg_pair  */
#line 500 "grammar/parser.y"
    {
        uint8_t opcode = 0b11000001 | ((yyvsp[0].int_val) << 4);
        i_emit("POP", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2127 "src/parser.c"
    break;

  case 84: /* stack_io: XTHL  */
#line 506 "grammar/parser.y"
    {
        uint8_t opcode = 0b11100011;
        i_emit("XTHL", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2137 "src/parser.c"
    break;

  case 85: /* stack_io: SPHL  */
#line 512 "grammar/parser.y"
    {
        uint8_t opcode = 0b11111001;
        i_emit("SPHL", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2147 "src/parser.c"
    break;

  case 86: /* stack_io: IN expr  */
#line 518 "grammar/parser.y"
    {
        uint8_t opcode = 0b11011011;
        i_emit("IN", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 2157 "src/parser.c"
    break;

  case 87: /* stack_io: OUT expr  */
#line 524 "grammar/parser.y"
    {
        uint8_t opcode = 0b11010011;
        i_emit("OUT", LC, opcode, (yyvsp[0].int_val), 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
#line 2167 "src/parser.c"
    break;

  case 88: /* control: EI  */
#line 533 "grammar/parser.y"
    {
        uint8_t opcode =  0b11111011;
        i_emit("EI", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2177 "src/parser.c"
    break;

  case 89: /* control: DI  */
#line 539 "grammar/parser.y"
    {
        uint8_t opcode =  0b11110011;
        i_emit("DI", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2187 "src/parser.c"
    break;

  case 90: /* control: NOP  */
#line 545 "grammar/parser.y"
    { 
        uint8_t opcode =  0;
        i_emit("NOP", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2197 "src/parser.c"
    break;

  case 91: /* control: HLT  */
#line 551 "grammar/parser.y"
    {
        uint8_t opcode =  0b01110110;
        i_emit("HLT", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2207 "src/parser.c"
    break;

  case 92: /* control: RST expr  */
#line 557 "grammar/parser.y"
    {
        // Note: "exp" must evaluate to a number in the range 0bOOO to 0b111
        uint8_t opcode = 0b11000111 | ((yyvsp[0].int_val) << 3);
        i_emit("RST", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
#line 2218 "src/parser.c"
    break;

  case 102: /* label: NAME ':'  */
#line 577 "grammar/parser.y"
               { st_insert(symbolTable, st_new_symbol((yyvsp[-1].string_val), LC, false)); }
#line 2224 "src/parser.c"
    break;

  case 103: /* expr: expr '+' expr  */
#line 582 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) + (yyvsp[0].int_val); }
#line 2230 "src/parser.c"
    break;

  case 104: /* expr: expr '-' expr  */
#line 583 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) - (yyvsp[0].int_val); }
#line 2236 "src/parser.c"
    break;

  case 105: /* expr: expr '*' expr  */
#line 584 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) * (yyvsp[0].int_val); }
#line 2242 "src/parser.c"
    break;

  case 106: /* expr: expr '/' expr  */
#line 585 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) / (yyvsp[0].int_val); }
#line 2248 "src/parser.c"
    break;

  case 107: /* expr: expr MODULO expr  */
#line 586 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) % (yyvsp[0].int_val); }
#line 2254 "src/parser.c"
    break;

  case 108: /* expr: expr AND expr  */
#line 587 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) & (yyvsp[0].int_val); }
#line 2260 "src/parser.c"
    break;

  case 109: /* expr: expr OR expr  */
#line 588 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) | (yyvsp[0].int_val); }
#line 2266 "src/parser.c"
    break;

  case 110: /* expr: expr XOR expr  */
#line 589 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) ^ (yyvsp[0].int_val); }
#line 2272 "src/parser.c"
    break;

  case 111: /* expr: expr SHR expr  */
#line 590 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) >> (yyvsp[0].int_val); }
#line 2278 "src/parser.c"
    break;

  case 112: /* expr: expr SHL expr  */
#line 591 "grammar/parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val) << (yyvsp[0].int_val); }
#line 2284 "src/parser.c"
    break;

  case 113: /* expr: term  */
#line 592 "grammar/parser.y"
           { }
#line 2290 "src/parser.c"
    break;

  case 114: /* term: '(' expr ')'  */
#line 596 "grammar/parser.y"
                   { (yyval.int_val) = (yyvsp[-1].int_val); }
#line 2296 "src/parser.c"
    break;

  case 115: /* term: '-' expr  */
#line 597 "grammar/parser.y"
                            { (yyval.int_val) = (yyvsp[0].int_val) * (-1); }
#line 2302 "src/parser.c"
    break;

  case 116: /* term: NOT expr  */
#line 598 "grammar/parser.y"
                { (yyval.int_val) = ~(yyvsp[0].int_val); }
#line 2308 "src/parser.c"
    break;

  case 117: /* term: primary  */
#line 599 "grammar/parser.y"
                { (yyval.int_val) = (yyvsp[0].int_val); }
#line 2314 "src/parser.c"
    break;

  case 118: /* primary: NAME  */
#line 605 "grammar/parser.y"
    { 
        Symbol *label = st_lookup(symbolTable, (yyvsp[0].string_val));
        // TODO: if lookup is null then insert label's index to unresolved jumps' list
        (yyval.int_val) =  -1;
    }
#line 2324 "src/parser.c"
    break;

  case 119: /* primary: immediate  */
#line 610 "grammar/parser.y"
                { (yyval.int_val) = (yyvsp[0].int_val); }
#line 2330 "src/parser.c"
    break;

  case 120: /* immediate: HEX_NUMBER  */
#line 615 "grammar/parser.y"
                    { (yyval.int_val) = (yyvsp[0].int_val); }
#line 2336 "src/parser.c"
    break;

  case 121: /* immediate: DEC_NUMBER  */
#line 616 "grammar/parser.y"
                    { (yyval.int_val) = (yyvsp[0].int_val); }
#line 2342 "src/parser.c"
    break;

  case 122: /* immediate: OCT_NUMBER  */
#line 617 "grammar/parser.y"
                    { (yyval.int_val) = (yyvsp[0].int_val); }
#line 2348 "src/parser.c"
    break;

  case 123: /* immediate: BIN_NUMBER  */
#line 618 "grammar/parser.y"
                    { (yyval.int_val) = (yyvsp[0].int_val); }
#line 2354 "src/parser.c"
    break;

  case 124: /* reg_pair: B  */
#line 622 "grammar/parser.y"
        { (yyval.int_val) = 0; }
#line 2360 "src/parser.c"
    break;

  case 125: /* reg_pair: D  */
#line 623 "grammar/parser.y"
        { (yyval.int_val) = 1; }
#line 2366 "src/parser.c"
    break;

  case 126: /* reg_pair: H  */
#line 624 "grammar/parser.y"
        { (yyval.int_val) = 2; }
#line 2372 "src/parser.c"
    break;

  case 127: /* reg_pair: SP  */
#line 625 "grammar/parser.y"
         { (yyval.int_val) = 3; }
#line 2378 "src/parser.c"
    break;

  case 128: /* register: B  */
#line 629 "grammar/parser.y"
        { (yyval.int_val) = 0; }
#line 2384 "src/parser.c"
    break;

  case 129: /* register: C  */
#line 630 "grammar/parser.y"
        { (yyval.int_val) = 1; }
#line 2390 "src/parser.c"
    break;

  case 130: /* register: D  */
#line 631 "grammar/parser.y"
        { (yyval.int_val) = 2; }
#line 2396 "src/parser.c"
    break;

  case 131: /* register: E  */
#line 632 "grammar/parser.y"
        { (yyval.int_val) = 3; }
#line 2402 "src/parser.c"
    break;

  case 132: /* register: H  */
#line 633 "grammar/parser.y"
        { (yyval.int_val) = 4; }
#line 2408 "src/parser.c"
    break;

  case 133: /* register: L  */
#line 634 "grammar/parser.y"
        { (yyval.int_val) = 5; }
#line 2414 "src/parser.c"
    break;

  case 134: /* register: M  */
#line 635 "grammar/parser.y"
        { (yyval.int_val) = 6; }
#line 2420 "src/parser.c"
    break;

  case 135: /* register: A  */
#line 636 "grammar/parser.y"
        { (yyval.int_val) = 7; }
#line 2426 "src/parser.c"
    break;


#line 2430 "src/parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 638 "grammar/parser.y"


void yyerror(const char* msg) {
    printf("Error: LOL: %s\n", msg);
}

int main (int argc, char **argv) {
	if (argc == 3) {
		if ( !(yyin = fopen(argv[1], "r")) ) {
			fprintf(stderr, "Cannot read file %s.\n", argv[1]);
			perror("");
			return 1;
		}
		if ( !(yyout = fopen(argv[2], "w")) ) {
			fprintf(stderr, "Cannot write file %s.\n", argv[2]);
			perror("");
			return 1;
		}
	} 
	else if (argc == 2) {
		if ( !(yyin = fopen(argv[1], "r")) ) {
			fprintf(stderr, "Cannot read file %s.\n", argv[1]);
			perror("");
            return 1;
		}
	} 
	else {
		yyin = stdin;
	}
    
    symbolTable = st_new(32, hash);

    yyparse();
    st_print(symbolTable);
    i_printInstructions();
    return 0;
}
