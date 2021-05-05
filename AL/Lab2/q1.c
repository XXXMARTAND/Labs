#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b){
	if (a>b)
		gcd(b,a);
	for (int i = a; i >=1; i--)
	{
		if(!(b%i)&&!(a%i))
			return i;
	}
}
int main(){
	int a,b;
	printf("Enter a and b\n");
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d\n",gcd(a,b) );
	return 0;
}