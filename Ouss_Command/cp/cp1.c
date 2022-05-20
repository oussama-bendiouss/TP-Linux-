#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 32
#define FILE_NAME_LEN 200

void usage(char *pn){
  printf("Usage : %s [OPTION] [SRC_FILE] [DEST_FILE]\n",pn);
  printf("Can be used to copy from a source file to a dest file.\n\n");
  printf("   -v  show version\n");
  printf("   -n  number all output lines\n");
  printf("   -h  display this help and exit\n\n");
  printf("Examples\n");
  printf("  %s -n file     Output file content and number output lines\n",pn);
}

//works fine
int main(int argc, char *argv[]) {
  FILE *file_to_read;
  FILE *file_to_write;
  char name_of_file_to_read[FILE_NAME_LEN + 1];
  char name_of_file_to_write[FILE_NAME_LEN + 1];
  char buf[BUF_SIZE];
  size_t num_rec;
  if (argc != 3) {
    printf("Please Provide two arugments \n");
  } else {
    if (access(argv[1], F_OK) < 0) {
      printf("%s not found \n ", argv[1]);
    }
    strcpy(name_of_file_to_read, argv[1]);
    strcpy(name_of_file_to_write, argv[2]);
    if ((file_to_read = fopen(name_of_file_to_read, "r")) == NULL) {
      fprintf(stderr, "Could not open file '%s' for reading\n",
              name_of_file_to_read);
      return 3;
    }
    if ((file_to_write = fopen(name_of_file_to_write, "w")) == NULL) {
      fprintf(stderr, "Could not open file '%s' for writing\n",
              name_of_file_to_write);
      fclose(file_to_read);
      return 4;
    }
    while ((num_rec = fread(buf, sizeof(char), BUF_SIZE, file_to_read)) > 0) {
      fwrite(buf, sizeof(char), num_rec, file_to_write);
      if (ferror(file_to_write)) {
        fprintf(stderr, "Error while writing into file '%s'\n",
                name_of_file_to_write);
        fclose(file_to_read);
        fclose(file_to_write);
        return 5;
      }
    }
    if (ferror(file_to_read)) {
      fprintf(stderr, "Error while reading the file '%s'\n",
              name_of_file_to_read);
      fclose(file_to_read);
      fclose(file_to_write);
      return 6;
    }
    fclose(file_to_read);
    fclose(file_to_write);
    printf("File '%s' successfully copied to file '%s'\n", name_of_file_to_read,
           name_of_file_to_write);
    return 1;
  }
}