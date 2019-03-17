#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void
handle_sigbus(int sig)
{
        printf("SIGBUS captured\n");
        exit(1);
}

int
main(void)
{
        char buf[256] = {0};
        int  *p = (int *)&buf[1];

        signal(SIGBUS, handle_sigbus);
        printf("%p\n", buf);
        *p = 0;

        return 0;
}
