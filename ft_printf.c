/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:15:07 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:15:19 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_reset_list(void)
{
	g_plist.flags[0] = 0;
	g_plist.flags[1] = 0;
	g_plist.prec[0] = 0;
	g_plist.prec[1] = 0;
	g_plist.error = 0;
}

void	ft_ajust(void)
{
	if (g_plist.flags[0] == 3 && g_plist.prec[0] < 0)
	{
		g_plist.flags[0] = 0;
		g_plist.prec[0] = 0;
	}
	else if (g_plist.flags[0] == 2 && g_plist.prec[0] < 0)
	{
		g_plist.flags[0] = 1;
		g_plist.prec[0] *= -1;
	}
	else if (g_plist.prec[0] < 0)
	{
		g_plist.flags[0] = 1;
		g_plist.prec[0] *= -1;
	}
	if (g_plist.flags[1] && g_plist.prec[1] < 0)
	{
		g_plist.flags[1] = 0;
		g_plist.prec[1] = 0;
	}
}

int		ft_printf(const char *format, ...)
{
	int		sum;

	sum = 0;
	va_start(g_plist.arg, format);
	while (*format)
	{
		ft_reset_list();
		if (*format == '%')
		{
			format++;
			ft_get_flag(&format);
			ft_ajust();
			sum += ft_get_type(&format);
		}
		else
		{
			ft_putchar(*format);
			sum++;
		}
		if (g_plist.error)
			return (-1);
		format++;
	}
	va_end(g_plist.arg);
	return (sum);
}
