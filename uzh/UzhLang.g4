grammar UzhLang;

// Parser rule

program: (line|BOL)+;
line: (functionLine | whileLine | ifLine | elseLine | assignLine | exprLine | returnLine);

functionLine: BOL? DEF ID '(' (ID (',' ID)*  )? ')' ':';
whileLine: BOL WHILE expr ':';
ifLine: BOL IF expr ':';
elseLine: BOL ELSE ':';
assignLine: BOL ID '=' expr;
returnLine: BOL RETURN expr;
exprLine: BOL expr;

funcCall: ID '('(expr (',' expr)*  )? ')';
expr:
	NOT expr
	| expr ( '*' | '/') expr
	| expr ( '+' | '-') expr
	| expr COMP expr
	| expr AND expr
	| expr OR expr
	| '(' expr ')'
	| funcCall
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




