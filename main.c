#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


/*int main() {

    char *s = "bro i might fuck your shit up if you even get close to me!!!";
    int len = strlen(s);
    int fd = open("README.md", O_RDWR);
    
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    write(fd, s, len);
    close(fd);
    return 0;
}*/

/*int main(){

    char buff[100];
    int fd;
    fd = open("README.md", O_RDONLY);
    read(fd, buff, 100);
    write(1, buff, 100);
    return 0;
}*/
