#include "minitalk.h"
void receive_char(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "1", 1);
	}

	if (signum == SIGUSR2)
	{
		write(1, "0", 1);
	}
}
int	receive_str()
{
	sigset_t	set;
	struct sigaction newaction;
	newaction.sa_handler = &receive_char;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigaction(SIGUSR1, &newaction, NULL);
	sigaction(SIGUSR2, &newaction, NULL);
	pause();
}

int main(void)
{
	printf("%d\n", getpid());
	receive_str();	
}