
#include <stdio.h>
#include <stdlib.h>

int powa(int a, int b){
	int product = 1;
	for (int i = 0; i < b; ++i)
	{
		product = product*a;
	}
	return product;
}

int main() {
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter array elements: \n");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	unsigned int i;
	int a1[50], a2[50];
	int j, k; 
	int sum1, sum2;

	for(i = 1; i < (powa(2, n) / 2); i++) {
		j = 0, k = 0;

		for(int l = 0; l < n; l++) {
			if((1<<l) & i)
				a1[j++] = arr[l];
			else
				a2[k++] = arr[l];
		}
		sum1 = 0, sum2 = 0;

		for(int x = 0; x < j; x++)
			sum1 = sum1 + a1[x];
		for(int y = 0; y < k; y++)
			sum2 = sum2 + a2[y];

		printf("%d %d\n",sum1,sum2);

		if(sum1 == sum2){
			printf("{");
			for(int x = 0; x < j; x++)
				printf("%d, ", a1[x]);
			
			printf("}, {");

			for(int y = 0; y < k; y++)
				printf("%d, ", a2[y]);
			printf("}\n");
		}
	}




	//printf("{1, 2}, {3}\n");
}
