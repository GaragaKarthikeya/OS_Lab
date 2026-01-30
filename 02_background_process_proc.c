/* Program Number: 2
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program runs indefinitely in the background
   and allows exploration of process information via /proc.
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Background process started\n");
    printf("PID: %d\n", getpid());

    while (1) {
        sleep(10);
    }

    return 0;
}
