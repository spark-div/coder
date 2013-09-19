#include <stdio.h>

#define HIST_LENGTH 26
#define STRING_LENGTH 100
#define ReadString char[STRING_LENGTH];
#define Histogram short[HIST_LENGTH] ;

#define USE_DBG_PRINT

#ifdef USE_DBG_PRINT
#define DEBUG_PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define DEBUG_DO(SMTH) SMTH
#else
#define DEBUG_PRINT(fmt, ...)
#define DEBUG_DO(SMTH)
#endif//USE_DBG_PRINT

size_t mystrlen(char* str)
{
   size_t len = 0;     
   while(str[len++] != 0);
   return len; 
}


void printArr(short hist[], size_t len)
{
   for (int i=0; i< len; ++i)
   { 
      DEBUG_PRINT("%d,", hist[i]);
   }
   DEBUG_PRINT("\b\n");
}

template<typename T>
void makeHist(T* instring, size_t inLngth, T offset,  short iHisto[])
{
   DEBUG_PRINT("ln=%d, off=%d str='%s' \n", inLngth, offset, instring);
   for (int i=0; i< inLngth; ++i)
   {          
      iHisto[instring[i] - offset]++; 
   }      
}


bool cmpArr(short* arrA, short* arrB, size_t arr_size )
{
    for (int i=0; i < arr_size; ++i)
    {
       if (arrA[i] != arrB[i]) return false;
    }
    return true;
}

int main()
{
   char ciphs[STRING_LENGTH];
   char origs[STRING_LENGTH];
   while ( (EOF != scanf("%s", ciphs)) &&
           (EOF != scanf("%s", origs)))   
   {
      DEBUG_PRINT("%s\n",ciphs);
      DEBUG_PRINT("%s\n",origs);
      short lciphHisto[HIST_LENGTH]={0};
      short lorigHisto[HIST_LENGTH]={0};
      makeHist(ciphs, mystrlen(ciphs), 'A', lciphHisto);
      makeHist(origs, mystrlen(origs), 'A', lorigHisto);
      DEBUG_DO(printArr(lciphHisto, HIST_LENGTH));
      DEBUG_DO(printArr(lorigHisto, HIST_LENGTH));
      short lciphHistHisto[STRING_LENGTH]={0};
      short lorigHistHisto[STRING_LENGTH]={0};
      makeHist<short>(lciphHisto, HIST_LENGTH, 0, lciphHistHisto);
      makeHist<short>(lorigHisto, HIST_LENGTH, 0, lorigHistHisto);
      DEBUG_DO(printArr(lciphHistHisto, STRING_LENGTH));
      DEBUG_DO(printArr(lorigHistHisto, STRING_LENGTH));
      if (cmpArr(lciphHistHisto,lorigHistHisto,HIST_LENGTH))
         printf("YES\r\n");
      else
         printf("NO\r\n");
   }
   return 0;
}