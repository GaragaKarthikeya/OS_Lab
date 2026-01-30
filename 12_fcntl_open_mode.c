/* Program Number: 12
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program determines the opening
   mode of a file using the fcntl() system call.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    int fd;
    int flags;

    fd = open("modefile.txt", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl failed");
        close(fd);
        return 1;
    }

    switch (flags & O_ACCMODE) {
        case O_RDONLY:
            printf("File opened in READ ONLY mode\n");
            break;
        case O_WRONLY:
            printf("File opened in WRITE ONLY mode\n");
            break;
        case O_RDWR:
            printf("File opened in READ-WRITE mode\n");
            break;
        default:
            printf("Unknown access mode\n");
    }

    close(fd);
    return 0;
}
