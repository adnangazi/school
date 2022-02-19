grammar pascal;

start     : 'program' ID ';' 'var' decl_list main_code EOF ;

decl_list : decl | decl decl_list ;
decl      : ID concat_decl ':' 'integer' ';';
concat_decl : ',' ID concat_decl | ;

main_code : 'begin' st_list 'end' '.' ;
code_block: statement | 'begin' st_list 'end' ;
st_list   : statement ';' | statement ';' st_list ;

repeat_block: 'repeat' st_list 'until' relation_block ;

statement : assign | branch | out | in | repeat_block;

assign    : ID ':=' arit ;
out       : 'writeln' '(' content_out ')' ;
in		  : 'readln' '(' ID ')' ;

branch    : 'if' relation_block 'then' code_block | 'if' relation_block 'then' code_block 'else' code_block ;


content_out : string | expr ;
string : '\'' .*? '\'' ;
expr      : NUMBER | ID ;


arit : expr '+' expr | expr '-' expr | expr '*' expr | expr '/' expr | expr '%' expr | '(' arit ')' | expr;

relation_block : relation_block OR relation_block | relation_block AND relation_block | 
				 NOT relation_block | '(' relation_block ')' | relation ;
relation  : expr LT expr | expr LEQ expr | expr EQ expr 
          | expr NEQ expr | expr GEQ expr | expr GT expr ;
	


EQ        : '=' ;
LT        : '<' ;
LEQ       : '<=' ;
GT        : '>' ;
GEQ       : '>=' ;
NEQ       : '<>' ;

OR	: 'or' | 'OR' | '|' ;
AND	: 'and' | 'AND' | '&' ;
NOT	: 'not' | 'NOT' | '!' ;

ID        : [a-z]+ ;
NUMBER    : [0-9]+ ;

R_COMMENT : '(*' .*? '*)' -> skip ;     // .*? matches anything until the first */
C_COMMENT : '{' .*? '}' -> skip ;       // .*? matches anything until the first }
LINE_COMMENT : '//' ~[\r\n]* -> skip ;  // ~[\r\n]* matches anything but \r and \n
WS        : [ \n\t\r]+ -> skip;
ErrorChar : . ;
