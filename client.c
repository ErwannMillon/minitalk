/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:06:15 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/06 20:38:38 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_str(int x)
{
	(void)x;
}

void	message_received(int x)
{
	ft_putstr_fd("Message sent successfully!", 1);
}

int	transmit_char(int c, int serverpid)
{
	int					i;
	struct sigaction	newaction;

	i = 7;
	newaction.sa_handler = &receive_str;
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, &message_received);
	while (i >= 0)
	{
		if (check_bit(&c, i))
		{
			kill(serverpid, SIGUSR1);
			write(1, "1", 1);
		}
		else
		{
			kill(serverpid, SIGUSR2);
			write(1, "0", 1);
		}
		i--;
		usleep(WAIT_TIME);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char				*transmitstr;
	int					i;
	int					serverpid;
	struct sigaction	newaction;

	newaction.sa_handler = &receive_str;
	sigaction(SIGUSR1, &newaction, NULL);
	signal(SIGUSR2, &message_received);
	i = 0;
	if (argc != 3)
		return (write(1, "Invalid number of arguments", 27));
	transmitstr = argv[1];
	serverpid = atoi(argv[2]);
	while (transmitstr[i])
	{
		transmit_char(transmitstr[i], serverpid);
		// pause();
		i++;
	}
	usleep(WAIT_TIME);
	transmit_char(255, serverpid);
}
