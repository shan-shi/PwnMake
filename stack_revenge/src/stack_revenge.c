#include <stdio.h>
#include <unistd.h>
#include <string.h>

void read_n(char *buf, int n)
{
    char a;
    for (int i = 0; i < n; i++)
    {
        read(0, &a, 1);
        if (a == 10)
        {
            break;
        }
        if (a == 0)
        {
            break;
        }
        buf[i] = a;
    }
}

int main()
{
    setvbuf(stdout, NULL, 2, NULL);
    setvbuf(stdin, NULL, 2, NULL);
    char *buf[0x30];
    read_n(buf, 0x190);
    puts(buf);
}