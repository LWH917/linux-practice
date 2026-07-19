#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("Breore exec,pid = %d\n",getpid());
		execlp("ls","ls","-l",NULL);
		printf("After ,pid = %d\n",getpid());
		return 0;
	
}
