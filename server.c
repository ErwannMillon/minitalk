/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:05:53 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/03 23:33:03 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
char *g_str;

char	*buf_alloc(char *old)
{
	char		*new;
	static int	size = 1;
	int			i;

	i = 0;
	size += 1;
	new = malloc(size + 1);
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

void receive_char(int signum)
{
	static int	counter = 0;
	static int	i = 7;

	if (counter % 6)
	{
		g_str = buf_alloc(g_str);
	}
	if (signum == SIGUSR1)
	{
		write(1, "1", 1);
	}

	if (signum == SIGUSR2)
	{
		write(1, "0", 1);
	}
	counter++;
}
int	receive_str()
{

	pause();
}

int main(void)
{
	g_str = malloc(2);
	sigset_t	set;
	struct sigaction newaction;
	newaction.sa_handler = &receive_char;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigaction(SIGUSR1, &newaction, NULL);
	sigaction(SIGUSR2, &newaction, NULL);
	printf("%d\n", getpid());
	while (1)
		receive_str();	
}