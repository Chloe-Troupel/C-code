/* Fichier: client.c
* Communication client-serveur
* Auteur: Chloé TROUPEL
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

/* envoi et reception de message
 */
int envoie_recois_message(int socketfd) {
  char data[5];
  memset(data, 0, sizeof(data));
  char message[100];
  printf("Votre message (max 1000 caracteres): \n");
  fgets(message, 1024, stdin);
  strcpy(data, "message: ");  //ajout de message: à data
  strcat(data, message);
  
  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  memset(data, 0, sizeof(data));
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);
 
  return 0;
}

//********************* Exercice 5.5 **************************************************

int envoie_operateur_numeros(int socketfd){
  char operateur_num[20];
  char data[1024];
  memset(data, 0, sizeof(data));
  printf("Quel est votre calcul ? \n");
  fgets(operateur_num, 1024, stdin);
  
   
  strcpy(data, "calcule: ");
  strcat(data, operateur_num);
 
// envoie du message
   int write_status = write(socketfd, data, strlen(data));
   if ( write_status < 0 ) {
     perror("erreur ecriture");
     exit(EXIT_FAILURE);
   }

// reception du résultat
   memset(data, 0, sizeof(data));
   int read_status = read(socketfd, data, sizeof(data));
   if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
   }

   printf("Résultat: %s\n", data);
   return 0;
}
 
 
//************************* Exercice 5.6 **************************************************
//On aurait pu le faire en une fonction mais je voulais laisser la possibilité de choisir entre moyenne ou la somme totale des notes. On a donc beaucoup de répétition
 
int envoie_recois_notesomme(int socketfd){
  char data1[1024];
  char notes11[30];
  char notes12[30];
  char notes13[30];
  char notes14[30];
  char notes15[30];
  FILE* fichiernote11 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note1.txt", "r");
  FILE* fichiernote12 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note2.txt", "r");
  FILE* fichiernote13 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note3.txt", "r");
  FILE* fichiernote14 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note4.txt", "r");
  FILE* fichiernote15 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note5.txt", "r");
  memset(data1, 0, sizeof(data1));
  fgets(notes11, 1024, fichiernote11);
  strtok(notes11,"\n");   //pour enlever le enter à la fin de chaque fichier test
  fgets(notes12, 1024, fichiernote12);
  strtok(notes12,"\n");
  fgets(notes13, 1024, fichiernote13);
  strtok(notes13,"\n");
  fgets(notes14, 1024, fichiernote14);
  strtok(notes14,"\n");
  fgets(notes15, 1024, fichiernote15);
  strtok(notes15,"\n");

  strcpy(data1, "notes: ");  //ajout de message: à data
  strcat(data1, notes11);
  strcat(data1, " ");         // pour espacer les notes pour pouvoir les faire lire par scanf par le serveur
  strcat(data1, notes12);
  strcat(data1, " ");
  strcat(data1, notes13);
  strcat(data1, " ");
  strcat(data1, notes14);
  strcat(data1, " ");
  strcat(data1, notes15);
  
//****on reproduit le meme procédé pour chaque étudiant
  char notes21[30];
  char notes22[30];
  char notes23[30];
  char notes24[30];
  char notes25[30];
  FILE* fichiernote21 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note1.txt", "r");
  FILE* fichiernote22 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note2.txt", "r");
  FILE* fichiernote23 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note3.txt", "r");
  FILE* fichiernote24 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note4.txt", "r");
  FILE* fichiernote25 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note5.txt", "r");

  fgets(notes21, 1024, fichiernote21);
  strtok(notes21,"\n");
  fgets(notes22, 1024, fichiernote22);
  strtok(notes22,"\n");
  fgets(notes23, 1024, fichiernote23);
  strtok(notes23,"\n");
  fgets(notes24, 1024, fichiernote24);
  strtok(notes24,"\n");
  fgets(notes25, 1024, fichiernote25);
  strtok(notes25,"\n");

  strcat(data1, " ");
  strcat(data1, notes21);
  strcat(data1, " ");
  strcat(data1, notes22);
  strcat(data1, " ");
  strcat(data1, notes23);
  strcat(data1, " ");
  strcat(data1, notes24);
  strcat(data1, " ");
  strcat(data1, notes25);
  
  char notes31[30];
  char notes32[30];
  char notes33[30];
  char notes34[30];
  char notes35[30];
  FILE* fichiernote31 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note1.txt", "r");
  FILE* fichiernote32 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note2.txt", "r");
  FILE* fichiernote33 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note3.txt", "r");
  FILE* fichiernote34 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note4.txt", "r");
  FILE* fichiernote35 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note5.txt", "r");

  fgets(notes31, 1024, fichiernote31);
  strtok(notes31,"\n");
  fgets(notes32, 1024, fichiernote32);
  strtok(notes32,"\n");
  fgets(notes33, 1024, fichiernote33);
  strtok(notes33,"\n");
  fgets(notes34, 1024, fichiernote34);
  strtok(notes34,"\n");
  fgets(notes35, 1024, fichiernote35);
  strtok(notes35,"\n");

  strcat(data1, " ");
  strcat(data1, notes31);
  strcat(data1, " ");
  strcat(data1, notes32);
  strcat(data1, " ");
  strcat(data1, notes33);
  strcat(data1, " ");
  strcat(data1, notes34);
  strcat(data1, " ");
  strcat(data1, notes35);
  
  char notes41[30];
  char notes42[30];
  char notes43[30];
  char notes44[30];
  char notes45[30];
  FILE* fichiernote41 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note1.txt", "r");
  FILE* fichiernote42 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note2.txt", "r");
  FILE* fichiernote43 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note3.txt", "r");
  FILE* fichiernote44 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note4.txt", "r");
  FILE* fichiernote45 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note5.txt", "r");

  fgets(notes41, 1024, fichiernote41);
  strtok(notes41,"\n");
  fgets(notes42, 1024, fichiernote42);
  strtok(notes42,"\n");
  fgets(notes43, 1024, fichiernote43);
  strtok(notes43,"\n");
  fgets(notes44, 1024, fichiernote44);
  strtok(notes44,"\n");
  fgets(notes45, 1024, fichiernote45);
  strtok(notes45,"\n");

  strcat(data1, " ");
  strcat(data1, notes41);
  strcat(data1, " ");
  strcat(data1, notes42);
  strcat(data1, " ");
  strcat(data1, notes43);
  strcat(data1, " ");
  strcat(data1, notes44);
  strcat(data1, " ");
  strcat(data1, notes45);
  
  char notes51[30];
  char notes52[30];
  char notes53[30];
  char notes54[30];
  char notes55[30];
  FILE* fichiernote51 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note1.txt", "r");
  FILE* fichiernote52 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note2.txt", "r");
  FILE* fichiernote53 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note3.txt", "r");
  FILE* fichiernote54 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note4.txt", "r");
  FILE* fichiernote55 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note5.txt", "r");

  fgets(notes51, 1024, fichiernote51);
  strtok(notes51,"\n");
  fgets(notes52, 1024, fichiernote52);
  strtok(notes52,"\n");
  fgets(notes53, 1024, fichiernote53);
  strtok(notes53,"\n");
  fgets(notes54, 1024, fichiernote54);
  strtok(notes54,"\n");
  fgets(notes55, 1024, fichiernote55);
  strtok(notes55,"\n");


  strcat(data1, " ");
  strcat(data1, notes51);
  strcat(data1, " ");
  strcat(data1, notes52);
  strcat(data1, " ");
  strcat(data1, notes53);
  strcat(data1, " ");
  strcat(data1, notes54);
  strcat(data1, " ");
  strcat(data1, notes55);
  
  printf("%s\n",data1);
  
  int write_status = write(socketfd, data1, strlen(data1));

  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }
  
  printf("Somme total notes de chaque étudiants dans l'ordre :\n");
 
  memset(data1, 0, sizeof(data1));
  int read_status = read(socketfd, data1, sizeof(data1));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data1);
 
  return 0;
} 

