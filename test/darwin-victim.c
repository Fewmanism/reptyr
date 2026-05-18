#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    char *line = NULL;
    size_t cap = 0;

    setvbuf(stdout, NULL, _IONBF, 0);

    for (;;) {
        errno = 0;
        if (getline(&line, &cap, stdin) != -1) {
            printf("ECHO: %s", line);
            continue;
        }
        clearerr(stdin);
        usleep(10000);
    }
}
