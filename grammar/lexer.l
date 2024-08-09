%option noyywrap noinput nounput yylineno warn caseless
%option outfile = "src/lexer.c" header-file="include/lexer.h"

%{
#include <stdlib.h>
enum type {OPCODE, STR_CONST, INT_CONST, BINARY_CONST, HEX_CONST};
struct token {
	int line;
	enum type tokenType;
	char* lexeme;
	union {
		char* str_val;
		int int_val;
	} value;
};
%}

NAME			[a-zA-Z?@]+
%%

"MOV"	{printf("INSTRUCTION: MOV\n");}
"MVI"	{printf("INSTRUCTION: MVI\n");}
"LXI"	{printf("INSTRUCTION: LXI\n");}
"LDA"	{printf("INSTRUCTION: LDA\n");}
"STA"	{printf("INSTRUCTION: STA\n");}
"LHLD"	{printf("INSTRUCTION: LHLD\n");}
"SHLD"	{printf("INSTRUCTION: SHLD\n");}
"LDAX"	{printf("INSTRUCTION: LDAX\n");}
"STAX"	{printf("INSTRUCTION: STAX\n");}
"XCHG"	{printf("INSTRUCTION: XCHG\n");}

"ADD"	{printf("INSTRUCTION: %s\n", yytext);}
"ADI"	{printf("INSTRUCTION: %s\n", yytext);}
"ADC"	{printf("INSTRUCTION: %s\n", yytext);}
"ACI"	{printf("INSTRUCTION: %s\n", yytext);}
"SUB"	{printf("INSTRUCTION: %s\n", yytext);}
"SUI"	{printf("INSTRUCTION: %s\n", yytext);}
"SBB"	{printf("INSTRUCTION: %s\n", yytext);}
"SBI"	{printf("INSTRUCTION: %s\n", yytext);}
"INR"	{printf("INSTRUCTION: %s\n", yytext);}
"DCR"	{printf("INSTRUCTION: %s\n", yytext);}
"INX"	{printf("INSTRUCTION: %s\n", yytext);}
"DCX"	{printf("INSTRUCTION: %s\n", yytext);}
"DAD"	{printf("INSTRUCTION: %s\n", yytext);}

"ANA"	{printf("INSTRUCTION: %s\n", yytext);}
"ANI"	{printf("INSTRUCTION: %s\n", yytext);}
"XRA"	{printf("INSTRUCTION: %s\n", yytext);}
"XRI"	{printf("INSTRUCTION: %s\n", yytext);}
"ORA"	{printf("INSTRUCTION: %s\n", yytext);}
"ORI"	{printf("INSTRUCTION: %s\n", yytext);}
"CMP"	{printf("INSTRUCTION: %s\n", yytext);}
"CPI"	{printf("INSTRUCTION: %s\n", yytext);}
"RLC"	{printf("INSTRUCTION: %s\n", yytext);}
"RRC"	{printf("INSTRUCTION: %s\n", yytext);}
"RAL"	{printf("INSTRUCTION: %s\n", yytext);}
"RAR"	{printf("INSTRUCTION: %s\n", yytext);}
"CMA"	{printf("INSTRUCTION: %s\n", yytext);}
"CMC"	{printf("INSTRUCTION: %s\n", yytext);}
"STC"	{printf("INSTRUCTION: %s\n", yytext);}

"JMP"	{printf("INSTRUCTION: %s\n", yytext);}
"JC"	{printf("INSTRUCTION: %s\n", yytext);}
"JNC"	{printf("INSTRUCTION: %s\n", yytext);}
"JZ"	{printf("INSTRUCTION: %s\n", yytext);}
"JNZ"	{printf("INSTRUCTION: %s\n", yytext);}
"JP"	{printf("INSTRUCTION: %s\n", yytext);}
"JM"	{printf("INSTRUCTION: %s\n", yytext);}
"JPE"	{printf("INSTRUCTION: %s\n", yytext);}
"JPO"	{printf("INSTRUCTION: %s\n", yytext);}
"CALL"	{printf("INSTRUCTION: %s\n", yytext);}
"CC"	{printf("INSTRUCTION: %s\n", yytext);}
"CNC"	{printf("INSTRUCTION: %s\n", yytext);}
"CZ"	{printf("INSTRUCTION: %s\n", yytext);}
"CNZ"	{printf("INSTRUCTION: %s\n", yytext);}
"CP"	{printf("INSTRUCTION: %s\n", yytext);}
"CM"	{printf("INSTRUCTION: %s\n", yytext);}
"CPE"	{printf("INSTRUCTION: %s\n", yytext);}
"CPO"	{printf("INSTRUCTION: %s\n", yytext);}
"RET"	{printf("INSTRUCTION: %s\n", yytext);}
"RC"	{printf("INSTRUCTION: %s\n", yytext);}
"RNC"	{printf("INSTRUCTION: %s\n", yytext);}
"RZ"	{printf("INSTRUCTION: %s\n", yytext);}
"RNZ"	{printf("INSTRUCTION: %s\n", yytext);}
"RP"	{printf("INSTRUCTION: %s\n", yytext);}
"RM"	{printf("INSTRUCTION: %s\n", yytext);}
"RPE"	{printf("INSTRUCTION: %s\n", yytext);}
"RPO"	{printf("INSTRUCTION: %s\n", yytext);}

"PUSH"	{printf("INSTRUCTION: %s\n", yytext);}
"POP"	{printf("INSTRUCTION: %s\n", yytext);}
"XTHL"	{printf("INSTRUCTION: %s\n", yytext);}
"SPHL"	{printf("INSTRUCTION: %s\n", yytext);}
"IN"	{printf("INSTRUCTION: %s\n", yytext);}
"OUT"	{printf("INSTRUCTION: %s\n", yytext);}
"EI"	{printf("INSTRUCTION: %s\n", yytext);}
"DI"	{printf("INSTRUCTION: %s\n", yytext);}
"HLT"	{printf("INSTRUCTION: %s\n", yytext);}
"NOP"	{printf("INSTRUCTION: %s\n", yytext);}

"A"		{ printf("REGISTER: %s\n", yytext);}
"B"		{ printf("REGISTER: %s\n", yytext);}
"C"		{ printf("REGISTER: %s\n", yytext);}
"D"		{ printf("REGISTER: %s\n", yytext);}
"E"		{ printf("REGISTER: %s\n", yytext);}
"H"		{ printf("REGISTER: %s\n", yytext);}
"L"		{ printf("REGISTER: %s\n", yytext);}
"PC"	{ printf("REGISTER: %s\n", yytext);}
"SP"	{ printf("REGISTER: %s\n", yytext);}

0b[0-1]+		{ printf("BINARY NUMBER: %s = %ld\n", yytext, strtol(yytext+2, NULL, 2)); }
[0-9]+			{printf("NUMBER: %s\n = %ld", yytext, strtol(yytext, NULL, 10)); }
0x[a-f0-9]+		{printf("HEX NUMBER: %s = %ld\n", yytext, strtol(yytext+2, NULL, 16));}
{NAME}			{printf("NAME: %s\n", yytext);}

","			{ printf("COMMA"); }
":"			{ printf("COLON\n"); }
";"[^{}\n]*  /* eat up one-line comments */
[\n]		{ }
[ \t]+		{ /* eat up whitespace */ }
.			{ fprintf(stderr, "Unrecognised character %s at line %d\n", yytext, yylineno); }


%%
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

    yylex();
    return 0;
}
