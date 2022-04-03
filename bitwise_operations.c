#include "minitalk.h"


void	set_bit(char *c, int n)
{
	*c |= 1 << n;
}

void	clear_bit(char *c, int n)
{
	*c &= ~(1 << n);
}

int		check_bit(char *c, int n)
{
	int	x;
	x = (*c >> n) & 1U;	
}


// int transmit_char(char c, int serverpid)
// {
// 	int	i;

// 	i = 7;

// 	while (i >= 0)
// 	{
// 		if (check_bit(&c, i))
// 		{
// 			printf("%d\n", check_bit(&c, i));
// 			// kill(serverpid, SIGUSR1);
// 		}
// 		else
// 		{
			
// 			printf("%d\n", check_bit(&c, i));
// 			// kill(serverpid, SIGUSR2);
// 		}
// 		i--;
// 	}
// }

// int main(void)
// {
// 	char *transmitstr = "abc";
// 	int i = 0;
// 	while (transmitstr[i])
// 	{
// 		transmit_char(transmitstr[i], 0);
// 		i++;
// 	}

// }