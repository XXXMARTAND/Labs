%{
	int isCompound = 0;

%}
%%
[]and[] {isCompound = 1;}
[]or[] {isCompound = 1;}
%%
void main(){
	yylex();
	if (isCompound==1)
	printf("Compound \n");
	else
	printf("Simple \n");
	

}
int yywrap()
{
	return 1;
}