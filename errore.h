#include <errno.h>

void errore(char *msg, int ret_code)
{
    printf(msg);
    printf("errcode : %d (%s)\n", errno,strerror(errno));
    exit(ret_code);
}
