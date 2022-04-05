/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:05:53 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/05 23:17:48 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



void receive_char(int signum, siginfo_t *info, void *ucontext)
{
	static int	counter = 0;
	static int	i = 7;
	static int c = 0;
	// write(1, "Signal number\n", 15);
	// ft_putnbr_fd(info->si_signo, 1);
	if (signum == SIGUSR1)
	{
		set_bit(&c, i);
		// write(1, "1", 1);
	}
	if (signum == SIGUSR2)
	{
		// write(1, "0", 1);
	}
	// ft_putstr_fd("i:   ", 1);
	// ft_putnbr_fd(i, 1);
	// ft_putstr_fd("\n", 1);
	i--;
	if (i == -1 && c != 255)
	{
		ft_putchar_fd(c, 1);
		i = 7;
		c = 0;
		usleep(1000);
		kill(info->si_pid, SIGUSR1);
	}
	if (c == 255)
	{
		i = 7;
		c = 0;
		kill(info->si_pid, SIGUSR2);

	}
	// if (counter >= 2)
	// 	printf("STRING: %s\n", g_str);
	usleep(1000);
	kill(info->si_pid, SIGUSR1);

}


int main(void)
{
	int i = 0;
	sigset_t	set;
	struct sigaction newaction;
	newaction.sa_flags = SA_SIGINFO;
	newaction.sa_sigaction = &receive_char;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigaction(SIGUSR1, &newaction, NULL);
	sigaction(SIGUSR2, &newaction, NULL);
	long long unsigned int pid = getpid();
	ft_putnbr_fd(pid, 1);
	printf("\n");
	while (1)
	{
		i = 0;
	}
}