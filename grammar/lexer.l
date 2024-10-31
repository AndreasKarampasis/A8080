%option noyywrap noinput nounput yylineno warn 
/* caseless */
%option outfile = "src/lexer.c" header-file="include/lexer.h"

%{
#include <stdlib.h>
#include "parser.h"
int error_line;
#define MAX_STR_CONST 1025
char string_buf[MAX_STR_CONST];
char* string_buf_ptr;
%}

NAME			[a-zA-Z?@]+
%x STRING

%%

"MOV"	{ return MOV;  }
"MVI"	{ return MVI;  }
"LXI"	{ return LXI;  }
"LDA"	{ return LDA;  }
"STA"	{ return STA;  }
"LHLD"	{ return LHLD; }
"SHLD"	{ return SHLD; }
"LDAX"	{ return LDAX; }
"STAX"	{ return STAX; }
"XCHG"	{ return XCHG; }

"ADD"	{ return ADD; }
"ADI"	{ return ADI; }
"ADC"	{ return ADC; }
"ACI"	{ return ACI; }
"SUB"	{ return SUB; }
"SUI"	{ return SUI; }
"SBB"	{ return SBB; }
"SBI"	{ return SBI; }
"INR"	{ return INR; }
"DCR"	{ return DCR; }
"INX"	{ return INX; }
"DCX"	{ return DCX; }
"DAD"	{ return DAD; }
"DAA"   { return DAA; }

"ANA"	{ return ANA; }
"ANI"	{ return ANI; }
"XRA"	{ return XRA; }
"XRI"	{ return XRI; }
"ORA"	{ return ORA; }
"ORI"	{ return ORI; }
"CMP"	{ return CMP; }
"CPI"	{ return CPI; }
"RLC"	{ return RLC; }
"RRC"	{ return RRC; }
"RAL"	{ return RAL; }
"RAR"	{ return RAR; }
"CMA"	{ return CMA; }
"CMC"	{ return CMC; }
"STC"	{ return STC; }

"JMP"	{ return JMP; }
"JC"	{ return JC; }
"JNC"	{ return JNC; }
"JZ"	{ return JNC; }
"JNZ"	{ return JNZ; }
"JP"	{ return JP; }
"JM"	{ return JM; }
"JPE"	{ return JPE; }
"JPO"	{ return JPO; }
"CALL"	{ return CALL; }
"CC"	{ return CC; }
"CNC"	{ return CNC; }
"CZ"	{ return CZ; }
"CNZ"	{ return CNZ; }
"CP"	{ return CP; }
"CM"	{ return CM; }
"CPE"	{ return CPE; }
"CPO"	{ return CPO; }
"RET"	{ return RET; }
"RC"	{ return RC; }
"RNC"	{ return RNC; }
"RZ"	{ return RZ; }
"RNZ"	{ return RNZ; }
"RP"	{ return RP; }
"RM"	{ return RM; }
"RPE"	{ return RPE; }
"RPO"	{ return RPO; }
"PCHL"  { return PCHL; }

"PUSH"	{ return PUSH; }
"POP"	{ return POP; }
"XTHL"	{ return XTHL; }
"SPHL"	{ return SPHL; }
"IN"	{ return IN; }
"OUT"	{ return OUT; }
"EI"	{ return EI; }
"DI"	{ return DI; }
"HLT"	{ return HLT; }
"NOP"	{ return NOP; }
"RST"   { return RST; }

"A"	{ return A; }
"B"	{ return B; }
"C"	{ return C; }
"D"	{ return D; }
"E"	{ return E; }
"H"	{ return H; }
"L"	{ return L; }
"M"     { return M; }
"SP"     { return SP; }

"ORG"   { return ORG; }
"END"   { return END; }
"EQU"   { return EQU; }
"DB"    { return DB; }
"DW"    { return DW; }
"DS"    { return DS; }
"IF"    { return IF; }
"ENDIF" { return ENDIF; }
"SET"   { return SET; }

","     { return ','; }
":"     { return ':'; }
"("     { return '('; }
")"     { return ')'; }
"$"     { return '$'; }
"+"     { return '+'; }
"-"     { return '-'; }
"*"     { return '*'; }
"/"     { return '/'; }
"MOD"   { return MODULO; }
"NOT"   { return NOT; }
"AND"   { return AND; }
"OR"    { return OR; }      
"XOR"   { return XOR; }
"SHR"   { return SHR; }
"SHL"   { return SHL; }

[0-9][0-9a-fA-F]*[hH]   { yylval.int_val = strtol(yytext, NULL, 16); return HEX_NUMBER; }
[0-9]+[dD]?             { yylval.int_val = strtol(yytext, NULL, 10); return DEC_NUMBER; }
[0-8]+[oO]              { yylval.int_val = strtol(yytext, NULL, 10); return OCT_NUMBER; }
[0-1]+[bB]              { yylval.int_val = strtol(yytext, NULL, 2); return BIN_NUMBER; }
{NAME}		        { yylval.string_val = strdup(yytext); return NAME; }

\"                      { string_buf_ptr = string_buf; error_line = yylineno; BEGIN(STRING); }
<STRING>\"              {
                                /* saw closing quote - all done */
                                BEGIN(INITIAL);
                                *string_buf_ptr = '\0';
                                yylval.string_val = strdup(string_buf);
                                return STR_CONST;
                        }

<STRING>\n              {
                                /* error - unterminated string constant */
                                fprintf(yyout, "[line %d] Error: missing terminating \" character.\n", error_line);
                                yyterminate();
                        }

<STRING>\\[0-7]{1,3}    {
                                /* octal escape sequence */
                                int result;
                                (void) sscanf(yytext + 1, "%o", &result);
                                if (result > 0xff) {
                                        /* error, constant is out-of-bounds */
                                        yyterminate();
                                }
                                *string_buf_ptr++ = result;
                        }
<STRING>\\[0-9]+        {
                                /* generate error - bad escape sequence */
                                fprintf(yyout, "[line %d] Error: unkown escape sequence '%s'\n", yylineno, yytext);
                                // yyerror("");
                                yyterminate();

                        } 
<STRING>\\n             *string_buf_ptr++ = '\n';
<STRING>\\\\            *string_buf_ptr++ = '\\';
<STRING>\\'             *string_buf_ptr++ = '\'';
<STRING>\\\"            *string_buf_ptr++ = '"';
<STRING>\\a             *string_buf_ptr++ = '\a';
<STRING>\\b             *string_buf_ptr++ = '\b';
<STRING>\\f             *string_buf_ptr++ = '\f';
<STRING>\\\n            *string_buf_ptr++ = '\n';
<STRING>\\r             *string_buf_ptr++ = '\r';
<STRING>\\t             *string_buf_ptr++ = '\t';
<STRING>\\v             *string_buf_ptr++ = '\v';
<STRING>\\.             { 
                                fprintf(yyout, "[line %d] Error: unkown escape sequence '%s'\n", error_line, yytext); 
                                // yyerror("");
                                yyterminate();
                        }
<STRING>[^\\\n\"]+      {
                                char* yptr = yytext;
                                while (*yptr) *string_buf_ptr++ = *yptr++;
                        }
";"[^{}\n]*     /* eat up one-line comments */
[\n]		{ return TOK_EOL; }

[ \t]+		{ /* eat up whitespace */ }
.		{ fprintf(stderr, "Unrecognised character %s at line %d\n", yytext, yylineno); }


%%

