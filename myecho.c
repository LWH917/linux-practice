#include <unistd.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        if (i > 1) write(1, " ", 1);     // 单词之间加空格
        int len = 0;
        while (argv[i][len]) len++;       // 计算字符串长度
        write(1, argv[i], len);           // 输出单词
    }
    write(1, "\n", 1);                    // 换行
    return 0;
}
