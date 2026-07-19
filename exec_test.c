#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before exec, pid = %d\n", getpid());
    
    // 把自己变成 ls 命令
    execlp("ls", "ls", "-l", NULL);
    
    printf("After exec, pid = %d\n", getpid());  // 这行不会执行！
    return 0;
}
