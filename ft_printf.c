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

//초기화
void	ft_reset_list(void)
{
	g_plist.flags[0] = 0;
	g_plist.flags[1] = 0;
	g_plist.prec[0] = 0;
	g_plist.prec[1] = 0;
	g_plist.error = 0;
}

//
void	ft_ajust(void)
{
	// flag가 . 이고 prec 가 < 0 일때
	if (g_plist.flags[0] == 3 && g_plist.prec[0] < 0)
	{
		g_plist.flags[0] = 0;
		g_plist.prec[0] = 0;
	}
	//flag가 0 이고 prec가 <0 일때
	else if (g_plist.flags[0] == 2 && g_plist.prec[0] < 0)
	{
		g_plist.flags[0] = 1;
		g_plist.prec[0] *= -1;
	}
	//prec 가 <0 일때
	else if (g_plist.prec[0] < 0)
	{
		g_plist.flags[0] = 1;
		g_plist.prec[0] *= -1;
	}
	//두번째 플레그가 있고 두번째 pre <0 일때
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
		ft_reset_list(); //구조체 초기화
		if (*format == '%') //%이면
		{
			format++; 
			ft_get_flag(&format); //ft_get.c 플래그 
			ft_ajust();
			sum += ft_get_type(&format); //타입 넣기
		}
		else
		{
			ft_putchar(*format);
			sum++;
		}
		if (g_plist.error) //만약에러가 있으면
			return (-1);
		format++;//증가
	}
	va_end(g_plist.arg); //마지막
	return (sum); //출력된 바이트 개수 넘겨주기
}
