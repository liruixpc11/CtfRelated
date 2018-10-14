#include<stdio.h>

char bin_sh[] = "/bin/sh";

int main() {
    char buffer[0x64];
    setvbuf(stdout, 0, 2, 0);
    puts("RET2LIBC");
    gets(buffer);
    return 0;
}