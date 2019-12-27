#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
  char str1[]="Sample string";
  char *str2 = (char *) malloc(5*sizeof(char));
  char *str3 = (char *) malloc(5*sizeof(char));
  strcpy (str2,str1);
  strcpy (str3,"copy successful");
  printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
  printf ("str1: %d\nstr2: %d\nstr3: %d\n",sizeof(str1),sizeof(str2),sizeof(str3));
  char str4[5], str5[5];
  strcpy (str5,str1);
  strcpy (str4,str1);
  printf ("str4: %s\nstr5: %s\n",str4,str5);
  printf ("str4: %d\nstr5: %d\n",sizeof(str4),sizeof(str5));
  return 0;
}
