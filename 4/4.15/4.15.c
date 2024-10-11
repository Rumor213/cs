#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char * argv[])
{
    if(open("tempfile", O_RDWR | O_CREAT | O_TRUNC, 700) < 0)
      err_sys("open error");
    if(unlink("tempfile") < 0)
      err_sys("unlink error");
    printf("file unlink");

    exit(0);
}