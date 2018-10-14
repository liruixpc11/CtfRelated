#include <stdio.h>
#include <string.h>

char g_buffer[0x64];

int main() {
    char buffer[0x64];

    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 1, 0);
    puts("no system for you this time!!");
    gets(buffer);
    strncpy(g_buffer, buffer, 0x64);
    puts("bye bye ~");
    return 0;
}