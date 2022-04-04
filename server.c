/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:05:53 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/04 02:51:33 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
char *g_str;

char	*buf_alloc(char *old)
{
	char		*new;
	static int	size = 10;
	int			i;

	i = 0;
	size += 1;
	new = malloc(size + 2);
	if (!new)
		return (NULL);
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i] = 0;
	free(old);
	return (new);
}

void receive_char(int signum, siginfo_t *info, void *ucontext)
{
	static int	counter = 0;
	static int	i = 7;
	static unsigned char c = 0;
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
	i--;
	if (i == -1)
	{
		ft_putchar_fd(c, 1);
		i = 7;
		c = 0;
	}
	if (c == 255)
	{
		// g_str[counter] = 0;
		// write(1, g_str, counter);
		// free(g_str);
		// g_str = malloc(10);
		// g_str[0] = 0;
		i = 7;
		// counter = 0;
		c = 0;
	}
	if (i == -1 && c != 255)
	{
		// write(1, "CHAR RECEIVED\n", 15);
		// write(1, &c, 1);
		// g_str[counter] = c;
		// counter++;
		// g_str[counter] = 0;
		// g_str = buf_alloc(g_str);
		i = 7;
		c = 0;
	}
	// if (counter >= 2)
	// 	printf("STRING: %s\n", g_str);
}
int	receive_str()
{

	pause();
}

int main(void)
{
	g_str = malloc(10);
	g_str[0] = 0;
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
	while (1)
	{
		i = 0;
	}
}