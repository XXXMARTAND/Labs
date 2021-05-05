#include <stdio.h>
int main()
{
	int denom, d[100], use[100], i, n;
	printf("Enter denomination COUNT");
	scanf("%d", &denom);

	printf("enter d1,d2....\n");
	for (int i = 0; i < denom; ++i)
	{
		scanf("%d", &d[i]);
	}

	printf("Enter amount ");
	scanf("%d", &n);

	for (int i = 0; i < denom; ++i)
	{
		use[i] = n / d[i];
		n %= d[i];
	}

	printf("\nSol \n");
	for (int i = 0; i < denom; ++i)
	{
		if (use[i] == 0)
		{
			continue;
		}
		printf("%d coins of %d\n", use[i], d[i]);
	}
}