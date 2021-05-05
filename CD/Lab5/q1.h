#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 512

char *inname;
int ki=0;
int get_size(char value[16]) {
	if (strcmp(value, "int") == 0)
		return 4;
	else if (strcmp(value, "char") == 0)
		return 1;
	return 0;
}

int KEYWORD_COUNT = 12;
char *keywords[12] = {

	"class", "main", "int", "char", "return", "func", "if","for","else","printf","scanf","void"
};

int is_keyword(char value[16]) {
	for (int i = 0; i < KEYWORD_COUNT; ++i) {
		if (strcmp(value, keywords[i]) == 0)
			return 1;
	}
	return 0;
}



typedef struct stex {
	int id;
	char lexeme[16];
	char type[16];
	int size;
	int scope;
	char arg[16];
	int noarg;
	char returntype[16];
} ste_t;

ste_t symbol_table[16];
int ste_p = 0;

ste_t find_or_insert_st(char lexeme[16], char type[16], int size, int scope, char arg[16], int noarg, char returntype[16]) {
	ste_t entry;
	// Check if the symbol table entry is present
	int i;
	for (i = 0; i < ste_p; ++i) {
		if (strcmp(symbol_table[i].lexeme, lexeme) == 0) {
			return symbol_table[i];
		}
	}
	strcpy(entry.lexeme, lexeme);
	entry.id = ste_p + 1;
	strcpy(entry.type, type);
	entry.size = size;
	entry.scope = scope;
	strcpy(entry.arg,arg);
	strcpy(entry.returntype,returntype);
	entry.noarg = noarg;
	symbol_table[ste_p++] = entry;
	return entry;
}

void modify(char lexeme[16], char arg[16]){
		//printf("%s %s\n", lexeme,arg);
	int x;

	for (int i = 0; i < ste_p; ++i)
	{
		if (strcmp(symbol_table[i].lexeme, lexeme) == 0)
		{
			x=i;
			strcpy(symbol_table[x].arg,arg);
			symbol_table[x].noarg = 1;
		}
	}

}

void print_symbol_table() {
	printf("\n");
	printf("-----------    SYMBOL  TABLE    ----------\n");
	//printf("------------------------------------------\n");
	printf("id |            name | type | size | scope|arguments|No. of arg|returntype\n");
	//printf("------------------------------------------\n");
	int x=1;
	for (int i = 0; i < ste_p; ++i) {
		ste_t entry = symbol_table[i];
		if(!strcmp(entry.type,"int")||!strcmp(entry.type,"char")||!strcmp(entry.type,"Func"))
		printf("%2d | %15s | %4s | %4d | %5d| %5s   |    %2d    |%4s \n", x++, entry.lexeme, entry.type, entry.size, entry.scope,entry.arg,entry.noarg,entry.returntype);
	}
	//printf("------------------------------------------\n");
}


typedef enum ttx {
	TOKEN_TYPE_ID,
	TOKEN_TYPE_KEYWORD,
	TOKEN_TYPE_NUM,
	TOKEN_TYPE_OP,
	TOKEN_TYPE_SPECIAL,
	TOKEN_TYPE_FUN
} token_type;

typedef struct tokenx {
	token_type type;
	char value[16];
	ste_t entry;
	int rowno;
	int colno;
} token_t;

token_t tokens[120];
int token_p = 0;

token_t last_keyword;
int current_scope = 0;

token_t new_token(token_type type, char value[16], int rowno, int colno) {
	//printf("%s\n",last_keyword.value );
	//printf("%dyyyyy",colno );
	token_t token;
	token.type = type;
	token.rowno = rowno;
			token.colno = colno;
	if (type == TOKEN_TYPE_ID) {
		if (is_keyword(value)) {
			token.type = TOKEN_TYPE_KEYWORD;
			// token.rowno = rowno;
			// token.colno = colno;
		} else {
			token.entry = find_or_insert_st(value, last_keyword.value, get_size(last_keyword.value), current_scope,"x",0,"");
			// token.rowno = rowno;
			// token.colno = colno;
			
		}
	}
	else if (type == TOKEN_TYPE_FUN) {
		
			//chart buff[128];
			//findargs(buff)
			token.entry = find_or_insert_st(value, "Func", 0, current_scope,"x",0,last_keyword.value);
			token.rowno = rowno;
			token.colno = colno;
			
		
	}

	strcpy(token.value, value);
	if (token.type == TOKEN_TYPE_KEYWORD) {
		last_keyword = token;
	}
	//printf("%s",tokens[(token_p)-1].value);
	if (!strcmp(value,")")&&!strcmp(tokens[(token_p)-1].value,"(")){
		//printf("jhakkas\n");
		
	}
	else if(!strcmp(value,")"))
		{
			//printf("jhakkas2\n");
			modify(tokens[token_p-4].value,tokens[token_p-1].value);
		}
	tokens[token_p++] = token;
	
	

	return token;
}

void print_token(token_t token) {
	printf("<");
	inname[ki++]='<';
	if (token.type == TOKEN_TYPE_ID) {
		ste_t entry = find_or_insert_st(token.value, last_keyword.value, get_size(last_keyword.value), current_scope,"x",0,last_keyword.value);
		printf("id, %d", entry.id);
		inname[ki++]='i';
		inname[ki++]='d';
	} else if (token.type == TOKEN_TYPE_NUM) {
		printf("num, %s", token.value);
		inname[ki++]='n';
		inname[ki++]='u';
		inname[ki++]='m';
		
	} else {
		printf("%s", token.value);
		for (int i = 0; i < strlen(token.value); ++i)
		{
			inname[ki++]=token.value[i];
	}}
	
	printf(",%d,%d",token.rowno,token.colno);
	printf("> ");
	inname[ki++]='>';
	inname[ki++]=' ';

}

