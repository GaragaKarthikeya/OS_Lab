/* Program Number: 15
   Student Name: Karthikeya Garaga; Register Number: IMT2024073
   Date: 30-01-2026
   Description: This program displays all user
   environment variables using the environ variable.
*/

#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main() {

    char **env = environ;

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
