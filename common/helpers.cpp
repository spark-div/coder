
void printArr(short hist[], size_t len)
{
   for (int i=0; i< len; ++i)
   { 
      DEBUG("%d,", hist[i]);
   }
   DEBUG("\b\n");
}


int main()
{

#ifdef USE_FILES
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
#else
   FILE* pFile = stdin;   
#endif//USE_FILES
}