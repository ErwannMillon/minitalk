/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:06:18 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/04 17:57:57 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_bit(char *c, int n)
{
	*c |= (char)1 << n;
}

void	clear_bit(char *c, int n)
{
	*c &= ~((char)1 << n);
}

int		check_bit(char *c, int n)
{
	int	x;
	x = (*c >> n) & 1U;
	return (x);
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