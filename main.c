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

//this is a test for me to understand how shit works....
//  this program prints out what is in a file no matter how big it is...
/*int main(int argc, char **argv)
{
    int fd;
    char file[67];  //<----this buffer can be any size, and it will still work.
    ssize_t count;
    int bytes_read;

    if (argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (1);
    bytes_read = 1;
    count = 0;
    while (bytes_read > 0)  // byte_read will be 0 when we are the EOF.
    {
        bytes_read = read(fd, file, sizeof(file));
        if (bytes_read == -1)
        {
            close(fd);
            return (1);            
        }
        if (bytes_read > 0)
        {
            write(1, file, bytes_read);
            count = count + bytes_read;
        }
    }
    close(fd);
    printf("\nthe count is :[%zu]", count);
    return 0;
}*/

int main(int argc, char **argv)  //for testing my final project.....!!
{
    int fd;
    int line_count;
    char *line;

    if (argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (1);
    line_count = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("[%d]: %s", line_count, line);
        free(line);
        line_count++;
    }
    close(fd);
    return (0);
}
