/* Program Number: 6
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program reads input from STDIN and
   displays it on STDOUT using read() and write().
*/

#include <unistd.h>

int main() {

    char buffer[100];
    int n;

    n = read(0, buffer, sizeof(buffer));

    if (n > 0) {
        write(1, buffer, n);
    }

    return 0;
}
