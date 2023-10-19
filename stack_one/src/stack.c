#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int vuln()
{
    char str[0x10];
    printf("tell me something\n");
    read(0,str,0x20);
    return 0;
}

void menu()
{
    puts("====one====");
    puts("  1.leak");
    puts("  2.vuln");
    puts("  3.exit");
    puts("===========");
}

int main()
{
    setvbuf(stdout, NULL, 2, NULL);
    int opt;
    while(1)
    {
        menu();
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                puts((char *)(0x601018));
                break;
            case 2:
                vuln();
                break;
            case 3:
                exit(0);
        }
    }

    return 0;
}