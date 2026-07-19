#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf[1024];
    int n, fd_src, fd_dst;
    
    if (argc < 3) {
        printf("Usage: %s <src> <dst>\n", argv[0]);
        return 1;
    }
    
    // 打开源文件（只读）
    fd_src = open(argv[1], O_RDONLY);
    if (fd_src < 0) {
        perror("open src");
        return 1;
    }
    
    // 创建目标文件（只写，如果不存在则创建，权限644）
    fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dst < 0) {
        perror("open dst");
        return 1;
    }
    
    // 读取源文件，写入目标文件
    while ((n = read(fd_src, buf, sizeof(buf))) > 0) {
        write(fd_dst, buf, n);
    }
    
    close(fd_src);
    close(fd_dst);
    printf("Copy done!\n");
    return 0;
}
