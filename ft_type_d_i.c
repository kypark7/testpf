/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:18:07 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:18:20 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int				ft_type_d_i_dot(int n, int neg)
{
	int	i;
	int	j;
	int	size;
	int dot;

	i = -1;
	j = -1;
	i += neg;
	//큰거 선택 %5.3d 이면 3
	size = g_plist.prec[1] < ft_ten_size(n) ? ft_ten_size(n) : g_plist.prec[1];
	//!n !g_plist.pre[1]
	dot = !n && !g_plist.prec[1] ? 1 : 0;
	//'0'||* digit
	if (g_plist.flags[0] == 2 || g_plist.flags[0] == 4)
		while (-dot + ++i < g_plist.prec[0] - size)
			write(1, " ", 1);
	if (neg)
		write(1, "-", 1);
	//.
	else if (g_plist.flags[0] == 3)
		while (-dot + ++i < g_plist.prec[0] - size)
			write(1, "0", 1);
	while (++j < size - ft_ten_size(n))
		write(1, "0", 1);
	dot ? size-- : ft_putnbr_ui(n);
	//-
	if (g_plist.flags[0] == 1)
		while (++i < g_plist.prec[0] - size)
			write(1, " ", 1);
	return (size + i);
}

static int		ft_flags_before(int neg, int i, int size, int dot)
{
	//* digit
	if (g_plist.flags[0] == 4)
		while (-dot + i++ < g_plist.prec[0] - size - neg)
			write(1, " ", 1);
	if (neg)
		write(1, "-", 1);
	//'0'
	if (g_plist.flags[0] == 2)
		while (-dot + i++ < g_plist.prec[0] - size - neg)
			write(1, "0", 1);
	// .
	else if (g_plist.flags[0] == 3)
	{
		if (neg)
			while (i++ < g_plist.prec[0] - size + 1 - neg)
				write(1, "0", 1);
		else
			while (-dot + i++ < g_plist.prec[0] - size - neg)
				write(1, "0", 1);
	}
	return (i);
}

int				ft_type_d_i(int n, int neg)
{
	int				i;
	int				dot;
	unsigned int	nbr;
	int				size;

	i = 0;
	//음수일 경우
	if (n < 0)
	{
		nbr = -n;
		neg = 1;
	}
	else
		nbr = n;
	//자릿수
	size = ft_ten_size(nbr);
	//두번째 플래그
	if (g_plist.flags[1])
		return (ft_type_d_i_dot(nbr, neg));
	// . && !nbr && !g_plist.prec[0]
	dot = g_plist.flags[0] == 3 && !nbr && !g_plist.prec[0] ? 1 : 0;
	// 그전 플래그
	i = ft_flags_before(neg, i, size, dot);
	// putnub
	dot ? size-- : ft_putnbr_ui(nbr);
	//뒤에 
	if (g_plist.flags[0] == 1)
		while (-dot + i++ < g_plist.prec[0] - size - neg)
			write(1, " ", 1);
	return (i ? size + i - 1 + neg : size + neg);
}
