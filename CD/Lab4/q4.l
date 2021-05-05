%{
	int pc = 0, sc = 0;
%}

%%

"printf" { fprintf(yyout, "WRITE"); pc++; }
"scanf" { fprintf(yyout, "READ"); sc++; }

%%
void main()
{
	yyin = fopen("in.c", "r");
	yyout = fopen("out.c", "w");
	yylex();

	printf("\n printf : %d", pc);
	printf("\n scanf : %d\n", sc);

	
}

int yywrap() {
	return 1;
}