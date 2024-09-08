%{
#include "symboltable.h"

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

struct instruction {
    uint8_t opcode;
    uint16_t adress;
    bool is_data;
};

Symboltable *labelTable;
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
%token<opcode>  MOV MVI LXI LDA STA LHLD SHLD LDAX STAX XCHG
%token<opcode>  ADD ADI ADC ACI SUB SUI SBB SBI INR DCR INX DCX DAD DAA
%token<opcode>  ANA ANI XRA XRI ORA ORI CMP CPI RLC RRC RAL RAR CMA CMC STC
%token<opcode>  JMP JC JNC JZ JNZ JP JM JPE JPO CALL CC CNC CZ CNZ CP CM CPE CPO RET RC RNC RZ RNZ RP RM RPE RPO
%token<opcode>  PUSH POP XTHL SPHL IN OUT EI DI HLT NOP RST
%token<opcode>  ORG END EQU DB DW DS IF ENDIF SET PCHL
%token<int_val>  A B C D E H L M SP
%token<string_val>  TOK_EOL
%token<string_val>  ',' ':' '+' '-' '*' '/' '(' ')' '$' MODULO NOT AND OR XOR SHR SHL
%token<string_val> NAME
%token<int_val> HEX_NUMBER DEC_NUMBER OCT_NUMBER BIN_NUMBER
%token<string_val> STR_CONST CHAR

%type<int_val>register reg_pair
%type<opcode> data_transfer arithmetic logical branch stack_io control
%type<int_val> immediate primary


%left OR XOR
%left AND
%left '+' '-'
%left '*' '/' MODULO SHR SHL
%right NOT UMINUS
%left '(' ')'

%%
program: program line TOK_EOL| %empty;

line
    : label instruction  { ; }
    | instruction        { ; }
    | label              { ; }
    | %empty
    ;

instruction
    : data_transfer 
    | arithmetic 
    | logical 
    | branch 
    | stack_io 
    | control 
    | directives
    ;

data_transfer
    : MOV register[reg1] ',' register[reg2]
    { 
        uint8_t opcode =  0b01000000 | ($reg1 << 3) | ($reg2);
        printf("MOV %02X\n", opcode);
    }
    | MVI register ',' expr
    { 
        uint8_t opcode =  0b00000110 | ($register << 3);
        printf("MVI %02X\n", opcode);
    }
    | LXI reg_pair ',' expr
    { 
        uint8_t opcode =  0b00000001 | ( $reg_pair << 4);
        printf("LXI %02X\n", opcode);
    }
    | LDA expr
    { 
        uint8_t opcode =  0b00111010;
        printf("LDA %02X\n", opcode);
    }
    | STA expr
    {
        uint8_t opcode =  0b00110010;
        printf("STA %02X\n", opcode); 
    }
    | LDAX reg_pair
    { 
        uint8_t opcode =  0b00001010 | ( $reg_pair << 4);
        printf("LDAX %02X\n", opcode);
    }
    | STAX reg_pair
    { 
        uint8_t opcode =  0b00000010 | ( $reg_pair << 4);
        printf("STAX %02X\n", opcode);
    }
    | LHLD expr
    { 
        uint8_t opcode =  0b00101010;
        printf("LHLD %02X\n", opcode);
    }
    | SHLD expr
    { 
        uint8_t opcode =  0b00100010;
        printf("SHLD %02X\n", opcode);
    }
    | XCHG
    { 
        uint8_t opcode =  0b11101011;
        printf("XCHG %02X\n", opcode);
    }
    ;

arithmetic
    : ADD register
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
    { 
        uint8_t opcode =  0;
        printf("NOP %02X\n", opcode);
    }
    | HLT
    | RST expr
    ;

directives
    : ORG
    | END
    | EQU
    | DB expr
    | DW
    | DS
    | IF 
    | ENDIF
    | SET 

label
    : NAME ':' 
    {
        // Symbol *lab = ;
        st_insert(labelTable, st_create_label($NAME, false));
    };


expr
    : expr[expr1] '+' expr[expr2]
    | expr[expr1] '-' expr[expr2]
    | expr[expr1] '*' expr[expr2]
    | expr[expr1] '/' expr[expr2]
    | expr[expr1] MODULO expr[expr2]
    | expr[expr1] AND expr[expr2]
    | expr[expr1] OR expr[expr2]
    | expr[expr1] XOR expr[expr2]
    | expr[expr1] SHR expr[expr2]
    | expr[expr1] SHL expr[expr2]
    | term
    ;

term
    : '(' expr ')'
    | '-' expr %prec UMINUS
    | NOT expr
    | primary
    ;


primary
    : NAME { $$ = 0; }
    | immediate { $primary = $immediate; }; 
    ;


immediate
    : HEX_NUMBER    { $immediate = $HEX_NUMBER; }
    | DEC_NUMBER    { $immediate = $DEC_NUMBER; }
    | OCT_NUMBER    { $immediate = $OCT_NUMBER; }
    | BIN_NUMBER    { $immediate = $BIN_NUMBER; }
    ;

reg_pair
    : B { $reg_pair = 0; } 
    | D { $reg_pair = 1; }
    | H { $reg_pair = 2; }
    | SP { $reg_pair = 3; }
    ;

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
    
    labelTable = st_new(32, hash);
    yyparse();
    st_print(labelTable);
    return 0;
}