/* Program Number: 7
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program copies the contents of one file
   into another using file-related system calls.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    int fd_src, fd_dst;
    char buffer[1024];
    int bytes_read;

    if (argc != 3) {
        write(2, "Usage: ./7 <source> <destination>\n", 36);
        return 1;
    }

    fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1) {
        perror("open source failed");
        return 1;
    }

    fd_dst = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd_dst == -1) {
        perror("open destination failed");
        close(fd_src);
        return 1;
    }

    while ((bytes_read = read(fd_src, buffer, sizeof(buffer))) > 0) {
        write(fd_dst, buffer, bytes_read);
    }

    close(fd_src);
    close(fd_dst);

    return 0;
}
