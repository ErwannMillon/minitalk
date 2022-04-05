/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:06:15 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/04 02:36:21 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int transmit_char(char c, int serverpid)
{
	int	i;
	char a = 0;
	i = 7;

	while (i >=0 )
	{
		if (check_bit(&c, i))
		{
			// printf("%d", check_bit(&c, i));
			kill(serverpid, SIGUSR1);
			// set_bit(&a, i);
		}
		else
		{
			// printf("%d", check_bit(&c, i));
			kill(serverpid, SIGUSR2);
		}
		i--;
		usleep(100);
	}
	return (1);
}

int main(int argc, char **argv)
{
	char	*transmitstr;
	int		i;
	int		serverpid;

	i = 0;
	if (argc != 3)
		return(printf("Invalid number of arguments"));
	transmitstr = argv[1];
	serverpid = atoi(argv[2]);
	while (transmitstr[i])
	{
		transmit_char(transmitstr[i], serverpid);
		usleep(1000);
		i++;
	}
	transmit_char(255, serverpid);
}