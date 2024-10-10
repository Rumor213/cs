#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char * argv[])
{
    umask(0);
    if(creat("foo", RWRWRW) < 0)
      err_sys("creat error");
    umask(066);
    if(creat("bar", RWRWRW) < 0)
      err_sys("creat error");
    exit(0);
}