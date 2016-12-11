#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * myStrConca(const char * str1, const char * str2)
{
  unsigned int rozm = strlen(str1) + strlen(str2)+1;
  //printf("%d\n",rozm);
  char *str3;
  int i=0;
  str3 =(char *) malloc(rozm* sizeof(*str3));
  for(i =0; i<strlen(str1);i++)
    str3[i] = str1[i];
  for(i; i<rozm;i++)
    str3[i] = str2[i-strlen(str1)];
  return str3;
};

int main()
{
  const char * str1 = "abcdefghijklmnoprstuwxyz";
  const char * str2 = " a tu nie wiem";
  char * str3 = myStrConca(str1,str2);
  printf("%s\n",str3);
  free(str3);
  return 0;
}
