/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:06:15 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/04 18:15:58 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int transmit_char(char c, int serverpid)
{
	int	i;
	i = 7;

	while (i >=0 )
	{
		if (check_bit(&c, i))
		{
			ft_putnbr_fd(check_bit(&c, i), 1);
			kill(serverpid, SIGUSR1);
		}
		else
		{
			ft_putnbr_fd(check_bit(&c, i), 1);
			kill(serverpid, SIGUSR2);
		}
		i--;
		usleep(100);
	}
	write(1, "\n", 1);
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
	// while (i <= 254)
	// {
	// 	transmit_char(i, serverpid);
	// 	usleep(1000);
	// 	i++;
	// }
	transmit_char(0, serverpid);
	transmit_char(0, serverpid);
}