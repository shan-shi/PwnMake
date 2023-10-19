#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>

char *addr;

int main()
{
    // setvbuf(stdout, NULL, 2, NULL);
    setvbuf(stdin, NULL, 2, NULL);

    char buf[0x10];

    addr = mmap(0x196082000, 0x10000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    read(0, addr, 0x500);
    read(0, buf, 0x100);

    return 0;
}