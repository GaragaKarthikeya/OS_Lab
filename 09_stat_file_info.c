/* Program Number: 9
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program prints detailed information
   about a file using the stat() system call.
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {

    struct stat st;

    if (argc != 2) {
        write(2,
              "Usage: ./9 <filename>\n",
              sizeof("Usage: ./9 <filename>\n") - 1);
        return 1;
    }

    if (stat(argv[1], &st) == -1) {
        perror("stat failed");
        return 1;
    }

    printf("Inode number        : %ld\n", st.st_ino);
    printf("Hard links          : %ld\n", st.st_nlink);
    printf("User ID             : %d\n", st.st_uid);
    printf("Group ID            : %d\n", st.st_gid);
    printf("File size           : %ld bytes\n", st.st_size);
    printf("Block size          : %ld bytes\n", st.st_blksize);
    printf("Number of blocks    : %ld\n", st.st_blocks);

    printf("Last access time    : %s", ctime(&st.st_atime));
    printf("Last modification   : %s", ctime(&st.st_mtime));
    printf("Last status change  : %s", ctime(&st.st_ctime));

    return 0;
}
