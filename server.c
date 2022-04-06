/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:05:53 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/06 20:57:43 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_char(int signum, siginfo_t *info, void *ucontext)
{
	static int	i = 7;
	static int	c = 0;

	if (signum == SIGUSR1)
		set_bit(&c, i);
	i--;
	if (i == -1 && c != 255)
	{
		ft_putchar_fd(c, 1);
		i = 7;
		c = 0;
	}
	if (c == 255)
	{
		i = 7;
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction		newaction;
	long long unsigned int	pid;

	newaction.sa_flags = SA_SIGINFO;
	newaction.sa_sigaction = &receive_char;
	sigaction(SIGUSR1, &newaction, NULL);
	sigaction(SIGUSR2, &newaction, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		pause();
	}
}
