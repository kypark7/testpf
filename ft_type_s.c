/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:19:34 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:19:44 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_type_s_dot(char *str)
{
	int i;
	int j;
	int	s;
	
	//두번째 prec가 string 길이보다 작을때
	if (g_plist.prec[1] < (int)ft_strlen(str))
		s = g_plist.prec[1];
	else
		s = (int)ft_strlen(str);
	i = -1;
	j = -1;
	//처음 플래그 0이면
	if (g_plist.flags[0] == 2)
		while (++i < g_plist.prec[0] - s)
			write(1, "0", 1);
	//처음플래그 * or digit
	else if (g_plist.flags[0] == 4)
		while (++i < g_plist.prec[0] - s)
			write(1, " ", 1);
	while (++j < s)
		ft_putchar(str[j]);
	//플래그 -
	if (g_plist.flags[0] == 1)
		while (++i < g_plist.prec[0] - s)
			write(1, " ", 1);
	return (j + i);
}

int		ft_type_s(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	//플래그 두개이상
	if (g_plist.flags[1])
		return (ft_type_s_dot(str));
	//처음플래그 0이면
	if (g_plist.flags[0] == 2)
		while (i++ < g_plist.prec[0] - (int)ft_strlen(str))
			write(1, "0", 1);
	//처음플래그 * or digit
	else if (g_plist.flags[0] == 4)
		while (i++ < g_plist.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	// 처음플래그 . 이면
	if (g_plist.flags[0] == 3)
	{
		while (i < g_plist.prec[0] && i < (int)ft_strlen(str))
			ft_putchar(str[i++]);
		return (i);
	}
	else
		ft_putstr(str);
	//처음플래그 -이면
	if (g_plist.flags[0] == 1)
		while (i++ < g_plist.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	return (ft_strlen(str) + (i ? --i : i));
}
