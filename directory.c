// file: directory.c
// author: Chloé TROUPEL
// purpose: user gives a directory's path and the programm display the name of all files with 2 methods

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "directory.h"

//To read a directory with an iterative process
char read_dir(char *rep){
  
    DIR *dirp =  opendir(rep);    //open a directory with rep the path
  
    if (dirp == NULL) {           // error if can't open directory
        perror("opendir");
        return(EXIT_FAILURE);
    }
  
    struct dirent * ent;         // struct to read directory
    while(1) {
      ent = readdir(dirp);
      if (ent == NULL) {        //readdir return null if no more files to read
        break;
      }
      printf("%s\n", ent->d_name); //annother writing: (*ent).d_name instead of ent->d_name
    }
    closedir(dirp);             //close a directory
    return(0);
}


//To read a directory with the recursion
char read_dir_recursif(char *c){
  char path[2000];
  struct dirent *dir_content;
  DIR *rep =  opendir(c);
  
  if (rep == NULL) {
    perror("opendir");
    return(EXIT_FAILURE);
  }
  
  while((dir_content = readdir(rep))!=NULL)
    {
        if (dir_content -> d_type == DT_DIR) //if it is a directory
        {
          if (strcmp(dir_content -> d_name, ".")!=0 && strcmp(dir_content -> d_name, "..")!=0) // if the file is not in the current directory and not in the last one
           {
         // to have the path of sub directory
            strcpy(path, c);
            strcat(path,"/");
            strcat(path, dir_content -> d_name);
            printf(" ************** Directory %s ***************\n", dir_content -> d_name);
            read_dir_recursif(path);
            printf("************** Exit directory %s ************\n", dir_content -> d_name);
      }
        }
        else
        {
           printf("-> %s\n", dir_content -> d_name);
        }
    }
    closedir(rep);
    return(0);
}


int main(int argc, char **argv ) {

    if (argc < 2) {
      printf("There is no path for readdir\n");
      return(EXIT_FAILURE);
    }

//1st method
//    read_dir(argv[1]);
//2nd method
    read_dir_recursif("/Users/Chloe3/Ecole/Administration");
    
    return(0);
}


  
  

