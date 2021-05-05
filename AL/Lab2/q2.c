#include <stdio.h>
int gcd(int a, int b){
	if(b>a)
		gcd(b,a);
	
	int ans = 1;
	int temp = a;
	
	for (int f = 2;f<=temp;f++){
		
		while(!(a%f)&&!(b%f)){
			ans = ans * f;
			b= b/f;
			a=a/f;
			
			if(!a||!b)
				return ans;
		}
	}
	return ans;
}
int main(){
	int a,b;
	printf("Enter a and b\n");
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d\n",gcd(a,b) );
	return 0;
}
