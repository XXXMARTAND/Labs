%{
	int c = 0, w = 0, l = 0, b = 0;
%}


%%

\n { l++; }
" " { b++; w++; c += strlen(yytext);}
\t { b += 4; }
. { c++; }

%%

int yywrap() {
	return 1;
}

void main() {
	yylex();

	printf("\n characters %d", c);
	printf("\n words %d", w);
	printf("\n lines %d", l);
	printf("\n blanks %d\n", b);

	
}