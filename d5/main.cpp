#include <stdio.h>        
#include <cstring>

//#define USE_DBG_PRINT

#ifdef USE_DBG_PRINT
#define DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG(fmt, ...)
#endif//DBG_PRINT

#define MAX_WORD_LN 65535

inline void zeroMem(char*  mem, size_t len)
{
   memset(mem, 0, len);
}

void reverse(char* word, size_t ln)
{
   for(size_t i=0; i < ln/2; ++i )
   {
      char tmp = word[i];
      word[i] = word[ln - i -1];
      word[ln - i - 1] = tmp;
   }
}

int main()
{
   char ch = 0, word[MAX_WORD_LN]={};
   size_t i = 0;
   int inres = 0;
   bool wordStart = true;

   do
   {    
      inres = scanf("%c", &ch);
      if ((ch != ' ') && ( ch != '\n') && inres != EOF)
      {
         if (i == 0) wordStart = true;
         if (wordStart)
         {
           word[i++] = ch;
         }
      }
      else
      { 
        if (i>0)
        {
            reverse(word, i);
            printf("%s", word);
            zeroMem(word, i);

            i = 0;
            wordStart = false;
         }         
         if (inres != EOF)
            printf("%c", ch);         
      }
   }
   while(( inres != EOF) );
   return 0;
}                                