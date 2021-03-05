#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_info
{
	int		zero;
	int		minus;
	int		width;
	int		precis;
	char	type;
	int		nbr_base;
}				t_info;

int			ft_printf(const char *string, ...);

#endif