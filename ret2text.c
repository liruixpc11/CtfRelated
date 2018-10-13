#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    char buffer[0x60];

    setvbuf(stdout, 0, 2, 0);
    puts("please input some words:");
    gets(buffer);
    printf("input is %s\n", buffer);
    return 0;
}

void secure() {
    unsigned int seed;
    int input;
    int secret_code;

    seed = time(NULL);
    srand(seed);
    secret_code = rand();
    scanf("%d", &input);
    if (input == secret_code) {
        system("/bin/sh");
    }
}