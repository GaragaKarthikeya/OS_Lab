/* Program Number: 13
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program waits for input from STDIN
   for 10 seconds using the select() system call.
*/

#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    fd_set readfds;
    struct timeval tv;
    char buffer[100];
    int retval;

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);   /* STDIN */

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    retval = select(1, &readfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select failed");
    } else if (retval == 0) {
        printf("No input received within 10 seconds\n");
    } else {
        if (FD_ISSET(0, &readfds)) {
            int n = read(0, buffer, sizeof(buffer));
            write(1, "Input received: ", 16);
            write(1, buffer, n);
        }
    }

    return 0;
}
