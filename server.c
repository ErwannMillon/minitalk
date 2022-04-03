#include "minitalk.h"

int main(void)
{
	sigset_t	set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	

	printf("%d\n", getpid());
	pause();
	
}