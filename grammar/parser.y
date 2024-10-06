%{
#include "symboltable.h"
#include "instruction.h"

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

%token<string_val>  MOV MVI LXI LDA STA LHLD SHLD LDAX STAX XCHG
%token<string_val>  ADD ADI ADC ACI SUB SUI SBB SBI INR DCR INX DCX DAD DAA
%token<string_val>  ANA ANI XRA XRI ORA ORI CMP CPI RLC RRC RAL RAR CMA CMC STC
%token<string_val>  JMP JC JNC JZ JNZ JP JM JPE JPO CALL CC CNC CZ CNZ CP CM CPE CPO RET RC RNC RZ RNZ RP RM RPE RPO
%token<string_val>  PUSH POP XTHL SPHL IN OUT EI DI HLT NOP RST
%token<string_val>  ORG END EQU DB DW DS IF ENDIF SET PCHL
%token<int_val>  A B C D E H L M SP
%token<string_val>  TOK_EOL
%token<string_val>  ',' ':' '+' '-' '*' '/' '(' ')' '$' MODULO NOT AND OR XOR SHR SHL
%token<string_val> NAME
%token<int_val> HEX_NUMBER DEC_NUMBER OCT_NUMBER BIN_NUMBER
%token<string_val> STR_CONST CHAR

%type<int_val> register reg_pair
%type<opcode>  data_transfer arithmetic logical branch stack_io control
%type<int_val> immediate primary term expr


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
        i_emit("MOV", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("MOV %02X\n", opcode);
    }
    | MVI register ',' expr
    { 
        uint8_t opcode =  0b00000110 | ($register << 3);
        i_emit("MVI", LC, opcode, $expr, 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
        printf("MVI %02X %02X\n", opcode, $expr);
    }
    | LXI reg_pair ',' expr
    { 
        uint8_t opcode =  0b00000001 | ( $reg_pair << 4);
        i_emit("LXI", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
        printf("LXI %02X\n", opcode);
    }
    | LDA expr
    { 
        uint8_t opcode =  0b00111010;
        i_emit("LDA", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
        printf("LDA %02X\n", opcode);
    }
    | STA expr
    {
        uint8_t opcode =  0b00110010;
        i_emit("STA", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
        printf("STA %02X\n", opcode); 
    }
    | LDAX reg_pair
    { 
        uint8_t opcode =  0b00001010 | ( $reg_pair << 4);
        i_emit("LDAX", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("LDAX %02X\n", opcode);
    }
    | STAX reg_pair
    { 
        uint8_t opcode =  0b00000010 | ( $reg_pair << 4);
        i_emit("STAX", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("STAX %02X\n", opcode);
    }
    | LHLD expr
    { 
        uint8_t opcode =  0b00101010;
        i_emit("LHLD", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
        printf("LHLD %02X\n", opcode);
    }
    | SHLD expr
    { 
        uint8_t opcode =  0b00100010;
        i_emit("SHLD", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
        printf("SHLD %02X\n", opcode);
    }
    | XCHG
    { 
        uint8_t opcode =  0b11101011;
        i_emit("XCHG", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("XCHG %02X\n", opcode);
    }
    ;

arithmetic
    : ADD register
    {
        uint8_t opcode =  0b10000000 | ($register);
        i_emit("ADD", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("ADD %02X\n", opcode); 
    }
    | ADI expr
    {
        uint8_t opcode =  0b11000110;
        i_emit("ADI", LC, opcode, $expr, 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
        printf("ADI %02X %02X\n", opcode, $expr); 
    }
    | ADC register
    {
        uint8_t opcode =  0b10001000 | ($register);
        i_emit("ADC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("ADC %02X\n", opcode); 
    }
    | ACI expr
    {
        uint8_t opcode =  0b11001110;
        i_emit("ACI", LC, opcode, $expr, 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
        printf("ACI %02X %02X\n", opcode, $expr); 
    }
    | SUB register
    {
        uint8_t opcode =  0b10010000 | ($register);
        i_emit("SUB", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("SUB %02X\n", opcode); 
    }
    | SUI expr
    {
        uint8_t opcode =  0b11010110;
        i_emit("SUI", LC, opcode, $expr, 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
        printf("SUI %02X %02X\n", opcode, $expr); 
    }
    | SBB register
    {
        uint8_t opcode =  0b10011000 | ($register);
        i_emit("SBB", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("SBB %02X\n", opcode); 
    }
    | SBI expr
    {
        uint8_t opcode =  0b11011110;
        i_emit("SBI", LC, opcode, $expr, 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
        printf("SBI %02X %02X\n", opcode, $expr); 
    }
    | INR register
    {
        uint8_t opcode =  0b00000100 | ($register << 3);
        i_emit("INR", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("INR %02X\n", opcode); 
    }
    | DCR register
    {
        uint8_t opcode =  0b00000101 | ($register << 3);
        i_emit("DCR", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("DCR %02X\n", opcode); 
    }
    | INX reg_pair
    {
        uint8_t opcode =  0b00000011 | ($reg_pair << 4);
        i_emit("INX", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("INX %02X\n", opcode); 
    }
    | DCX reg_pair
    {
        uint8_t opcode =  0b00001011 | ($reg_pair << 4);
        i_emit("DCX", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("DCX %02X\n", opcode); 
    }
    | DAD reg_pair
    {
        uint8_t opcode =  0b00001001 | ($reg_pair << 4);
        i_emit("DAD", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("DAD %02X\n", opcode); 
    }
    | DAA
    {
        uint8_t opcode =  0b00100111;
        i_emit("DAA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("DAA %02X\n", opcode); 
    }
    ;

logical
    : ANA register
    {
        uint8_t opcode = 0b10100000 | $register;
        i_emit("ANA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("ANA %02X\n", opcode);
    }
    | ANI expr
    {
        uint8_t opcode = 0b11100110;
        i_emit("ANI", LC, opcode, $expr, 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
        printf("ANI %02X %02X\n", opcode, $expr);
    }
    | XRA register
    {
        uint8_t opcode = 0b10101000 | $register;
        i_emit("XRA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("XRA %02X\n", opcode);
    }
    | XRI expr
    {
        uint8_t opcode = 0b11101110;
        i_emit("XRI", LC, opcode, $expr, 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
        printf("XRI %02X %02X\n", opcode, $expr);
    }
    | ORA register
    {
        uint8_t opcode = 0b10110000| $register;
        i_emit("ORA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("ORA %02X\n", opcode);
    }
    | ORI expr
    {
        uint8_t opcode = 0b11110110;
        i_emit("ORI", LC, opcode, $expr, 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
        printf("ORI %02X %02X\n", opcode, $expr);
    }
    | CMP register
    {
        uint8_t opcode = 0b10111000| $register;
        i_emit("CMP", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("CMP %02X\n", opcode);
    }
    | CPI expr
    {
        uint8_t opcode = 0b11111110;
        i_emit("CPI", LC, opcode, $expr, 0, IMMEDIATE);
        LC = LC + IMMEDIATE;
        printf("CPI %02X %02X\n", opcode, $expr);
    }
    | RLC
    {
        uint8_t opcode = 0b00000111;
        i_emit("RLC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("RLC %02X\n", opcode);
    }
    | RRC
    {
        uint8_t opcode = 0b00001111;
        i_emit("RRC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("RRC %02X\n", opcode);
    }
    | RAL
    {
        uint8_t opcode = 0b00010111;
        i_emit("RAL", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("RAL %02X\n", opcode);
    }
    | RAR
    {
        uint8_t opcode = 0b00001111;
        i_emit("RAR", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("RAR %02X\n", opcode);
    }
    | CMA
    {
        uint8_t opcode = 0b00101111;
        i_emit("CMA", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("CMA %02X\n", opcode);
    }
    | CMC
    {
        uint8_t opcode = 0b00111111;
        i_emit("CMC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("CMC %02X\n", opcode);
    }
    | STC
    {
        uint8_t opcode = 0b00110111;
        i_emit("STC", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
    ;

branch
    : JMP expr
    {
        uint8_t opcode = 0b11000011;
        i_emit("JMP", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | JC expr
    {
        uint8_t opcode = 0b11011010;
        i_emit("JC", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | JNC expr
    {
        uint8_t opcode = 0b11010010;
        i_emit("JNC", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | JZ expr
    {
        uint8_t opcode = 0b11001010;
        i_emit("JZ", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | JNZ expr
    {
        uint8_t opcode = 0b11000010;
        i_emit("JNZ", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | JP expr
    {
        uint8_t opcode = 0b11110010;
        i_emit("JP", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | JM expr
    {
        uint8_t opcode = 0b11111010;
        i_emit("JM", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | JPE expr
    {
        uint8_t opcode = 0b11101010;
        i_emit("JPE", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | JPO expr
    {
        uint8_t opcode = 0b11100010;
        i_emit("JPO", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | CALL expr
    {
        uint8_t opcode = 0b11001101;
        i_emit("CALL", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | CC expr
    {
        uint8_t opcode = 0b11011100;
        i_emit("CC", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | CNC expr
    {
        uint8_t opcode = 0b11010100;
        i_emit("CNC", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | CZ expr
    {
        uint8_t opcode = 0b11001100;
        i_emit("CZ", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | CNZ expr
    {
        uint8_t opcode = 0b11000100;
        i_emit("CNZ", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | CP expr
    {
        uint8_t opcode = 0b11110100;
        i_emit("CP", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | CM expr
    {
        uint8_t opcode = 0b11111100;
        i_emit("CM", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | CPE expr
    {
        uint8_t opcode = 0b11101100;
        i_emit("CPE", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | CPO expr
    {
        uint8_t opcode = 0b11100100;
        i_emit("CPO", LC, opcode, $expr & 0xFF, $expr >> 8, DIRECT);
        LC = LC + DIRECT;
    }
    | RET
    {
        uint8_t opcode = 0b11001001;
        i_emit("RET", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
    | RC
    {
        uint8_t opcode = 0b11011000;
        i_emit("RC", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
    | RNC
    {
        uint8_t opcode = 0b11010000;
        i_emit("RNC", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
    | RZ
    {
        uint8_t opcode = 0b11001000;
        i_emit("RZ", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
    | RNZ
    {
        uint8_t opcode = 0b11000000;
        i_emit("RNZ", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
    | RP
    {
        uint8_t opcode = 0b11110000;
        i_emit("RP", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
    | RM
    {
        uint8_t opcode = 0b11111000;
        i_emit("RM", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
    | RPE
    {
        uint8_t opcode = 0b11101000;
        i_emit("RPE", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
    | RPO
    {
        uint8_t opcode = 0b11100000;
        i_emit("RPO", LC, opcode, 0, 0, DIRECT);
        LC = LC + REGISTER;
    }
    | PCHL
    {
        uint8_t opcode = 0b11101001;
        i_emit("PCHL", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
    }
    ;

stack_io
    : PUSH reg_pair
    {
        uint8_t opcode = 0b11000101 | ($reg_pair << 4);
        i_emit("PUSH", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("PUSH %02X\n", opcode);
    }
    | POP reg_pair
    {
        uint8_t opcode = 0b11000001 | ($reg_pair << 4);
        i_emit("POP", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("POP %02X\n", opcode);
    }
    | XTHL
    {
        uint8_t opcode = 0b11100011;
        i_emit("XTHL", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("XTHL %02X\n", opcode);
    }
    | SPHL
    {
        uint8_t opcode = 0b11111001;
        i_emit("SPHL", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("SPHL %02X\n", opcode);
    }
    | IN expr
    {
        uint8_t opcode = 0b11011011;
        uint8_t input_device = $expr;
        printf("IN %02X %02X\n", opcode, input_device);
    }
    | OUT expr
    {
        uint8_t opcode = 0b11010011;
        uint8_t input_device = $expr;
        printf("OUT %02X %02X\n", opcode, input_device);
    }
    ;

control
    : EI
    {
        uint8_t opcode =  0b11111011;
        printf("DI %02X\n", opcode);
    }
    | DI
    {
        uint8_t opcode =  0b11110011;
        printf("DI %02X\n", opcode);
    }
    | NOP
    { 
        uint8_t opcode =  0;
        i_emit("NOP", LC, opcode, 0, 0, REGISTER);
        LC = LC + REGISTER;
        printf("NOP %02X\n", opcode);
    }
    | HLT
    {
        uint8_t opcode =  0b01110110;
        printf("HLT %02X\n", opcode);
    }
    | RST expr
    {
        uint8_t opcode = 0b11000111 | ($expr << 3);
        printf("RST %02X\n", opcode);
    }
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
    : NAME ':' { st_insert(symbolTable, st_new_symbol($NAME, LC, false)); }
    ;


expr
    : expr[expr1] '+' expr[expr2]       { $$ = $expr1 + $expr2; }
    | expr[expr1] '-' expr[expr2]       { $$ = $expr1 - $expr2; }
    | expr[expr1] '*' expr[expr2]       { $$ = $expr1 * $expr2; }
    | expr[expr1] '/' expr[expr2]       { $$ = $expr1 / $expr2; }
    | expr[expr1] MODULO expr[expr2]    { $$ = $expr1 % $expr2; }
    | expr[expr1] AND expr[expr2]       { $$ = $expr1 & $expr2; }
    | expr[expr1] OR expr[expr2]        { $$ = $expr1 | $expr2; }
    | expr[expr1] XOR expr[expr2]       { $$ = $expr1 ^ $expr2; }
    | expr[expr1] SHR expr[expr2]       { $$ = $expr1 >> $expr2; }
    | expr[expr1] SHL expr[expr2]       { $$ = $expr1 << $expr2; }
    | term { }
    ;

term
    : '(' expr ')' { $term = $expr; }
    | '-' expr %prec UMINUS { $term = $expr * (-1); }
    | NOT expr  { $term = ~$expr; }
    | primary   { $term = $primary; }
    ;


primary
    : NAME
    { 
        Symbol *label = st_lookup(symbolTable, $NAME);
        $primary =  label->value;
    }
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
    
    symbolTable = st_new(32, hash);
    yyparse();
    st_print(symbolTable);
    i_printInstructions();
    return 0;
}