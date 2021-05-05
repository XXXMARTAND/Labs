%{
	int pint = 0, nint = 0, pfloat = 0, nfloat = 0;
%}

%%

\+?[0-9]+	pint++;
-[0-9]+	nint++;

\+?[0-9]*\.[0-9]+ pfloat++;
-[0-9]*\.[0-9]+	nfloat++;
. ;

%%

int yywrap() {
	
}

void main() {
	yylex();

	printf("\npositive int count %d", pi);
	printf("\negative int count %d", ni);
	printf("\npositive float count %d", pf);
	printf("\negative float count %d\n", nf);
	
	return 0;
}