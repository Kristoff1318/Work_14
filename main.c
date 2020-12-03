#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char * args[5];

char ** parse_args( char * line ) {
    int i = 0;
    char *p = line;
    while(p) {
        args[i] = strsep(&p, " ");
        i++;
    }
    return args;
}

int main() {
    char c[] = "ls -a -l";
    char **args = parse_args(c);
    execvp(args[0], args);

    return 0;
}
