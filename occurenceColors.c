// file: occurenceColors.c
// author: Chloé TROUPEL
// purpose: create an array of colors and if there is an occurrence displays it

#include <stdio.h>

int main (){

// initialisation
  int sizeArray = 150;
  typedef struct RGBA color;
    struct RGBA    {int R;int G;int B;int A;};
  color arrayColor[sizeArray];

  for (int i=0; i<sizeArray; i++){
    arrayColor[i].R = rand() % 5;
    arrayColor[i].G = rand() % 5;
    arrayColor[i].B = rand() % 5;
    arrayColor[i].A = rand() % 5;
    printf("Ox%2.2x Ox%2.2x Ox%2.2x Ox%2.2x \n", arrayColor[i].R, arrayColor[i].G, arrayColor[i].B, arrayColor[i].A);  //Ox%2.2x pour afficher en hexadecimal
  };
    
   typedef struct RGBAO counter;
    struct RGBAO    {int R;int G;int B;int A;int O;};
   counter result[sizeArray];
    
 printf("\n"); //pour des questions de clarté
 printf("Array of occurrences: \n");
 
// occurence verification
 for (int i=0; i<sizeArray; i++){
     int cpt=0;
     for(int j = i+1; j < sizeArray; j++){ //on parcourt tout le tableau pour chaque couleur pour voir les occurences
         if ((arrayColor[i].R == arrayColor[j].R) & (arrayColor[i].G == arrayColor[j].G) & (arrayColor[i].B == arrayColor[j].B) & (arrayColor[i].A == arrayColor[j].A)){
             cpt++;
             result[i].R=arrayColor[i].R; //on rentre le resultat dans le tableau resultat
             result[i].G=arrayColor[i].G;
             result[i].B=arrayColor[i].B;
             result[i].A=arrayColor[i].A;
             result[i].O=cpt;
             printf("Ox%2.2x Ox%2.2x Ox%2.2x Ox%2.2x %d \n", result[i].R, result[i].G, result[i].B, result[i].A,result[i].O);
         }
     }
 }
return 0;
}
