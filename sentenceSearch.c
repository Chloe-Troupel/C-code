// file: sentenceSearch.c
// author: Chloé TROUPEL
// purpose: create an array of 10 senntences and look for a sentence in the array

#include <stdio.h>
#include <string.h>

int main (){
    
    int p=0;
    char sentSearch[1][31] = {"\0"};  //sentence to look for (nno more than 30 character)
    printf ("The sentence you want to look for ? \n");
    scanf("%[^\n]", &sentSearch);  //[^\n] allows to get all the character even the space
    
    char sentenceArray[][31] = { "monday","lundi, meilleur jour de la semaine", "N'est t-il pas ?", "mercredi","juste un peu", "quand même", "lorsque", "le matin", "le soir", "le midi", "manque d'inspiration certain" }; //the size automatically adjusts itself
    
    int i;
    for (i = 0; i < sizeof sentenceArray / sizeof sentenceArray[0]; i++)
    {  if (strcmp(sentSearch, sentenceArray[i]) == 0)
        {
            p=-1;
        }
    }
    
//result
    if (p ==-1){
          printf("the sentence has been found\n");}
    else {
          printf("the sentence hasn't been found \n");}

    return 0;
}
