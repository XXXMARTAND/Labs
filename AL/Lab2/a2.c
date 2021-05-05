#include <stdio.h> 

void toH(int n, char from, char to, char aux) 
{ 
	if (n == 1) 
	{ 
		printf("\n Move disk 1 from rod %c to rod %c", from, to); 
		return; 
	} 
	toH(n-1, from, aux, to); 
	printf("\n Move disk %d from rod %c to rod %c", n, from, to); 
	toH(n-1, aux, to, from); 
} 

int main() 
{ 
	int n;
	printf("Enter no. of discs\n");
	scanf("%d",&n); 
	toH(n, 'A', 'C', 'B'); 
	return 0; 
} 
