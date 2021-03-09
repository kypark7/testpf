/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:19:01 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:19:13 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	ft_flags_before(int size, int dot, int i)
{
	if (g_plist.flags[0] == 4)
		while (i++ < g_plist.prec[0] - size - 2 - dot)
			write(1, " ", 1);
	ft_putstr("0x");
	if (g_plist.flags[0] == 2 && !g_plist.flags[1])
		while (i++ < g_plist.prec[0] - size - 2 - dot)
			write(1, "0", 1);
	else if (g_plist.flags[0] == 3)
		while (i++ < g_plist.prec[0] - size - dot)
			write(1, "0", 1);
	return (i);
}

static char	*ft_make_the_dst(void *ptr, int size, char *hex)
{
	unsigned long	ptr2;
	char			*dst;

	ptr2 = (unsigned long)ptr;
	if (!(dst = (char *)ft_calloc(sizeof(char), size + 1)))
		return (0);
	while (size--)
	{
		dst[size] = hex[ptr2 % 16];
		ptr2 /= 16;
	}
	return (dst);
}

int			ft_type_p_dot(void *ptr, char *dst, int s)
{
	int	i;
	int	j;
	int	dot;
	int	size;

	i = -1;
	j = -1;
	size = g_plist.prec[1] < s ? s : g_plist.prec[1];
	dot = !(unsigned long)ptr && !g_plist.prec[1] ? 1 : 0;
	if (g_plist.flags[0] == 2 || g_plist.flags[0] == 4)
		while (-dot + ++i < g_plist.prec[0] - size - 2)
			write(1, " ", 1);
	ft_putstr("0x");
	while (++j < g_plist.prec[1] - ft_hex_size((unsigned long)ptr))
		write(1, "0", 1);
	dot ? size-- : ft_putstr(dst);
	free(dst);
	if (g_plist.flags[0] == 1)
		while (++i < g_plist.prec[0] - size - 2)
			write(1, " ", 1);
	return (size + i + 2);
}

int			ft_type_p(void *ptr, char *hex)
{
	int		i;
	int		size;
	char	*dst;
	int		dot;

	i = 0;
	dot = 0;
	//자릿수
	size = ft_hex_size((unsigned long)ptr);
	//dst 만들기 size hex로 변완해서 
	dst = ft_make_the_dst(ptr, size, hex);
	//두번째 플래그가 있는가?
	if (g_plist.flags[1])
		return (ft_type_p_dot(ptr, dst, size));
	//플래그
	if (g_plist.flags[0] == 3 && !(unsigned long)ptr && !g_plist.prec[0])
		dot = 1;
	i = ft_flags_before(size, dot, i);
	dot ? size-- : ft_putstr(dst);
	free(dst);
	if (g_plist.flags[0] == 1)
		while (i++ < g_plist.prec[0] - size - 2)
			write(1, " ", 1);
	return (i ? size + i + 1 : size + 2);
}
