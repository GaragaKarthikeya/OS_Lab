/* Program Number: 14
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program identifies the type of a file
   using the stat() system call.
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    struct stat st;

    if (argc != 2) {
        write(2,
              "Usage: ./14 <filename>\n",
              sizeof("Usage: ./14 <filename>\n") - 1);
        return 1;
    }

    if (lstat(argv[1], &st) == -1) {
        perror("stat failed");
        return 1;
    }

    if (S_ISREG(st.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(st.st_mode))
        printf("Symbolic link\n");
    else if (S_ISFIFO(st.st_mode))
        printf("FIFO\n");
    else if (S_ISCHR(st.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(st.st_mode))
        printf("Block device\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");

    return 0;
}
