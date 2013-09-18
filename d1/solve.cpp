#include <stdio.h>

#define HIST_LENGTH 24
#define STRING_LENGTH 100
#define ReadString char[STRING_LENGTH];
#define Histogram short[HIST_LENGTH] ;

#define DBG_PRINT

#ifdef DBG_PRINT
#define DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG(fmt, ...)
#endif//DBG_PRINT

size_t mystrlen(char* str)
{
   size_t len = 0;     
   while(str[len++] != 0);
   return len; 
}

template<typename T>
void cleanArr(T hist[], size_t len)
{
   for (int i=0; i< len; ++i)
   { hist[i] = 0; }
}

void printArr(short hist[], size_t len)
{
   for (int i=0; i< len; ++i)
   { 
      DEBUG("%d,", hist[i]);
   }
   DEBUG("\b\n");
}

template<typename T>
void makeHist(T* instring, size_t inLngth, T offset,  short iHisto[])
{
   DEBUG("ln=%d, off=%d str='%s' \n", inLngth, offset, instring);
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

int main(int argv, char *argc[])
{
   char ciphs[STRING_LENGTH];
   char origs[STRING_LENGTH];
   FILE* pFile = NULL;   
   if(argv >= 2)
   {
      const char* fname = argc[1];
      pFile = fopen(fname,"r+");
   }
   else
   {
      pFile = freopen("newin", "r+", stdin);
   }
   if (!pFile)
   {
      return -1;
   }
   
   int res = 0;
   while ( (EOF != fscanf(pFile, "%s", ciphs)) &&
           (EOF != fscanf(pFile, "%s", origs)))   
   {
      DEBUG("%s\n",ciphs);
      DEBUG("%s\n",origs);
      short lciphHisto[HIST_LENGTH]={0};
      short lorigHisto[HIST_LENGTH]={0};
      makeHist(ciphs, mystrlen(ciphs), 'A', lciphHisto);
      makeHist(origs, mystrlen(origs), 'A', lorigHisto);
      printArr(lciphHisto, HIST_LENGTH-1);
      printArr(lorigHisto, HIST_LENGTH-1);
      short lciphHistHisto[STRING_LENGTH]={0};
      short lorigHistHisto[STRING_LENGTH]={0};
      makeHist<short>(lciphHisto, HIST_LENGTH-1, 0, lciphHistHisto);
      makeHist<short>(lorigHisto, HIST_LENGTH-1, 0, lorigHistHisto);
      printArr(lciphHistHisto, STRING_LENGTH-1);
      printArr(lorigHistHisto, STRING_LENGTH-1);
      if (cmpArr(lciphHistHisto,lorigHistHisto,HIST_LENGTH))
         printf("YES\r\n");
      else
         printf("NO\r\n");
   }
   return 0;
}