/* Program Number: 4
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program opens an existing file in
   read-write mode and demonstrates the use of O_EXCL.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    int fd;

    /* open existing file in read-write mode */
    fd = open("testfile.txt", O_RDWR);
    if (fd == -1) {
        perror("open O_RDWR failed");
    } else {
        printf("File opened successfully with O_RDWR\n");
        close(fd);
    }

    /* attempt exclusive creation */
    fd = open("testfile.txt", O_CREAT | O_EXCL | O_RDWR, 0666);
    if (fd == -1) {
        perror("open with O_EXCL failed");
    } else {
        close(fd);
    }

    return 0;
}