void print_tokens() {
	printf("\n");
	printf("--------------    TOKENS    --------------\n");
	for (int i = 0; i < token_p; ++i) {
		print_token(tokens[i]);
		if (i % 5 == 4)
			printf("\n");
	}
	printf("\n------------------------------------------\n");
}


int isDigit (char ch) {
	return (ch >= '0' && ch <= '9');
}

int isNumerical (char ch) {
	return (isDigit(ch) || ch == '.' || ch == 'e' || ch == 'E');
}

int isAlphabet (char ch) {
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int isValidID (char ch) {
	return (isDigit(ch) || isAlphabet(ch) || ch == '_');
}

const char *SPECIALSYMBOLS = "[]{}(),;:.#";

int isSpecialSymbol (char ch) {
	return (strchr(SPECIALSYMBOLS, ch) != NULL);
}

const char *OPERATORS = "+++-*/%<>=!&|^~";

int isOperator (char ch) {
	return (strchr(OPERATORS, ch) != NULL);
}

//#define BUFFER_SIZE 128
void clean_comm (char *infile){
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen(infile,"r");
	if(fa == NULL){
		printf("Cannot open file \n");
		exit(0);
	}
	fb = fopen("qout.c","w");
	ca = getc(fa);
	while(ca!= EOF){
		if(ca=='/'){
			cb = getc(fa);
			if (cb=='/')
			{
				while(ca!='\n')
					ca = getc(fa);

			}
			else if (cb =='*')
			{
				do{
					while(ca!='*')
						ca = getc(fa);
					ca = getc(fa);

				}while(ca!='/');
		}

		
		else{
			putc(ca,fb);
			putc(cb,fb);
		}
	}
	else if (ca == '#') { 
			while (ca != '\n') { 
				ca = getc(fa);
			}
		}
	else putc(ca,fb);
	ca = getc(fa);
}
fclose(fa);
fclose(fb);

}


void emit_tokens (char *infile) {
	int rowno=1,colno=0,tempcol=0;
	int isFunct = 0;
	clean_comm(infile);
	inname = (char *)malloc(BUFFER_SIZE*sizeof(char));
	FILE *input = fopen(infile, "r");

	char buffer[16];
	int k = 0;

	current_scope = 0;
	char ch, lch;

	token_t token;

	do {

		ch = getc(input);

		if (ch == ' ') {
			// Discard space
			colno++;
		}
		else if(ch == '\t'){
			colno+=4;

		}
		else if(ch == '\n'){
			colno=0;
			rowno++;
			
		}
		else if(ch == '\r'){
			
		}
		else if (ch == '#') { 
			colno=0;
			rowno++;
			while (ch != '\n') { 
				ch = getc(input);
			}
		}
		else if(ch=='/'){
			ch = getc(input);
			if (ch=='/')
			{
				colno=0;
			rowno++;
				while(ch!='\n')
					ch = getc(input);

			}
			else if (ch =='*')
			{	
				colno=0;
				rowno++;
				do{
					while(ch!='*'){
						ch = getc(input);
						if(ch=='\n')
							rowno++;
					}
					ch = getc(input);

				}while(ch!='/');
		}	
	}

		// IDs begin with an alphabet and then may contains numbers, characters or '_'
		else if (isAlphabet(ch)) {
			k = 0;
			tempcol=colno;
			while (isValidID(ch)) {
				buffer[k++] = ch;
				colno++;
				//printf("%d",colno );
				ch = getc(input);
			}
			//char x = getc(input);
			
			
			
			buffer[k++] = '\0';
			if (ch=='('&&!is_keyword(buffer)){

				
				
				token = new_token(TOKEN_TYPE_FUN, buffer,rowno,tempcol);

			}
			else
				token = new_token(TOKEN_TYPE_ID, buffer,rowno,tempcol);
			//ungetc(x,input);
			ungetc(ch, input);
			//printf("%s\n",buffer );
			
		}

		// Numbers
		else if (isDigit(ch)) {
			k = 0;
			tempcol=colno;
			while (isNumerical(ch)) {
				buffer[k++] = ch;
				colno++;
				ch = getc(input);
			}
			ungetc(ch, input);
			buffer[k++] = '\0';
			token = new_token(TOKEN_TYPE_NUM, buffer,rowno,tempcol);
		}

		else if (isSpecialSymbol(ch)) {
			tempcol=colno;
			if (ch == '{') {
				current_scope += 1;
			} else if (ch == '}') {
				current_scope -= 1;
			}
			k = 0;
			buffer[k++] = ch;
			colno++;
			buffer[k++] = '\0';
			token = new_token(TOKEN_TYPE_SPECIAL, buffer,rowno,colno);
			
		}

		else if (isOperator(ch)) {
			k = 0;
			tempcol=colno;
			while (isOperator(ch) || ch == ' ' || ch == '\t') {
				if (isOperator(ch)) {
					buffer[k++] = ch;
					colno++;
				}
				ch = getc(input);
			}
			buffer[k++] = '\0';
			ungetc(ch, input);
			token = new_token(TOKEN_TYPE_OP, buffer,rowno,tempcol);
		}

		lch = ch;

	} while (ch != EOF);

	//print_symbol_table();
	print_tokens();
	
	//program();

}


// int main(int argc, const char *argv[]) {
// 	emit_tokens("input.c");
// 	return 0;
// }