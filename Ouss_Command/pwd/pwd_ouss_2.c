#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
void version(){
  puts("TP : Programmation Linux Windows, CentraleSupélec, 2022 \u00A9\npwd program : basic functionnality works fine with some few features");
  exit(EXIT_FAILURE);

}

void usage(char* pn){
  printf("Utilisation : %s ",pn);
  printf("Tu peux utiliser cette fonction pour afficher le directory de travail actuel.\n\n");
 
       printf("   -V  Afficher des informations sur la version du %s\n",pn);
  printf("   -h  Afficher de l'aide \n\n");
  printf("Examples\n");
  printf("  %s \nLe résultat : /home/kali/Desktop",pn);
}

int main(int argc, char** argv)
{ if(argc==1){
  char wd[1000];
  printf("Le dossier de travail actuel est: %s", getcwd(wd,sizeof(wd)));}
  else if(argc ==2){
  switch(argv[1][1]){
       case 'h': usage(argv[0]);break;
        case 'V' : version();break;

  }
  }
  else {
  printf("Moins d'arguments s'il te plait");}
  return 0;
}
