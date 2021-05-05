
#include <stdio.h> 

void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 


void Sort(int arr[], int n) 
{ 
int i, j; 
for (i = 0; i < n-1; i++)	 

	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 


// Driver program to test above functions 
int main() 
{ 
	int b[10];
	int a;
	printf("Enter Size\n");
   scanf("%d",&a);
   printf("Enter array\n");
   for (int i = 0; i < a; ++i)
   {
       scanf("%d",&b[i]);
   } 
	Sort(b, a); 
	printf("Sorted array\n"); 
	int i; 
	for (i=0; i < a; i++) 
		printf("%d\n", b[i]); 
	return 0; 
} 
