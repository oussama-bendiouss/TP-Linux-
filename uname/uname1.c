#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>
//works fine
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
           default  : printf("Option not available\n");
       }
   } else {
       printf("system name : %s\n", info.sysname);
   }
   return 0;
}