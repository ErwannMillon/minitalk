/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:06:00 by gmillon           #+#    #+#             */
/*   Updated: 2022/04/05 22:42:43 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "libft.h"
# define BUFSIZE 8
char	*base_convert(long int dec, char *str);
char	*str_to_bin(char *str);
int		check_bit(int *c, int n);
void	clear_bit(int *c, int n);
void	set_bit(int *c, int n);
#endif