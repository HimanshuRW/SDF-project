#include <stdio.h>
#include <stdlib.h>

int main(){
  
  char str[200];
  int a,b,x;
  // open the file
  FILE *f = fopen("name.txt" , "w"); 
    
    // ------- READ ENTRIES ------------
    x = fscanf(f, "%s %d %d", str,&a,&b);
    printf("x: %d\n",x);
    printf("str : %s\n",str);
    printf("a : %d, b: %d\n",a,b);
    printf("-----------------------------\n");
    // ---- reading the last entry --
    x = fscanf(f, "%s %d %d", str,&a,&b);
    printf("x: %d\n",x); // -1
  


    // --- writting entry ---


  fclose(f); // close file
  
  return(0);
}