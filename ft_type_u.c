/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:20:25 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:20:38 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int				ft_type_u_dot(int n)
{
	int	i;
	int	j;
	int	size;
	int dot;

	i = -1;
	j = -1;
	size = g_plist.prec[1] < ft_ten_size(n) ? ft_ten_size(n) : g_plist.prec[1];
	dot = !n && !g_plist.prec[1] ? 1 : 0;
	if (g_plist.flags[0] == 2 || g_plist.flags[0] == 4)
		while (-dot + ++i < g_plist.prec[0] - size)
			write(1, " ", 1);
	while (++j < size - ft_ten_size(n))
		write(1, "0", 1);
	dot ? size-- : ft_putnbr_ui(n);
	if (g_plist.flags[0] == 1)
		while (++i < g_plist.prec[0] - size)
			write(1, " ", 1);
	return (size + i);
}

int				ft_type_u(int n)
{
	int				i;
	int				dot;
	int				size;
	unsigned int	nb;

	nb = n < 0 ? UINT_MAX + n + 1 : n;
	size = ft_ten_size(nb);
	i = 0;
	if (g_plist.flags[1])
		return (ft_type_u_dot(nb));
	dot = !n && g_plist.flags[0] == 3 && !g_plist.prec[0] ? 1 : 0;
	if (g_plist.flags[0] == 2 || g_plist.flags[0] == 3)
		while (-dot + i++ < g_plist.prec[0] - size)
			write(1, "0", 1);
	else if (g_plist.flags[0] == 4)
		while (-dot + i++ < g_plist.prec[0] - size)
			write(1, " ", 1);
	dot ? size-- : ft_putnbr_ui(nb);
	if (g_plist.flags[0] == 1)
		while (i++ < g_plist.prec[0] - size)
			write(1, " ", 1);
	return (i ? size + --i : size);
}
