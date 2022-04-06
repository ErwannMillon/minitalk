/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:06:18 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/06 20:54:06 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_bit(int *c, int n)
{
	*c |= 1 << n;
}

void	clear_bit(int *c, int n)
{
	*c &= ~(1 << n);
}

int	check_bit(int *c, int n)
{
	int	x;

	x = (*c >> n) & 1U;
	return (x);
}
