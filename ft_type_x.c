/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:20:55 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:21:06 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int			ft_flags_before(int size, int i, int dot)
{
	//첫번째 플래그'0'
	if (g_plist.flags[0] == 2)
		while (-dot + i++ < g_plist.prec[0] - size)
		{
			//앞 공백
			if (g_plist.flags[1])
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
	//첫번째 플래그'0' = .
	else if (g_plist.flags[0] == 3)
		while (-dot + i++ < g_plist.prec[0] - size)
			write(1, "0", 1);
	//첫번째 플래그 * digit
	else if (g_plist.flags[0] == 4)
		while (-dot + i++ < g_plist.prec[0] - size)
			write(1, " ", 1);
	return (i);
}

int			ft_type_x_dot(unsigned int n, char *base, char *res)
{
	int		size;
	int		x_i;
	int		dot;
	int		i;
	int		j;

	i = 0;
	j = 0;
	//큰거
	size = g_plist.prec[1] < ft_hex_size(n) ? ft_hex_size(n) : g_plist.prec[1];
	x_i = ft_hex_size(n);
	dot = !n && !g_plist.prec[1] ? 1 : 0;
	i = ft_flags_before(size, i, dot);
	while (j++ < size - x_i)
		write(1, "0", 1);
	//res hex 저장
	while (x_i--)
	{
		res[x_i] = base[n % 16];
		n /= 16;
	}
	//!n = true and !g_plist.pre[1] = true
	dot ? size-- : ft_putstr(res);
	free(res);
	//뒤에 ' '
	if (g_plist.flags[0] == 1)
		while (i++ < g_plist.prec[0] - size)
			write(1, " ", 1);
	return (size + --i);
}

int			ft_type_x(unsigned int n, int i, char *base)
{
	char	*res;
	int		size;
	int		x_i;
	int		dot;
	
	size = ft_hex_size(n);
	x_i = size;
	if (!(res = (char *)ft_calloc(sizeof(char), size + 1)))
		return (0)
	//두번째 플래그 존재
	if (g_plist.flags[1])
		return (ft_type_x_dot(n, base, res));
	//!n = true andd 첫번째 플래그 . and 처번째 prec 없 ==> dot
	dot = !n && g_plist.flags[0] == 3 && !g_plist.prec[0] ? 1 : 0;
	i = ft_flags_before(size, i, dot);
	//res에 hex해서 저장
	while (x_i--)
	{
		res[x_i] = base[n % 16];
		n /= 16;
	}
	dot ? size-- : ft_putstr(res);
	free(res);
	//첫번째 플래그 -
	if (g_plist.flags[0] == 1)
		while (i++ < g_plist.prec[0] - size)
			write(1, " ", 1);
	return (i ? size + --i : size);
}
