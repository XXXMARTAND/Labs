
#include <stdio.h>

int isStrong( int num){
    int i, originalNum, lastDigit, sum;
    long fact;




    

    originalNum=num;    

    sum = 0;


    while(num > 0)
    {


        lastDigit = num % 10;


        fact = 1;
        for(i=1; i<=lastDigit; i++)
        {
            fact = fact * i;
        }


        sum = sum + fact;

        num = num / 10;
    }

    /* Check Strong number condition */
    if(sum == originalNum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
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
   for (int i = 0; i < a; ++i)
   {
       if (!isStrong(b[i]))
       {
           printf("%d\n",b[i] );
       }
   }

}
