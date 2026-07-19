#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before fork, pid = %d\n", getpid());
    
    pid_t pid = fork();          // 创建子进程
    
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        // 子进程执行这里
        printf("I am child, pid = %d, my parent = %d\n", getpid(), getppid());
    }
    else {
        // 父进程执行这里
        printf("I am parent, pid = %d, my child = %d\n", getpid(), pid);
    }
    
    printf("After fork, pid = %d\n", getpid());
    return 0;
}
