grammar UzhLang;

// Parser rule

program: (line|empty_line)+;
line: BOL? (function_line | while_line | if_line | else_line | assign_line | expr | return_line);
empty_line: BOL;

function_line: DEF ID '(' (ID (',' ID)*  )? ')' ':';
while_line: WHILE expr ':';
if_line: IF expr ':';
else_line: ELSE ':';
assign_line: ID '=' expr;
return_line: RETURN expr;

expr:
	NOT expr
	| expr ( '*' | '/') expr
	| expr ( '+' | '-') expr
	| expr COMP expr
	| expr AND expr
	| expr OR expr
	| '(' expr ')'
	| ID '('(expr (',' expr)*  )? ')'
	| INT
	| ID;

// Lexer rules
INT: [0-9]+;
LC  : '#' ~[\r\n]* -> channel(HIDDEN);
BOL : '\n'[ ]*;
HWS : [ \t]+ -> channel(HIDDEN);
DEF: 'def';
WHILE: 'while';
IF: 'if';
ELSE: 'else';
RETURN: 'return';
COMP: ('<' | '>' | '<=' | '>=' | '==' | '!=');
AND: ( '&&' | 'and');
OR: ( '||' | 'or');
NOT: ('!' | 'not');
ID: [a-zA-Z_0-9][a-zA-Z_0-9]*;




