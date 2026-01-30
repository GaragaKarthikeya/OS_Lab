/* Program Number: 5
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program continuously creates five files
   in an infinite loop and keeps them open to observe file
   descriptors via /proc.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    int fd[5];
    int i;
    int count = 0;
    char filename[20];

    while (1) {
        for (i = 0; i < 5; i++) {
            snprintf(filename, sizeof(filename), "file_%d_%d.txt", count, i);
            fd[i] = open(filename, O_CREAT | O_RDWR, 0666);

            if (fd[i] == -1) {
                perror("open failed");
            }
        }

        count++;
        sleep(10);
    }

    return 0;
}
