
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
// works fine

void version(){
  puts("TP : Programmation Linux Windows, CentraleSupélec, 2022 \u00A9\nmkdir program : basic functionnality works fine with some few features");
}

void usage(char* pn){
  printf("Usage : %s DIRNAME\n",pn);
  printf("Can be used to create new directories.\n\n");
  printf("   -v  show version\n");
  printf("   -h  display this help and exit\n\n");
  printf("Examples\n");
  printf("  %s new_folder     creates a new folder\n",pn);
}

int main(int argc, char** argv)
{
    int ret = 0;
    
    if (argc == 1){
        printf("please enter the directory name");
    }

    ret = mkdir(argv[1], 0755);

    if (ret == 0)
        printf("Directory created successfully\n");
    else
        printf("Unable to create directory %s\n", argv[1]);

    return 0;
}