/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:17:23 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:17:37 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_type_c(int c)
{
	int	i;

	i = 0;
	//플래그 0
	if (g_plist.flags[0] == 2)
		while (i++ < g_plist.prec[0] - 1)
			write(1, "0", 1);
	//* digit 앞부분 자리수 맞춰주기
	else if (g_plist.flags[0] == 4)
		while (i++ < g_plist.prec[0] - 1)
			write(1, " ", 1);
	ft_putchar(c);
	// - 자리수 맞춰주기 뒷부분
	if (g_plist.flags[0] == 1)
		while (i++ < g_plist.prec[0] - 1)
			write(1, " ", 1);
	return (i ? i : ++i);
}
