#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
// works fine

void tee(int argc,char **argv){
    char buffer[1024] = {0};
    ssize_t nread = 0;
    while((nread = read(STDIN_FILENO, buffer, 1024)) != 0) {
        if (write(STDOUT_FILENO, buffer, nread) != nread) {
            fprintf(stderr, "%s\n", "Failed to write to stdout");
        }
        for (int i = 1; i < argc; i++){
            int outfd = open(argv[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
            if (outfd == -1) {
              fprintf(stderr, "%s\n", "Failed to create output file");
            }
            if (write(outfd, buffer, nread) != nread) {
            fprintf(stderr, "%s\n", "Failed to write to file");
        }
        }
    };

}
int main(int argc, char* argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "%s\n", "Output file name required");
        return 1;
    }
    
    tee(argc,argv);
    
    return 0;
}
