/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:05:53 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/06 18:32:43 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*buf_alloc(char *old)
{
	char		*new;
	static int	size = 1005;

	if (!old)
	{
		size = 1005;
		old = malloc(1005);
		return (old);
	}
	size += 1005;
	new = malloc(size);
	ft_memcpy(new, old, size - 4);
	free(old);
	return (new);
}

void	receive_char(int signum, siginfo_t *info, void *ucontext)
{
	static int	counter = 0;
	static int	i = 7;
	static int	c = 0;
	static char	*str = NULL;

	if (!str)
		str = malloc(1000);
	if (signum == SIGUSR1)
	{
		set_bit(&c, i);
	}
	i--;
	if (c == 255)
	{
		i = 7;
		c = 0;
		kill(info->si_pid, SIGUSR2);
		str[counter] = 0;
		write(1, str, counter);
		counter = 0;
		free(str);
		str = NULL;
	}
	if (i == -1 && c != 255)
	{
		str[counter] = c;
		counter++;
		if (c != 0 && c % 800 == 0)
			str = buf_alloc(str);
		i = 7;
		c = 0;
		usleep(1000);
		kill(info->si_pid, SIGUSR1);
	}
	usleep(1000);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int						i;
	struct sigaction		newaction;
	long long unsigned int	pid;

	i = 0;
	newaction.sa_flags = SA_SIGINFO;
	newaction.sa_sigaction = &receive_char;
	sigaction(SIGUSR1, &newaction, NULL);
	sigaction(SIGUSR2, &newaction, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	printf("\n");
	while (1)
	{
		i = 0;
	}
}
