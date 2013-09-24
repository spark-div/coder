#include <stdio.h>
#include <cmath>

int eval(int InputNum)
{
   double d = log10(double(InputNum)) / log10(2.0);
   //printf("input=%d,double=%f\n", InputNum, d);
   int log2Num = ceil(log10(double(InputNum)) / log10(2.0));
   return log2Num;   
}

int main()
{
   int input = 0, count = 1;
   while((scanf("%d\n", &input)!= EOF) && (input > 0) )
   {
      //printf("Case %d: input:%d result :%d\r\n", count++, input, eval(input));
        printf("Case %d: %d\n", count++, eval(input));
   }
   return 0;
}