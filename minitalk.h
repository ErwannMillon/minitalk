#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "libft.h"
char	*base_convert(long int dec, char *str);
char	*str_to_bin(char *str);
int		check_bit(char *c, int n);
void	clear_bit(char *c, int n);
void	set_bit(char *c, int n);
#endif