#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf[1024];
    int n, fd;
    if(argc < 2)
    {
	    printf("Usage: %s <file>\n",argv[0]);
	    return 1;
    }
    fd = open(argv[1],O_RDONLY);
    if(fd < 0)
    {
	    perror("open");
	    return 1;
    }
    while((n = read(fd,buf,sizeof(buf)))>0)
    {
	    write(1,buf,n);
    }
    close(fd);
    return 0;
}

