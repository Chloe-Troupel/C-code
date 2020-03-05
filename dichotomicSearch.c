// file: dichotomicSearch.c
// author: Chloé TROUPEL
// purpose: to make a dichotomic search

#include <stdio.h>
int main (){
  int i;
  int array[100];
  int number;
  printf ("Enter the int you want to search for:\n");
  scanf("%d", &number);
  
  // creation of the array
  for(i=0; i<100;i++){
    *(array+i)= i;
  }
  
  // dichotomic search
  int inf=*array;
  int sup=*(array+99);
  int pos= -1;
  int middle;
  while ( (inf<=sup) && (pos == -1) ){
    middle = (sup + inf) / 2;
    if ( number < *(array+middle)){
      sup = middle - 1;
    }
    else if ( number > *(array+middle)) {
      inf = middle + 1;
    }
    else {
      pos = middle;
    }
  }
  
  // result
   if (pos==-1){
     printf("The number hasn't been found \n");
   }
   else{
     printf("The number has been found and it is at the position %d \n", pos+1);
   }
    
  return 0;
}
