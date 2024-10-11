#include "apue.h"
#include <fcntl.h>
#include <sys/stat.h>
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char * argv[])
{
   struct stat statbuf;
   struct timespec times[2];
   int fd;

   for(int i = 1; i < argc; i++)
   {
    if(stat(argv[i], &statbuf) < 0){
      err_ret("%s:stat eror", argv[i]);
    }
    if((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0)
      err_ret("%s:open error", argv[i]);
    
   times[0].tv_sec = statbuf.st_atime;
   times[0].tv_nsec = statbuf.st_atime;
   times[1].tv_sec = statbuf.st_atime;
   times[1].tv_nsec = statbuf.st_mtimensec;
   if(utimes("./1.txt", times) < 0)
     err_ret("%s:futimes error", argv[i]);
   close(fd);
   }
   exit(0);
}