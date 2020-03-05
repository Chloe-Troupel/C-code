// fichier : operator.h
// Chloé TROUPEL
// but de l'exercice : creer des fonctions puis les utiliser plus tard dans un autre programme


#ifndef OPERATOR_H  //permet de ne pas redefinir une fonction déjà écrite
#define OPERATOR_H

float somme(float num1, float num2){
      float addi = num1 + num2;
      return addi;
}
float soustraction(float num1, float num2){
      float sous = num1-num2;
      return sous;
}
float multiplication(float num1, float num2){
      float mult = num1*num2;
      return mult;
}
float division(float num1, float num2){
  float div = num1/num2;
  return div;
}
int modulo( num1,  num2){
  int mod = num1%num2;
  return mod;
}
int et(num1,num2){ //par défaut le type est int pour les arguments
  int ET = num1&num2;
  return ET;
}
int ou(num1,num2){
  int OU = num1|num2;
  return OU;
}
int negation(num1){
  int negation1 = ~num1;
  return negation1;
}

#endif
