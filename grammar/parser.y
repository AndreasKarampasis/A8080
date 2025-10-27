%{
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
bool has_error = false;
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
    struct expr*   expr_val;
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
%token<string_val> STR_CONST

%type<int_val> register reg_pair
%type<opcode>  data_transfer arithmetic logical branch stack_io control
%type<expr_val> immediate primary term expr


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
        i_emit("MOV", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | MVI register ',' expr
    { 
        uint8_t opcode =  0b00000110 | ($register << 3);
        i_emit("MVI", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | LXI reg_pair ',' expr
    { 
        uint8_t opcode =  0b00000001 | ( $reg_pair << 4);
        i_emit("LXI", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | LDA expr
    { 
        uint8_t opcode =  0b00111010;
        i_emit("LDA", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | STA expr
    {
        uint8_t opcode =  0b00110010;
        i_emit("STA", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | LDAX reg_pair
    { 
        uint8_t opcode =  0b00001010 | ( $reg_pair << 4);
        i_emit("LDAX", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | STAX reg_pair
    { 
        uint8_t opcode =  0b00000010 | ( $reg_pair << 4);
        i_emit("STAX", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | LHLD expr
    { 
        uint8_t opcode =  0b00101010;
        i_emit("LHLD", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | SHLD expr
    { 
        uint8_t opcode =  0b00100010;
        i_emit("SHLD", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | XCHG
    { 
        uint8_t opcode =  0b11101011;
        i_emit("XCHG", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    ;

arithmetic
    : ADD register
    {
        uint8_t opcode =  0b10000000 | ($register);
        i_emit("ADD", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | ADI expr
    {
        uint8_t opcode =  0b11000110;
        i_emit("ADI", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | ADC register
    {
        uint8_t opcode =  0b10001000 | ($register);
        i_emit("ADC", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | ACI expr
    {
        uint8_t opcode =  0b11001110;
        i_emit("ACI", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | SUB register
    {
        uint8_t opcode =  0b10010000 | ($register);
        i_emit("SUB", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | SUI expr
    {
        uint8_t opcode =  0b11010110;
        i_emit("SUI", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | SBB register
    {
        uint8_t opcode =  0b10011000 | ($register);
        i_emit("SBB", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | SBI expr
    {
        uint8_t opcode =  0b11011110;
        i_emit("SBI", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | INR register
    {
        uint8_t opcode =  0b00000100 | ($register << 3);
        i_emit("INR", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | DCR register
    {
        uint8_t opcode =  0b00000101 | ($register << 3);
        i_emit("DCR", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | INX reg_pair
    {
        uint8_t opcode =  0b00000011 | ($reg_pair << 4);
        i_emit("INX", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | DCX reg_pair
    {
        uint8_t opcode =  0b00001011 | ($reg_pair << 4);
        i_emit("DCX", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | DAD reg_pair
    {
        uint8_t opcode =  0b00001001 | ($reg_pair << 4);
        i_emit("DAD", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | DAA
    {
        uint8_t opcode =  0b00100111;
        i_emit("DAA", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    ;

logical
    : ANA register
    {
        uint8_t opcode = 0b10100000 | $register;
        i_emit("ANA", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | ANI expr
    {
        uint8_t opcode = 0b11100110;
        i_emit("ANI", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | XRA register
    {
        uint8_t opcode = 0b10101000 | $register;
        i_emit("XRA", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | XRI expr
    {
        uint8_t opcode = 0b11101110;
        i_emit("XRI", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | ORA register
    {
        uint8_t opcode = 0b10110000| $register;
        i_emit("ORA", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | ORI expr
    {
        uint8_t opcode = 0b11110110;
        i_emit("ORI", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | CMP register
    {
        uint8_t opcode = 0b10111000| $register;
        i_emit("CMP", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | CPI expr
    {
        uint8_t opcode = 0b11111110;
        i_emit("CPI", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | RLC
    {
        uint8_t opcode = 0b00000111;
        i_emit("RLC", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | RRC
    {
        uint8_t opcode = 0b00001111;
        i_emit("RRC", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | RAL
    {
        uint8_t opcode = 0b00010111;
        i_emit("RAL", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | RAR
    {
        uint8_t opcode = 0b00001111;
        i_emit("RAR", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | CMA
    {
        uint8_t opcode = 0b00101111;
        i_emit("CMA", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | CMC
    {
        uint8_t opcode = 0b00111111;
        i_emit("CMC", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | STC
    {
        uint8_t opcode = 0b00110111;
        i_emit("STC", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    ;

branch
    : JMP expr
    {
        uint8_t opcode = 0b11000011;
        i_emit("JMP", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | JC expr
    {
        uint8_t opcode = 0b11011010;
        i_emit("JC", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | JNC expr
    {
        uint8_t opcode = 0b11010010;
        i_emit("JNC", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | JZ expr
    {
        uint8_t opcode = 0b11001010;
        i_emit("JZ", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | JNZ expr
    {
        uint8_t opcode = 0b11000010;
        i_emit("JNZ", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | JP expr
    {
        uint8_t opcode = 0b11110010;
        i_emit("JP", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | JM expr
    {
        uint8_t opcode = 0b11111010;
        i_emit("JM", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | JPE expr
    {
        uint8_t opcode = 0b11101010;
        i_emit("JPE", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | JPO expr
    {
        uint8_t opcode = 0b11100010;
        i_emit("JPO", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | CALL expr
    {
        uint8_t opcode = 0b11001101;
        i_emit("CALL", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | CC expr
    {
        uint8_t opcode = 0b11011100;
        i_emit("CC", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | CNC expr
    {
        uint8_t opcode = 0b11010100;
        i_emit("CNC", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | CZ expr
    {
        uint8_t opcode = 0b11001100;
        i_emit("CZ", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | CNZ expr
    {
        uint8_t opcode = 0b11000100;
        i_emit("CNZ", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | CP expr
    {
        uint8_t opcode = 0b11110100;
        i_emit("CP", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | CM expr
    {
        uint8_t opcode = 0b11111100;
        i_emit("CM", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | CPE expr
    {
        uint8_t opcode = 0b11101100;
        i_emit("CPE", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | CPO expr
    {
        uint8_t opcode = 0b11100100;
        i_emit("CPO", LC, opcode, $expr, DIRECT);
        LC = LC + DIRECT;
    }
    | RET
    {
        uint8_t opcode = 0b11001001;
        i_emit("RET", LC, opcode, NULL, DIRECT);
        LC = LC + REGISTER;
    }
    | RC
    {
        uint8_t opcode = 0b11011000;
        i_emit("RC", LC, opcode, NULL, DIRECT);
        LC = LC + REGISTER;
    }
    | RNC
    {
        uint8_t opcode = 0b11010000;
        i_emit("RNC", LC, opcode, NULL, DIRECT);
        LC = LC + REGISTER;
    }
    | RZ
    {
        uint8_t opcode = 0b11001000;
        i_emit("RZ", LC, opcode, NULL, DIRECT);
        LC = LC + REGISTER;
    }
    | RNZ
    {
        uint8_t opcode = 0b11000000;
        i_emit("RNZ", LC, opcode, NULL, DIRECT);
        LC = LC + REGISTER;
    }
    | RP
    {
        uint8_t opcode = 0b11110000;
        i_emit("RP", LC, opcode, NULL, DIRECT);
        LC = LC + REGISTER;
    }
    | RM
    {
        uint8_t opcode = 0b11111000;
        i_emit("RM", LC, opcode, NULL, DIRECT);
        LC = LC + REGISTER;
    }
    | RPE
    {
        uint8_t opcode = 0b11101000;
        i_emit("RPE", LC, opcode, NULL, DIRECT);
        LC = LC + REGISTER;
    }
    | RPO
    {
        uint8_t opcode = 0b11100000;
        i_emit("RPO", LC, opcode, NULL, DIRECT);
        LC = LC + REGISTER;
    }
    | PCHL
    {
        uint8_t opcode = 0b11101001;
        i_emit("PCHL", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    ;

stack_io
    : PUSH reg_pair
    {
        uint8_t opcode = 0b11000101 | ($reg_pair << 4);
        i_emit("PUSH", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | POP reg_pair
    {
        uint8_t opcode = 0b11000001 | ($reg_pair << 4);
        i_emit("POP", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | XTHL
    {
        uint8_t opcode = 0b11100011;
        i_emit("XTHL", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | SPHL
    {
        uint8_t opcode = 0b11111001;
        i_emit("SPHL", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | IN expr
    {
        uint8_t opcode = 0b11011011;
        i_emit("IN", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    | OUT expr
    {
        uint8_t opcode = 0b11010011;
        i_emit("OUT", LC, opcode, $expr, IMMEDIATE);
        LC = LC + IMMEDIATE;
    }
    ;

control
    : EI
    {
        uint8_t opcode =  0b11111011;
        i_emit("EI", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | DI
    {
        uint8_t opcode =  0b11110011;
        i_emit("DI", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | NOP
    { 
        uint8_t opcode =  0;
        i_emit("NOP", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | HLT
    {
        uint8_t opcode =  0b01110110;
        i_emit("HLT", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    | RST expr
    {
        // Note: "exp" must evaluate to a number in the range 0bOOO to 0b111
        uint8_t opcode = 0b11000111 | ($expr->number_const << 3);
        i_emit("RST", LC, opcode, NULL, REGISTER);
        LC = LC + REGISTER;
    }
    ;

directives
    : ORG expr { LC = $expr->number_const; }
    | END
    | NAME EQU expr
    | DB expr
    | DW expr
    | DS expr
    | IF 
    | ENDIF
    | SET 

label
    : NAME ':' { st_insert(symbolTable, st_new_symbol($NAME, LC, false)); }
    ;


expr
    : expr[expr1] '+' expr[expr2]
    { 
        expr_check_arith($expr1, "addition operation (+)");
        expr_check_arith($expr2, "addition operation (+)");
        $$ = new_number_const_expr($expr1->number_const + $expr2->number_const);

    }
    | expr[expr1] '-' expr[expr2]
    {
        expr_check_arith($expr1, "TODO");
        expr_check_arith($expr2, "TODO");
        $$ = new_number_const_expr($expr1->number_const - $expr2->number_const);
    }
    | expr[expr1] '*' expr[expr2]
    {
        expr_check_arith($expr1, "TODO");
        expr_check_arith($expr2, "TODO");
        $$ = new_number_const_expr($expr1->number_const * $expr2->number_const);
    }
    | expr[expr1] '/' expr[expr2]       {
        expr_check_arith($expr1, "TODO");
        expr_check_arith($expr2, "TODO");
        $$ = new_number_const_expr($expr1->number_const / $expr2->number_const);
    }
    | expr[expr1] MODULO expr[expr2]    {
        expr_check_arith($expr1, "TODO");
        expr_check_arith($expr2, "TODO");
        $$ = new_number_const_expr($expr1->number_const % $expr2->number_const);
    }
    | expr[expr1] AND expr[expr2]       {
        expr_check_arith($expr1, "TODO");
        expr_check_arith($expr2, "TODO");
        $$ = new_number_const_expr($expr1->number_const & $expr2->number_const);
    }
    | expr[expr1] OR expr[expr2]
    {
        expr_check_arith($expr1, "TODO");
        expr_check_arith($expr2, "TODO");
        $$ = new_number_const_expr($expr1->number_const | $expr2->number_const);
    }
    | expr[expr1] XOR expr[expr2]
    {
        expr_check_arith($expr1, "TODO");
        expr_check_arith($expr2, "TODO");
        $$ = new_number_const_expr($expr1->number_const ^ $expr2->number_const);
    }
    | expr[expr1] SHR expr[expr2]
    {
        expr_check_arith($expr1, "TODO");
        expr_check_arith($expr2, "TODO");
        $$ = new_number_const_expr($expr1->number_const >> $expr2->number_const);
    }
    | expr[expr1] SHL expr[expr2]
    {
        expr_check_arith($expr1, "TODO");
        expr_check_arith($expr2, "TODO");
        $$ = new_number_const_expr($expr1->number_const << $expr2->number_const);
    }
    | term { $$ = $term; }
    ;

term
    : '(' expr ')' { $term = $expr; }
    | '-' expr %prec UMINUS {
        $term = new_number_const_expr($expr->number_const * (-1));
    }
    | NOT expr  {
        $term = new_number_const_expr(~$expr->number_const);
    }
    | primary   { $term = $primary; }
    ;


primary
    : NAME
    { 
        Symbol *label = st_lookup(symbolTable, $NAME);
        if (!label) {
            unresolved_insert($NAME, current_instrs, yylineno);
            $primary =  NULL;
        }
        else {
            $primary = new_number_const_expr(label->value);
        }
    }
    | immediate { $primary = $immediate; }; 
    | STR_CONST { $primary = new_string_const_expr($STR_CONST); }
    ;


immediate
    : HEX_NUMBER    { $immediate = new_number_const_expr($HEX_NUMBER); }
    | DEC_NUMBER    { $immediate = new_number_const_expr($DEC_NUMBER); }
    | OCT_NUMBER    { $immediate = new_number_const_expr($OCT_NUMBER); }
    | BIN_NUMBER    { $immediate = new_number_const_expr($BIN_NUMBER); }
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

// This function has not been tested!
void yyerror(const char *msg) {
    has_error = true;
    fprintf(stderr, "Error: %s at line %d", msg, yylineno);
    if (yytext && yytext[0] != '\0') {
        fprintf(stderr, ", near '%s'", yytext);
    }
    fprintf(stderr, "\n");
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
    patch_unresolved_labels(symbolTable);
    if (!has_error) {
        i_printInstructions();
        st_print(symbolTable);
    }
    i_generate_intel_hex();
    return 0;
}