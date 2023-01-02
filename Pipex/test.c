#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *args[] = {"ls", "-l", NULL};
    char *env[] = {NULL};

    execve("/bin/ls", args, env);

    printf("Ce message ne sera jamais affiché\n");

    return 0;
}
