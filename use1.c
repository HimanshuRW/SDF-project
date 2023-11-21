#include <stdio.h>
#include <stdlib.h>

int main(){
  
  char str[200];
  int a,b,x;
  // open the file
  FILE *f = fopen("name.txt" , "w"); 
  
  // if there was an error
  if(f == NULL){
    perror("Error opening file"); // print error
    return(-1); 
  }
  // if there was no error
  else{ 
    x = fprintf(f, "%s %d %d\n", "Preksha_rawat",3,7);
    printf("x: %d\n",x);
    x = fprintf(f, "%s %d %d\n", "Prashanshu_rawat",13,117);
    printf("x: %d\n",x);
  }
  
  fclose(f); // close file
  
  return(0);
}