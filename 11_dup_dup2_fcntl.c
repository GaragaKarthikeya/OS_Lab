/* Program Number: 11
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program demonstrates file descriptor
   duplication using dup, dup2, and fcntl.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    int fd, fd_dup, fd_dup2, fd_fcntl;

    fd = open("dupfile.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    fd_dup = dup(fd);
    fd_dup2 = dup2(fd, 10);
    fd_fcntl = fcntl(fd, F_DUPFD, 20);

    write(fd,      "Written using fd\n", 17);
    write(fd_dup,  "Written using dup\n", 18);
    write(fd_dup2, "Written using dup2\n", 19);
    write(fd_fcntl,"Written using fcntl\n", 20);

    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    return 0;
}
