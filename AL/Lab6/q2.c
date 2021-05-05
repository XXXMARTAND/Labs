#include <stdio.h>
#include <stdlib.h>
int opcount = 0;
int partition(int *a, int l, int r){
	int pivot =a[l];
	int i = l;
	int j= r;
	while(i<j){
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j){
			int m =a[i];
			a[i]=a[j];
			a[j]=m;
		}
	}
	a[l]=a[j];
	a[j]=pivot;
	return j;
}
void qs(int *a, int l, int r){
	opcount++;
	int s;
	if(l<r){
		s=partition(a,l,r);
		qs(a,l,s-1);
		qs(a,s+1,r);
	}
}
int main(){
	int a[50],c;
	printf("Enter size \n");
	scanf("%d",&c);
	printf("Enter array of size %d\n",c);
	for (int i = 0; i < c; ++i)
	{
		scanf("%d",&a[i]);

			}
	printf("The sorted array is \n");
	qs(a,0,c-1);
	for (int i = 0; i < c; ++i)
	{
		printf("%d\n",a[i] );
	}
	printf("opcount :%d\n",opcount);

}
