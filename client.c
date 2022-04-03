#include "minitalk.h"

int main(int argc, char **argv)
{
	if (argc != 3)
		return(printf("Invalid number of arguments"));
		
	kill(atoi(argv[1]), SIGUSR1);
}