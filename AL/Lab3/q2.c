// C program for Naive Pattern Searching algorithm 
#include <stdio.h> 
#include <string.h> 

void search(char* pat, char* txt) 
{ 
	int a = strlen(pat); 
	int b = strlen(txt); 

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= b - a; i++) { 
		int j; 

		/* For current index i, check for pattern match */
		for (j = 0; j < a; j++) 
			if (txt[i + j] != pat[j]) 
				break; 

		if (j == a) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			printf("found at index %d \n", i); 
	} 
} 


int main() 
{ 
	int a;
	char txt[] = "AABAACAADAABAAABAA"; 
	char pat[] = "AABA"; 

	printf("Enter Array \n");
	gets(txt);
	printf("Enter Pattern \n");
	gets(pat);

	search(pat, txt); 
	return 0; 
} 
