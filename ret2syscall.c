#include <stdio.h>
#include <stdlib.h>

char bin_sh[] = "/bin/sh";

void empty_system() {
    system("/bin/ls");
}

int main() {
    char buffer[0x64];

    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 1, 0);
    puts("no system and shellcode for you this time!!");
    gets(buffer);
    return 0;
}
