/* Program Number: 1
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program creates a regular file, a soft link,
   a hard link, and a FIFO using file-related system calls.
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {

    /* create regular file */
    int fd = creat("original.txt", 0666);
    if (fd == -1) {
        perror("creat failed");
        return 1;
    }
    close(fd);

    /* create soft link */
    if (symlink("original.txt", "softlink.txt") == -1) {
        perror("symlink failed");
    }

    /* create hard link */
    if (link("original.txt", "hardlink.txt") == -1) {
        perror("link failed");
    }

    /* create FIFO */
    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo failed");
    }

    return 0;
}
