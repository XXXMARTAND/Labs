%{
	int chars = 0;
	int word = 0;
	int lines = 0;
%}

%%
[a-zA-Z]+ { word++;char+=strlen(yytext);}
\n {chars++;lines++;}
. {chars++}
%%
main(int argc, char **argv)
{
	yylex();
	printf("%8d%8d%8d\n",lines,words,chars);
}