int envoie_recois_notemoyenne(int socketfd){
  char data1[1024];
  char notes11[30];
  char notes12[30];
  char notes13[30];
  char notes14[30];
  char notes15[30];
  FILE* fichiernote11 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note1.txt", "r");
  FILE* fichiernote12 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note1.txt", "r");
  FILE* fichiernote13 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note1.txt", "r");
  FILE* fichiernote14 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note1.txt", "r");
  FILE* fichiernote15 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note1.txt", "r");
  memset(data1, 0, sizeof(data1));
  fgets(notes11, 1024, fichiernote11);
  strtok(notes11,"\n");   //pour enlever le enter à la fin de chaque fichier test
  fgets(notes12, 1024, fichiernote12);
  strtok(notes12,"\n");
  fgets(notes13, 1024, fichiernote13);
  strtok(notes13,"\n");
  fgets(notes14, 1024, fichiernote14);
  strtok(notes14,"\n");
  fgets(notes15, 1024, fichiernote15);
  strtok(notes15,"\n");

  strcpy(data1, "notes: ");  //ajout de message: à data
  strcat(data1, notes11);
  strcat(data1, " ");          // pour espacer les notes pour pouvoir les faire lire par scanf par le serveur
  strcat(data1, notes12);
  strcat(data1, " ");
  strcat(data1, notes13);
  strcat(data1, " ");
  strcat(data1, notes14);
  strcat(data1, " ");
  strcat(data1, notes15);
  
//****on reproduit le meme procédé pour chaque étudiant
  char notes21[30];
  char notes22[30];
  char notes23[30];
  char notes24[30];
  char notes25[30];
  FILE* fichiernote21 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note2.txt", "r");
  FILE* fichiernote22 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note2.txt", "r");
  FILE* fichiernote23 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note2.txt", "r");
  FILE* fichiernote24 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note2.txt", "r");
  FILE* fichiernote25 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note2.txt", "r");

  fgets(notes21, 1024, fichiernote21);
  strtok(notes21,"\n");
  fgets(notes22, 1024, fichiernote22);
  strtok(notes22,"\n");
  fgets(notes23, 1024, fichiernote23);
  strtok(notes23,"\n");
  fgets(notes24, 1024, fichiernote24);
  strtok(notes24,"\n");
  fgets(notes25, 1024, fichiernote25);
  strtok(notes25,"\n");

  strcat(data1, " ");
  strcat(data1, notes21);
  strcat(data1, " ");
  strcat(data1, notes22);
  strcat(data1, " ");
  strcat(data1, notes23);
  strcat(data1, " ");
  strcat(data1, notes24);
  strcat(data1, " ");
  strcat(data1, notes25);
  
  char notes31[30];
  char notes32[30];
  char notes33[30];
  char notes34[30];
  char notes35[30];
  FILE* fichiernote31 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note3.txt", "r");
  FILE* fichiernote32 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note3.txt", "r");
  FILE* fichiernote33 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note3.txt", "r");
  FILE* fichiernote34 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note3.txt", "r");
  FILE* fichiernote35 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note3.txt", "r");

  fgets(notes31, 1024, fichiernote31);
  strtok(notes31,"\n");
  fgets(notes32, 1024, fichiernote32);
  strtok(notes32,"\n");
  fgets(notes33, 1024, fichiernote33);
  strtok(notes33,"\n");
  fgets(notes34, 1024, fichiernote34);
  strtok(notes34,"\n");
  fgets(notes35, 1024, fichiernote35);
  strtok(notes35,"\n");

  strcat(data1, " ");
  strcat(data1, notes31);
  strcat(data1, " ");
  strcat(data1, notes32);
  strcat(data1, " ");
  strcat(data1, notes33);
  strcat(data1, " ");
  strcat(data1, notes34);
  strcat(data1, " ");
  strcat(data1, notes35);
  
  char notes41[30];
  char notes42[30];
  char notes43[30];
  char notes44[30];
  char notes45[30];
  FILE* fichiernote41 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note4.txt", "r");
  FILE* fichiernote42 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note4.txt", "r");
  FILE* fichiernote43 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note4.txt", "r");
  FILE* fichiernote44 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note4.txt", "r");
  FILE* fichiernote45 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note4.txt", "r");

  fgets(notes41, 1024, fichiernote41);
  strtok(notes41,"\n");
  fgets(notes42, 1024, fichiernote42);
  strtok(notes42,"\n");
  fgets(notes43, 1024, fichiernote43);
  strtok(notes43,"\n");
  fgets(notes44, 1024, fichiernote44);
  strtok(notes44,"\n");
  fgets(notes45, 1024, fichiernote45);
  strtok(notes45,"\n");

  strcat(data1, " ");
  strcat(data1, notes41);
  strcat(data1, " ");
  strcat(data1, notes42);
  strcat(data1, " ");
  strcat(data1, notes43);
  strcat(data1, " ");
  strcat(data1, notes44);
  strcat(data1, " ");
  strcat(data1, notes45);
  
  char notes51[30];
  char notes52[30];
  char notes53[30];
  char notes54[30];
  char notes55[30];
  FILE* fichiernote51 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/1/note5.txt", "r");
  FILE* fichiernote52 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/2/note5.txt", "r");
  FILE* fichiernote53 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/3/note5.txt", "r");
  FILE* fichiernote54 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/4/note5.txt", "r");
  FILE* fichiernote55 = fopen ("/fs03/share/users/chloe.troupel/home/Documents/TP_C/TP5final/etudiant/5/note5.txt", "r");

  fgets(notes51, 1024, fichiernote51);
  strtok(notes51,"\n");
  fgets(notes52, 1024, fichiernote52);
  strtok(notes52,"\n");
  fgets(notes53, 1024, fichiernote53);
  strtok(notes53,"\n");
  fgets(notes54, 1024, fichiernote54);
  strtok(notes54,"\n");
  fgets(notes55, 1024, fichiernote55);
  strtok(notes55,"\n");

  strcat(data1, " ");
  strcat(data1, notes51);
  strcat(data1, " ");
  strcat(data1, notes52);
  strcat(data1, " ");
  strcat(data1, notes53);
  strcat(data1, " ");
  strcat(data1, notes54);
  strcat(data1, " ");
  strcat(data1, notes55);
  
  printf("%s\n",data1);

  
  int write_status = write(socketfd, data1, strlen(data1));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }
  printf("Moyenne de chaques sujets dans l'ordre : \n");

// lecture 1er message
  memset(data1, 0, sizeof(data1));
  int read_status = read(socketfd, data1, sizeof(data1));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }
  printf("%s\n",data1);
  

  return 0;
    
}

    
 
    
    
int main() {
  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'un socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  //demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if ( connect_status < 0 ) {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }
  
//***** appel des fonctions
//  envoie_recois_message(socketfd);
//  envoie_operateur_numeros(socketfd);
//  envoie_recois_notesomme(socketfd);    
  envoie_recois_notemoyenne(socketfd);
        
  close(socketfd);
}
