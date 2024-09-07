%{

#include <stdio.h>
#include <string.h>
#include <stdint.h>

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
    char    char_val;
    uint16_t int_val;
    uint8_t opcode;
}
/* CONSTANTS */
%token<string_val>  MOV MVI LXI LDA STA LHLD SHLD LDAX STAX XCHG
%token<string_val>  ADD ADI ADC ACI SUB SUI SBB SBI INR DCR INX DCX DAD DAA
%token<string_val>  ANA ANI XRA XRI ORA ORI CMP CPI RLC RRC RAL RAR CMA CMC STC
%token<string_val>  JMP JC JNC JZ JNZ JP JM JPE JPO CALL CC CNC CZ CNZ CP CM CPE CPO RET RC RNC RZ RNZ RP RM RPE RPO
%token<string_val>  PUSH POP XTHL SPHL IN OUT EI DI HLT NOP RST
%token<string_val>  ORG END EQU DB DW DS IF ENDIF SET PCHL
%token<string_val>  A B C D E H L M
%token<string_val>  TOK_EOL TOK_EOF
%token<string_val>  ',' ':' '+' '-' '*' '/' '(' ')' '$' MODULO NOT AND OR XOR SHR SHL
%token<string_val> NAME
%token<int_val> HEX_NUMBER DEC_NUMBER OCT_NUMBER BIN_NUMBER
%token<string_val> STR_CONST CHAR

%type<int_val>register reg_pair

%left OR XOR
%left AND
%left '+' '-'
%left '*' '/' MODULO SHR SHL
%right NOT UMINUS
%left '(' ')'

%%

program: program line | %empty;

line
    : label instruction TOK_EOL { ; }
    | instruction TOK_EOL       { ; }
    | label TOK_EOL             { ; }
    | TOK_EOL                   { ; }
    ;

instruction
    : data_transfer 
    | arithmetic 
    | logical 
    | branch 
    | stack_io 
    | control 
    ;

data_transfer
    : MOV register[reg1] ',' register[reg2]
    | MVI register ',' expr
    | LXI reg_pair ',' expr
    | LDA expr
    | STA expr
    | LDAX reg_pair
    | STAX reg_pair
    | LHLD expr
    | SHLD expr
    | XCHG
    ;

arithmetic
    : ADD  register
    | ADI expr
    | ADC register
    | ACI expr
    | SUB register
    | SUI expr
    | SBB register
    | SBI expr
    | INR register
    | DCR expr
    | INX reg_pair
    | DCX reg_pair
    | DAD reg_pair
    | DAA
    ;

logical
    : ANA register
    | ANI expr
    | XRA register
    | XRI expr
    | ORA register
    | ORI expr
    | CMP register
    | CPI expr
    | RLC
    | RRC
    | RAL
    | RAR
    | CMA
    | CMC
    | STC
    ;

branch
    : JMP expr
    | JC expr
    | JNC expr
    | JZ expr
    | JNZ expr
    | JP expr
    | JM expr
    | JPE expr
    | JPO expr
    | CALL expr
    | CC expr
    | CNC expr
    | CZ expr
    | CNZ expr
    | CP expr
    | CM expr
    | CPE expr
    | CPO expr
    | RET
    | RC
    | RNC
    | RZ
    | RNZ
    | RP
    | RM
    | RPE
    | RPO
    | PCHL
    ;

stack_io
    : PUSH reg_pair
    | POP reg_pair
    | XTHL
    | SPHL
    | IN expr
    | OUT expr
    ;

control
    : EI
    | DI
    | NOP
    | HLT
    | RST expr
    ;

label: NAME ':';


expr
    : expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr MODULO expr
    | expr AND expr
    | expr OR expr
    | expr XOR expr
    | expr SHR expr
    | expr SHL expr
    | term
    ;

term
    : '(' expr ')'
    | '-' expr %prec UMINUS
    | NOT expr
    | primary
    ;


primary
    : address
    ;

address: NAME | immediate; 

immediate
    : HEX_NUMBER
    | DEC_NUMBER
    | OCT_NUMBER
    | BIN_NUMBER
    ;

reg_pair: B { $reg_pair = 0; } | D { $reg_pair = 1; };


register
    : B { $register = 0; }
    | C { $register = 1; }
    | D { $register = 2; }
    | E { $register = 3; }
    | H { $register = 4; }
    | L { $register = 5; }
    | M { $register = 6; }
    | A { $register = 7; }
    ;
%%

void yyerror(const char* msg) {
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