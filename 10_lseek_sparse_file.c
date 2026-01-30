/* Program Number: 10
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program writes data to a file, moves
   the file offset using lseek(), and writes again.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {

    int fd;
    off_t offset;
    char buf1[] = "ABCDEFGHIJ";   /* 10 bytes */
    char buf2[] = "1234567890";   /* 10 bytes */

    fd = open("seekfile.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    write(fd, buf1, 10);

    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t)-1) {
        perror("lseek failed");
        close(fd);
        return 1;
    }

    printf("Current file offset after lseek: %ld\n", offset);

    write(fd, buf2, 10);

    close(fd);
    return 0;
}
