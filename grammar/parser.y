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
        printf("MOV %02X\n", opcode);
    }
    | MVI register ',' expr
    { 
        uint8_t opcode =  0b00000110 | ($register << 3);
        printf("MVI %02X %02X\n", opcode, $expr);
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
    {
        uint8_t opcode =  0b10000000 | ($register);
        printf("ADD %02X\n", opcode); 
    }
    | ADI expr
    {
        uint8_t opcode =  0b11000110;
        printf("ADI %02X %02X\n", opcode, $expr); 
    }
    | ADC register
    {
        uint8_t opcode =  0b10001000 | ($register);
        printf("ADC %02X\n", opcode); 
    }
    | ACI expr
    {
        uint8_t opcode =  0b11001110;
        printf("ACI %02X %02X\n", opcode, $expr); 
    }
    | SUB register
    {
        uint8_t opcode =  0b10010000 | ($register);
        printf("SUB %02X\n", opcode); 
    }
    | SUI expr
    {
        uint8_t opcode =  0b11010110;
        printf("SUI %02X %02X\n", opcode, $expr); 
    }
    | SBB register
    {
        uint8_t opcode =  0b10011000 | ($register);
        printf("SBB %02X\n", opcode); 
    }
    | SBI expr
    {
        uint8_t opcode =  0b11011110;
        printf("SBI %02X %02X\n", opcode, $expr); 
    }
    | INR register
    {
        uint8_t opcode =  0b00000100 | ($register << 3);
        printf("INR %02X\n", opcode); 
    }
    | DCR register
    {
        uint8_t opcode =  0b00000101 | ($register << 3);
        printf("DCR %02X\n", opcode); 
    }
    | INX reg_pair
    {
        uint8_t opcode =  0b00000011 | ($reg_pair << 4);
        printf("INX %02X\n", opcode); 
    }
    | DCX reg_pair
    {
        uint8_t opcode =  0b00001011 | ($reg_pair << 4);
        printf("DCX %02X\n", opcode); 
    }
    | DAD reg_pair
    {
        uint8_t opcode =  0b00001001 | ($reg_pair << 4);
        printf("DAD %02X\n", opcode); 
    }
    | DAA
    {
        uint8_t opcode =  0b00100111;
        printf("DAA %02X\n", opcode); 
    }
    ;

logical
    : ANA register
    {
        uint8_t opcode = 0b10100000 | $register;
        printf("ANA %02X\n", opcode);
    }
    | ANI expr
    {
        uint8_t opcode = 0b11100110;
        uint8_t data = $expr;
        printf("ANI %02X %02X\n", opcode, data);
    }
    | XRA register
    {
        uint8_t opcode = 0b10101000 | $register;
        printf("XRA %02X\n", opcode);
    }
    | XRI expr
    {
        uint8_t opcode = 0b11101110;
        uint8_t data = $expr;
        printf("XRI %02X %02X\n", opcode, data);
    }
    | ORA register
    {
        uint8_t opcode = 0b10110000| $register;
        printf("ORA %02X\n", opcode);
    }
    | ORI expr
    {
        uint8_t opcode = 0b11110110;
        uint8_t data = $expr;
        printf("ORI %02X %02X\n", opcode, data);
    }
    | CMP register
    {
        uint8_t opcode = 0b10111000| $register;
        printf("CMP %02X\n", opcode);
    }
    | CPI expr
    {
        uint8_t opcode = 0b11111110;
        uint8_t data = $expr;
        printf("CPI %02X %02X\n", opcode, data);
    }
    | RLC
    {
        uint8_t opcode = 0b00000111;
        printf("RLC %02X\n", opcode);
    }
    | RRC
    {
        uint8_t opcode = 0b00001111;
        printf("RRC %02X\n", opcode);
    }
    | RAL
    {
        uint8_t opcode = 0b00010111;
        printf("RAL %02X\n", opcode);
    }
    | RAR
    {
        uint8_t opcode = 0b00001111;
        printf("RAR %02X\n", opcode);
    }
    | CMA
    {
        uint8_t opcode = 0b00101111;
        printf("CMA %02X\n", opcode);
    }
    | CMC
    {
        uint8_t opcode = 0b00111111;
        printf("CMC %02X\n", opcode);
    }
    | STC
    {
        uint8_t opcode = 0b00110111;
        printf("STC %02X\n", opcode);
    }
    ;

branch
    : JMP expr
    {
        uint8_t opcode = 0b11000011;
        uint8_t address = $expr;
        printf("JMP %02X %04X\n", opcode, address);
    }
    | JC expr
    {
        uint8_t opcode = 0b11011010;
        uint8_t address = $expr;
        printf("JC %02X %04X\n", opcode, address);
    }
    | JNC expr
    {
        uint8_t opcode = 0b11010010;
        uint8_t address = $expr;
        printf("JNC %02X %04X\n", opcode, address);
    }
    | JZ expr
    {
        uint8_t opcode = 0b11001010;
        uint8_t address = $expr;
        printf("JZ %02X %04X\n", opcode, address);
    }
    | JNZ expr
    {
        uint8_t opcode = 0b11000010;
        uint8_t address = $expr;
        printf("JNZ %02X %04X\n", opcode, address);
    }
    | JP expr
    {
        uint8_t opcode = 0b11110010;
        uint8_t address = $expr;
        printf("JP %02X %04X\n", opcode, address);
    }
    | JM expr
    {
        uint8_t opcode = 0b11111010;
        uint8_t address = $expr;
        printf("JM %02X %04X\n", opcode, address);
    }
    | JPE expr
    {
        uint8_t opcode = 0b11101010;
        uint8_t address = $expr;
        printf("JPE %02X %04X\n", opcode, address);
    }
    | JPO expr
    {
        uint8_t opcode = 0b11100010;
        uint8_t address = $expr;
        printf("JPO %02X %04X\n", opcode, address);
    }
    | CALL expr
    {
        uint8_t opcode = 0b11001101;
        uint8_t address = $expr;
        printf("CALL %02X %04X\n", opcode, address);
    }
    | CC expr
    {
        uint8_t opcode = 0b11011100;
        uint8_t address = $expr;
        printf("CC %02X %04X\n", opcode, address);
    }
    | CNC expr
    {
        uint8_t opcode = 0b11010100;
        uint8_t address = $expr;
        printf("CNC %02X %04X\n", opcode, address);
    }
    | CZ expr
    {
        uint8_t opcode = 0b11001100;
        uint8_t address = $expr;
        printf("CZ %02X %04X\n", opcode, address);
    }
    | CNZ expr
    {
        uint8_t opcode = 0b11000100;
        uint8_t address = $expr;
        printf("CNZ %02X %04X\n", opcode, address);
    }
    | CP expr
    {
        uint8_t opcode = 0b11110100;
        uint8_t address = $expr;
        printf("CP %02X %04X\n", opcode, address);
    }
    | CM expr
    {
        uint8_t opcode = 0b11111100;
        uint8_t address = $expr;
        printf("CM %02X %04X\n", opcode, address);
    }
    | CPE expr
    {
        uint8_t opcode = 0b11101100;
        uint8_t address = $expr;
        printf("CPE %02X %04X\n", opcode, address);
    }
    | CPO expr
    {
        uint8_t opcode = 0b11100100;
        uint8_t address = $expr;
        printf("CPO %02X %04X\n", opcode, address);
    }
    | RET
    {
        uint8_t opcode = 0b11001001;
        printf("RET %02X\n", opcode);
    }
    | RC
    {
        uint8_t opcode = 0b11011000;
        printf("RC %02X\n", opcode);
    }
    | RNC
    {
        uint8_t opcode = 0b11010000;
        printf("RNC %02X\n", opcode);
    }
    | RZ
    {
        uint8_t opcode = 0b11001000;
        printf("RZ %02X\n", opcode);
    }
    | RNZ
    {
        uint8_t opcode = 0b11000000;
        printf("RNZ %02X\n", opcode);
    }
    | RP
    {
        uint8_t opcode = 0b11110000;
        printf("RP %02X\n", opcode);
    }
    | RM
    {
        uint8_t opcode = 0b11111000;
        printf("RM %02X\n", opcode);
    }
    | RPE
    {
        uint8_t opcode = 0b11101000;
        printf("RPE %02X\n", opcode);
    }
    | RPO
    {
        uint8_t opcode = 0b11100000;
        printf("RPO %02X\n", opcode);
    }
    | PCHL
    {
        uint8_t opcode = 0b11101001;
        printf("PCHL %02X\n", opcode);
    }
    ;

stack_io
    : PUSH reg_pair
    {
        uint8_t opcode = 0b11000101 | ($reg_pair << 4);
        printf("PUSH %02X\n", opcode);
    }
    | POP reg_pair
    {
        uint8_t opcode = 0b11000001 | ($reg_pair << 4);
        printf("POP %02X\n", opcode);
    }
    | XTHL
    {
        uint8_t opcode = 0b11100011;
        printf("XTHL %02X\n", opcode);
    }
    | SPHL
    {
        uint8_t opcode = 0b11111001;
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
    : NAME ':' { st_insert(symbolTable, st_new_symbol($NAME, false)); }
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
        $$ =  label->value;
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
    return 0;
}