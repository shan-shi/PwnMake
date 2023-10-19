#include <stdio.h>
#include <unistd.h>
#include <string.h>

void backdoor()
{
    char str[] = "good job!\nyou hacked me!\n";
    for (int i = 0; i < strlen(str); i++)
    {
        usleep(150000);
        printf("%c", str[i]);
    }
    system("/bin/sh");
}

void vuln()
{
    char str[0x10];
    printf("tell me something\n");
    gets(str);
}

int main()
{
    setvbuf(stdout, NULL, 2, NULL);

    vuln();

    return 0;
}