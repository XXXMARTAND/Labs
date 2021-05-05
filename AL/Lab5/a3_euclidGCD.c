#include<stdio.h>

int gcd(int m,int n)
{
	if(n>m)
		gcd(n,m);
	int r;
	int count=0;
	while(n!=0)
	{
		count++;
		r=m%n;
		m=n;
		n=r;
	}
	return m;
}


void main()
{
	int a,b;
	printf("enter 2 numbers:\n");
	scanf("%d %d",&a,&b);
	int ans=gcd(a,b);
	printf("gcd = %d \n",ans);
}