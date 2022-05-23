#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/utsname.h>
//works fine
void print_errors(char *this){
     fprintf(stderr, "Tu as mal utilisé la fonctionne %s, l'erreur ici c'est:%s\n",this,strerror(errno));
}

void version(){
  puts("TP : Programmation Linux Windows, CentraleSupélec, 2022 \u00A9\nuname  program : basic functionnality works fine with some few features");
  exit(EXIT_FAILURE);

}

void usage(char* pn){
  printf("Utilisation : %s [OPTION]",pn);
  printf("Tu peux utiliser cette fonction pour afficher des informations system.\n\n");
  printf("   -v  Afficher la version de l'OS\n");
   printf("   -r Afficher la version de la release\n");
    printf("   -s  Afficher le nom du système\n");
     printf("   -m  Afficher des informations sur la machine\n");
      printf("   -n  Afficher des informations sur le nom de l'équipement\n");
       printf("   -V  Afficher des informations sur la version du %s\n",pn);
  printf("   -h  Afficher de l'aide \n\n");
  printf("Examples\n");
  printf("  %s -r\nLe résultat : 5.15.0-kali3-amd64",pn);
}

int main(int argc,char**argv) {
   
   struct utsname info;
   
   if (uname(&info) < 0) {
      perror("uname");
      exit(EXIT_FAILURE);
   }
   if (argc > 1){
       switch(argv[1][1]){
           case 'r' : printf("release     : %s\n", info.release); break;
           case 's' : printf("system name : %s\n", info.sysname); break;
           case 'm' : printf("machine     : %s\n", info.machine); break;
           case 'v' : printf("version     : %s\n", info.version); break;
           case 'n' : printf("node name   : %s\n", info.nodename); break;
           case 'V' : version();break;
           case 'h': usage(argv[0]);break;
           default  : printf("Option not available\n");
       }
    }else if(argc ==1) {
          printf("System name: %s\nNodename:%s\nRelease:%s\nVersion:%s\nMachine:%s\n",
       info.sysname, info.nodename, info.release,info.version,info.machine);
   } 
   else {
       print_errors(argv[0]);
   }
   return 0;
}
