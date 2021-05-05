#include <stdlib.h>
#include <stdio.h>
void merge(int *a, int *b, int*c, int p , int q){
	int i=0,j=0,k=0;
	while(i<p&&j<q){
		if(b[i]<=c[j]){
			a[k]=b[i];i++;
			}
			else 
				{a[k]=c[j];j++;
			k++;}
		}
			if(i==p){
				int x = j;
				int y = k;
				for (int sr = x; sr < q-1; ++sr)
				{
					a[y++]=c[sr];
				}

			}
			else{
				int x = i;
				int y = k;
				for (int sr = x; sr < q-1; ++sr)
				{
					a[y++]=b[sr];
				}

			}


		}
	
void ms(int *a, int n){
	
		printf("%d \t",a[0]);
	
	int b[n/2];
	int c[n/2];
	if (n>1);
	int k = 0;
	for (int i = 0; i < n/2; ++i)
	{
		b[k++]=a[i];

	}
	k=0;
	for (int i = n/2; i < n; ++i)
	{
		c[k++]=a[i];
	}
	
	//printf("1\n");
	//ms(b,n/2);
	//ms(c,n/2);
	//merge(b,c,a,n/2,(n-n/2));
}
int main(int argc, char const *argv[])
{
	int a[2];a[0] =3;a[1]=2;
	ms(a,2);
	for (int i = 0; i < 2; ++i)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}