#include<stdio.h> 


int sqrt(int x) 
{ 
    if (x == 0 || x == 1) 
    return x; 

    int i = 1, result = 1; 
    while (result <= x) 
    { 
      i++; 
      result = i * i; 
    } 
    return i - 1; 
} 
  

int main() 
{ 
    int x ;
    printf("Enter n\n");
    scanf("%d",&x);
    printf("%d\n",sqrt(x) );
    return 0; 
} 