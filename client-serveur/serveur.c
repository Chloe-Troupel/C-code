/* Fichier: serveur.c
 * Communication client-serveur
 * Auteur: Chloé TROUPEL
 */


#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "serveur.h"
#include "operator.h"

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data) {
  int data_size = write (client_socket_fd, (void *) data, strlen(data));
      
  if (data_size < 0) {
    perror("erreur ecriture");
    return(EXIT_FAILURE);
  }
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd) {
  struct sockaddr_in client_addr;
  char data[1024];

  int client_addr_len = sizeof(client_addr);
 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  memset(data, 0, sizeof(data));

  //lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data));
      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
        
  printf ("Réponse: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);

  //Si le message commence par le mot: 'message:'
  if (strcmp(code, "message:") == 0) {
    char message[100];
    printf("entrer une réponse \n");
    fgets(message, 1024, stdin);
    renvoie_message(client_socket_fd, message);
   // renvoie_message(client_socket_fd, data);
  }

  //fermer le socket
  close(socketfd);
}

//************** Exercice 5.5 **********************************************

int recois_numeros_calcule( int socketfd) {
  struct sockaddr_in client_addr;
  char data[1024];

  int client_addr_len = sizeof(client_addr);
 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  memset(data, 0, sizeof(data));

  //lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data));
      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
        
  printf ("Message Reçu: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);

  //Si le message commence par le mot: 'calcule:'
   if (strcmp(code, "calcule:") == 0) {
    char operateur;
    int nbvalue;
    float numero1, numero2;
    nbvalue = sscanf(data, "%*s %c %f %f", &operateur, &numero1, &numero2); //%* permet de ne pas prendre le calcule:
    if (nbvalue != 3) { printf("erreur lecture \n");}
    switch (operateur) {
    case '+':
    {
      float som = somme(numero1,numero2);
      char reponse[50];
      sprintf(reponse, "%.2f", som);  //permet de convertir un int ou float en chaine de caractere
      renvoie_message(client_socket_fd, reponse);
      break;
    }
    case '-':
    {
      float sous = soustraction(numero1,numero2);
      char reponse[50];
      sprintf(reponse, "%.2f", sous);
      renvoie_message(client_socket_fd, reponse);
      break;
    }
    case '*':
    {
      float multi = multiplication(numero1,numero2);
     char reponse[50];
       sprintf(reponse, "%.2f", multi);
      renvoie_message(client_socket_fd, reponse);
      break;
    }
    case '/':
    {
      float div = division(numero1,numero2);
      char reponse[50];
      sprintf(reponse, "%.2f", div);
      renvoie_message(client_socket_fd, reponse);
      
      break;
    }
    case '%':
    {
      int mod = modulo(numero1,numero2);
      char reponse[50];
      sprintf(reponse, "%d", mod);
      renvoie_message(client_socket_fd, reponse);
      break;
    }
     case '&':
    {
      int ET = et(numero1,numero2);
      char reponse[50];
      sprintf(reponse, "%d", ET);
      renvoie_message(client_socket_fd, reponse);
      break;
    }
    case '|':
    {
      int OU = ou(numero1,numero2);
      char reponse[50];
      sprintf(reponse, "%d", OU);
      renvoie_message(client_socket_fd, reponse);
      break;
    }
    case '~':
    {
      int negation1 = negation(numero1);
      char reponse[50];
      sprintf(reponse, "%d", negation1);
      renvoie_message(client_socket_fd, reponse);
      break;
    }
   }
  }

  //fermer le socket
  close(socketfd);
}
    
//********** Exercice 5.6 ***************************************************
    
int recois_envoie_notesomme( int socketfd) {
  struct sockaddr_in client_addr;
  char data[1024];
  
  int client_addr_len = sizeof(client_addr);
 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  memset(data, 0, sizeof(data));

  //lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data));

      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
        
  printf ("Messages Reçus: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);

  //Si le message commence par le mot: 'notes:'
  if (strcmp(code, "notes:") == 0) {
    int note11, note12, note13, note14, note15, nbvalue, sommetotal1, note21, note22, note23, note24, note25, note31, note32, note33, note34, note35, note41, note42, note43, note44, note45, sommetotal2, sommetotal3, sommetotal4;
    int nbvalue2, note51, note52, note53, note54, note55, sommetotal5;
    // on recupere les données
    nbvalue = sscanf(data, "%*s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &note11, &note12, &note13, &note14, &note15, &note21, &note22, &note23, &note24, &note25, &note31, &note32, &note33, &note34, &note35 ,&note41, &note42, &note43, &note44, &note45, &note51, &note52, &note53, &note54, &note55);
    if (nbvalue != 25) { printf("Erreur lecture \n");}
    
    sommetotal1= note11 + note12 + note13 + note14 + note15;
    sommetotal2= note21 + note22 + note23 + note24 + note25;
    sommetotal3= note31 + note32 + note33 + note34 + note35;
    sommetotal4= note41 + note42 + note43 + note44 + note45;
    sommetotal5= note51 + note52 + note53 + note54 + note55;
    
 //pour convertir un entier en str
    char str1[10];
    sprintf(str1, "%d", sommetotal1);
    char str2[10];
    sprintf(str2, "%d", sommetotal2);
    char str3[10];
    sprintf(str3, "%d", sommetotal3);
    char str4[10];
    sprintf(str4, "%d", sommetotal4);
    char str5[10];
    sprintf(str5, "%d", sommetotal5);
    char reponse[40];
 // pour concatener les reponses
    strcat(reponse, str1);
    strcat(reponse, " ");
    strcat(reponse, str2);
    strcat(reponse, " ");
    strcat(reponse, str3);
    strcat(reponse, " ");
    strcat(reponse, str4);
    strcat(reponse, " ");
    strcat(reponse, str5);
    strcat(reponse, " ");
    printf("%s",reponse);
 
//renvoie de la réponse
   renvoie_message(client_socket_fd, reponse);
  }

}
 
int recois_envoie_notemoyenne( int socketfd) { // meme fonction que precedente mais ici on calcule la moyenne
  struct sockaddr_in client_addr;
  char data[1024];
  
  int client_addr_len = sizeof(client_addr);
 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  memset(data, 0, sizeof(data));

  //lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data));
      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
        
  printf ("Messages Reçus: %s \n", data);
  char code[10];
  sscanf(data, "%s:", code);

  if (strcmp(code, "notes:") == 0) {
    int note11, note12, note13, note14, note15, nbvalue, note21, note22, note23, note24, note25, note31, note32, note33, note34, note35, note41, note42, note43, note44, note45, note51, note52, note53, note54, note55;
    float moyenne1,moyenne2, moyenne3, moyenne4, moyenne5;
    nbvalue = sscanf(data, "%*s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &note11, &note12, &note13, &note14, &note15, &note21, &note22, &note23, &note24, &note25, &note31, &note32, &note33, &note34, &note35 ,&note41, &note42, &note43, &note44, &note45,&note51, &note52, &note53, &note54, &note55 );
    
    if (nbvalue != 25) { printf("Erreur lecture \n");}
    moyenne1= ((float)(note11) + (float)(note12) + (float)(note13) + (float)(note14) + (float)(note15))/5;
    moyenne2= ((float)(note21) + (float)(note22) + (float)(note23) + (float)(note24) + (float)(note25))/5;
    moyenne3= ((float)(note31) + (float)(note32) + (float)(note33) + (float)(note34) + (float)(note35))/5;
    moyenne4= ((float)(note41) + (float)(note42) + (float)(note43) + (float)(note44) + (float)(note45))/5;
    moyenne5= ((float)(note51) + (float)(note52) + (float)(note53) + (float)(note54) + (float)(note55))/5;
    char str1[50];
    sprintf(str1, "%.2f", moyenne1);
    char str2[50];
    sprintf(str2, "%.2f", moyenne2);
    char str3[50];
    sprintf(str3, "%.2f", moyenne3);
    char str4[50];
    sprintf(str4, "%.2f", moyenne4);
    char str5[50];
    sprintf(str5, "%.2f", moyenne5);
    char reponse[100];
    strcat(reponse, str1);
    strcat(reponse, " ");
    strcat(reponse, str2);
    strcat(reponse, " ");
    strcat(reponse, str3);
    strcat(reponse, " ");
    strcat(reponse, str4);
    strcat(reponse, " ");
 //renvoie de la réponse
    renvoie_message(client_socket_fd, reponse);
  }
 
 
 }
 

 
 
int main() {

  int socketfd;
  int bind_status;
  int client_addr_len;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'un socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  bind_status = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (bind_status < 0 ) {
    perror("bind");
    return(EXIT_FAILURE);
  }
 
  listen(socketfd, 10);
  
//***** appel des fonctions
//   recois_envoie_message(socketfd);
//   recois_numeros_calcule(socketfd);
//   recois_envoie_notesomme(socketfd);
   recois_envoie_notemoyenne(socketfd);

  return 0;
}
