#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void print_errors(char *f1,char *f2){
     fprintf(stderr, "Non mon petit, tu peux pas copier le %s au %s à cause de :\n%s\n",f1,f2,strerror(errno)); 
     exit(EXIT_FAILURE);
}
void print_usage(char *this){
     fprintf(stderr, "Erreur de synthaxe: Tu sais pas utilisé la fonction %s, mais t'es nul\n\n\nVoici la bonne synthaxe:\n%s [Ancien_version] [nouvelle version]",this);
     exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    errno = 0;
    if(argc ==3){
       if(rename(argv[1], argv[2]) == -1){
          print_errors(argv[1], argv[2]);
}
       else {
           rename(argv[1], argv[2]);
}
} 
    else {
          print_usage(argv[0]);
}
return 0;
}
