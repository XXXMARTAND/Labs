%{
	int lett = 0;
	int vow = 0;
	
%}

%%
[aeiouAEIOU] {vow++;}

[a-zA-Z] {lett++;}
%%
int main(int argc, char *argv[])
{
	yylex();
	printf("%8d%8d\n",vow,lett);
	printf("%d \n",argc);

	printf("%s\n",argv[2]);

}
int yywrap() {
	return 1;
}