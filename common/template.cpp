#include <stdio.h>


#define DBG_PRINT

#ifdef DBG_PRINT
#define DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG(fmt, ...)
#endif//DBG_PRINT


int main(int argv, char *argc[])
{
   int res = 0;
   while ( EOF != scanf("%s", ciphs) )   
   {
      DEBUG("%s\n","some");

      printf("YES\r\n");
   }
   return 0;
}