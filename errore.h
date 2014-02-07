#include <errno.h>

void errore(char*str,int n)
{
    printf(str);
    printf("%s(%d)\n",strerror(errno),errno);
    exit(n);
}
