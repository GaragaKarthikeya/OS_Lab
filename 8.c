/* Program Number: 8
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program opens a file in read-only mode,
   reads it line by line, and displays each line.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    int fd;
    char ch;

    if (argc != 2) {
        write(2,
              "Usage: ./8 <filename>\n",
              sizeof("Usage: ./8 <filename>\n") - 1);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    while (read(fd, &ch, 1) > 0) {
        write(1, &ch, 1);
    }

    close(fd);
    return 0;
}
