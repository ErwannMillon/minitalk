/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:06:15 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/05 23:35:03 by gmillon          ###   ########.fr       */
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

int transmit_char(int c, int serverpid)
{
	int	i;
	int a = 0;
	i = 7;

	struct sigaction newaction;
	
	newaction.sa_handler = &receive_str;
	sigaction(SIGUSR1, &newaction, NULL);
	signal(SIGUSR2, &message_received);
	while (i >=0)
	{
		if (check_bit(&c, i))
		{
			printf("%d", check_bit(&c, i));
			kill(serverpid, SIGUSR1);
			// set_bit(&a, i);
		}
		else
		{
			printf("%d", check_bit(&c, i));
			kill(serverpid, SIGUSR2);
		}
		i--;
		pause();
	}
	// printf("\n");
	return (1);
}

int main(int argc, char **argv)
{
	char	*transmitstr;
	int		i;
	int		serverpid;

	
	struct sigaction newaction;

	newaction.sa_handler = &receive_str;
	sigaction(SIGUSR1, &newaction, NULL);
	signal(SIGUSR2, &message_received);


	i = 0;
	if (argc != 3)
		return(printf("Invalid number of arguments"));
	transmitstr = argv[1];
	serverpid = atoi(argv[2]);
	while (transmitstr[i])
	{
		transmit_char(transmitstr[i], serverpid);
		pause();
		i++;
	}
	transmit_char(255, serverpid);
}