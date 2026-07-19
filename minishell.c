#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char cmd[100];
    
    while (1) {
        printf("myshell> ");
        scanf("%s", cmd);
        
        if (cmd[0] == 'q') break;   // 输入 q 退出
        
        pid_t pid = fork();
        
        if (pid == 0) {
            // 子进程执行命令
            execlp(cmd, cmd, NULL);
            perror("exec");          // 如果 exec 失败
            return 1;
        }
        else {
            // 父进程等待子进程结束
            wait(NULL);
        }
    }
    
    printf("Bye!\n");
    return 0;
}
