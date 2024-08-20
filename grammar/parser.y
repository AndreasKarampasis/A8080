%{
#include <stdio.h>
#include <string.h>
void yyerror (const char* msg);
extern int yylex(void);
extern int yylineno;
extern int yyleng;
extern char *yytext;
extern FILE *yyin;
extern FILE *yyout;
%}


%defines "include/parser.h"
%output "src/parser.c"

%start program
%union {
    char*   string_val;
    int     int_val;
}

%type<string_val> opcode

%token<string_val>  MOV MVI LXI LDA STA LHLD SHLD LDAX STAX XCHG
%token<string_val> ADD ADI ADC ACI SUB SUI SBB SBI INR DCR INX DCX DAD
%token<string_val>  ANA ANI XRA XRI ORA ORI CMP CPI RLC RRC RAL RAR CMA CMC STC
%token<string_val>  JMP JC JNC JZ JNZ JP JM JPE JPO CALL CC CNC CZ CNZ CP CM CPE CPO RET RC RNC RZ RNZ RP RM RPE RPO
%token<string_val>  PUSH POP XTHL SPHL IN OUT EI DI HLT NOP
%token<string_val>  ORG END EQU DB DW DS IF ENDIF SET
%token<string_val>  A B C D E H L PC SP
%token<string_val>  COMMA COLON EOL PLUS MINUS STAR SLASH L_PAREN R_PAREN DOLLAR
%token<string_val> NAME
%token<int_val> NUMBER
%token<string_val> STR_CONST

%left PLUS MINUS
%left STAR SLASH

%%

program: lines ;

lines
    :   line
    |   line lines
    |   stmt
    ;

line
    :   stmt EOL
    |   EOL
    |   error EOL
    ;


stmt
    :   label instruction
    |   label directive expr
    |   label
    |   instruction
    |   directive expr
    ;

expr
    : expr PLUS expr
    | expr MINUS expr
    | expr STAR expr
    | expr SLASH expr
    | operand
    ;

label
    : NAME COLON
    ;

instruction
    :   opcode
    |   opcode operand
    |   opcode operand COMMA operand { printf("%s\n", $opcode); }


operand
    :   register
    |   NUMBER
    |   STR_CONST
    |   NAME

directive
    : ORG | END | EQU | DB | DW | DS | IF | ENDIF | SET
    ;

register
    :   A | B | C | D | E | H | L | PC | SP
    ;

opcode:
    MOV {$opcode = strdup("MOV"); }
  | MVI{$opcode = strdup("MVI"); }
  | LXI
  | LDA
  | STA
  | LHLD
  | SHLD
  | LDAX
  | STAX
  | XCHG
  | ADD
  | ADI
  | ADC
  | ACI
  | SUB
  | SUI
  | SBB
  | SBI
  | INR
  | DCR
  | INX
  | DCX
  | DAD
  | ANA
  | ANI
  | XRA
  | XRI
  | ORA
  | ORI
  | CMP
  | CPI
  | RLC
  | RRC
  | RAL
  | RAR
  | CMA
  | CMC
  | STC
  | JMP
  | JC
  | JNC
  | JZ
  | JNZ
  | JP
  | JM
  | JPE
  | JPO
  | CALL
  | CC
  | CNC
  | CZ
  | CNZ
  | CP
  | CM
  | CPE
  | CPO
  | RET
  | RC
  | RNC
  | RZ
  | RNZ
  | RP
  | RM
  | RPE
  | RPO
  | PUSH
  | POP
  | XTHL
  | SPHL
  | IN
  | OUT
  | EI
  | DI
  | HLT
  | NOP
  ;

%%

void yyerror(const char* msg) {
    fprintf(stderr, "\x1B[31m%s:\x1B[0m unexpected %s at line %d\n", msg, yytext, yylineno);
    fprintf(stderr, "    %d | %s\n", yylineno, yytext);
    for (int i = 0; i < yyleng + 7; i++) {
        fputc(' ', stderr); // Print spaces for alignment
    }
    fprintf(stderr, "^-- Here.\n");
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

    yyparse();
    return 0;
}