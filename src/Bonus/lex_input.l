%%
"boolean"			printf("boolean\n");
"int"				printf("int\n");
"float"				printf("float\n");
"if"				printf("if\n");
"else"				printf("else\n");
"while"				printf("while\n");
[a-zA-z][a-zA-z0-9]*		printf("id\n");
[0-9]+("."[0-9]+)?		printf("num\n");
"="				printf("assign\n");
"=="|"<="|"<"|">="|">"|!=	printf("relop\n");
","				printf(",\n");
";"				printf(";\n");
"("				printf("(\n");
")"				printf(")\n");
"{"				printf("{\n");
"}"				printf("}\n");
[+-]				printf("addop\n");
[*/]				printf("mulop\n");
[ \t\n]				;
.				printf("LEXICAL ERROR\n");
%%

int yywrap(void)
{
	return 1;
}

