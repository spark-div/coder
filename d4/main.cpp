#include <stdio.h>
#include <cmath>

//#define USE_DBG_PRINT

#ifdef USE_DBG_PRINT
#define DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG(fmt, ...)
#endif//DBG_PRINT

int main()
{
   char ch = 0;
   int i = 0, j = 0;
   bool hasonequote = false;
   while((scanf("%c", &ch)!= EOF) )
   {    
      if (ch == '"')
      {
         if (hasonequote)
         {
            printf("''");
            hasonequote = false;
         }
         else
         {
            printf("``");
            hasonequote = true;
         }
      }
      else
        printf("%c", ch);
   }
   return 0;
}