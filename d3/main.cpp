#include <stdio.h>
#include <cmath>

//#define USE_DBG_PRINT

#ifdef USE_DBG_PRINT
#define DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG(fmt, ...)
#endif//DBG_PRINT

int eval_number_of_cycles(int in)
{
   long long int n = in, count = 1;
   while(n != 1)
   {                       
      DEBUG("n=%d,", n);
      //odd or even   
      if ((n & 0x1) == 0)
      {
         DEBUG(" even,");
         n = n >> 1;
      }
      else
      {
         DEBUG(" odd,");
         n = n*3 + 1;
      }
      count++;
   } 
   DEBUG("cnt=%d \n", count);
   return count;
}

int main()
{
   int i = 0, j = 0;
   while((scanf("%d %d\n", &i, &j)!= EOF) )
   {    
        int max_cyc = 0, st = 0, en =0 ;
        if (i < j) st = i, en = j;
        else       st = j, en = i;
        for (int it = st; it <= en; it++)
        {             
           int cl = eval_number_of_cycles(it);
           DEBUG("n=%d  mc=%d,", it, cl);
           if ( cl > max_cyc) 
             max_cyc = cl;
        }
        DEBUG("\n");
        printf("%d %d %d\n", i, j, max_cyc );
   }
   return 0;
}