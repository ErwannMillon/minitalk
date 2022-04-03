#include "minitalk.h"

int transmit_char(char c, int serverpid)
{
	int	i;

	i = 7;

	while (i >=0 )
	{
		if (check_bit(&c, i))
		{
			// printf("%d", check_bit(&c, i));
			kill(serverpid, SIGUSR1);
		}
		else
		{
			
			// printf("%d", check_bit(&c, i));
			kill(serverpid, SIGUSR2);
		}
		i--;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	char	*transmitstr;
	int		i;
	int		serverpid;

	i = 0;
	if (argc != 3)
		return(printf("Invalid number of arguments"));
	transmitstr = argv[2];
	serverpid = atoi(argv[1]);
	while (transmitstr[i])
	{
		transmit_char(transmitstr[i], serverpid);
		i++;
	}
}