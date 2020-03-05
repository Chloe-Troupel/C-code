// file: arrayptr.c
// author: Chloé TROUPEL
// purpose: create 2 array with random int and float values. Use of pointers


#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

int main() {

//initialization
  srand(time(NULL));
  int i;
  int sizeArray = 20;
  int array1[sizeArray];
  float array2[sizeArray];
  
//Adding of random values in the arrays
  printf ("\nint array \n");
  for (i=0; i<sizeArray; i++){
    *(array1+i)=rand()%100;          //int between 0 et 99
    printf ("%i ", *(array1+i));
  }
  printf("\n \n");
  
  printf ("float array \n");
  for (i=0; i<sizeArray; i++){
    *(array2+i)=(rand()%100)/10.0;  //float betwee 0 et 10
    printf ("%f ", *(array2+i));
  }
  printf("\n \n");
  
  
//if the index is divisible by 2, we multiply the value at this position by 3
  printf ("int array after multiplication \n");
  for (i=0; i<sizeArray; i++){
    if (i%2 == 0){
      *(array1+i)=*(array1+i)*3;
    }
    printf ("%i ", *(array1+i));
  }
  printf("\n \n");
  
  printf ("float array after multiplication \n");
  for (i=0; i<sizeArray; i++){
    if (i%2 == 0){
      *(array2+i)=*(array2+i)*3;
    }
    printf ("%f ", *(array2+i));
  }
  printf("\n \n");
  
  return 0;
}


