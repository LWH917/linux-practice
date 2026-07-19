#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buf[1024];
    int n;
    int fd = open("hello.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    while ((n = read(fd, buf, sizeof(buf))) > 0) {
        write(1, buf, n);
    }
    close(fd);
    return 0;
}
