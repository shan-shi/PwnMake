#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    setvbuf(stdout, NULL, 2, NULL);

    char str[] = "good job!\nyou hacked me!\n";
    for (int i = 0; i < strlen(str); i++)
    {
        usleep(150000);
        printf("%c", str[i]);
    }
    system("/bin/sh");
    return 0;
}