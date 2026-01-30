/* Program Number: 3
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program creates a file using the creat()
   system call and prints the file descriptor value.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    int fd = creat("created_file.txt", 0666);

    if (fd == -1) {
        perror("creat failed");
        return 1;
    }

    printf("File created successfully\n");
    printf("File Descriptor: %d\n", fd);

    close(fd);
    return 0;
}
