/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:14:08 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:14:29 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_get_type(const char **format)
{
	if (**format == 0)
		g_plist.error = 1;
	else if (**format == 'c')
		return (ft_type_c(va_arg(g_plist.arg, int)));
	else if (**format == 's')
		return (ft_type_s(va_arg(g_plist.arg, char *)));
	else if (**format == 'p')
		return (ft_type_p(va_arg(g_plist.arg, void *), "0123456789abcdef"));
	else if (**format == 'd' || **format == 'i')
		return (ft_type_d_i(va_arg(g_plist.arg, int), 0));
	else if (**format == 'u')
		return (ft_type_u(va_arg(g_plist.arg, int)));
	else if (**format == 'x')
		return (ft_type_x(va_arg(g_plist.arg, unsigned int), 0,
					"0123456789abcdef"));
	else if (**format == 'X')
		return (ft_type_x(va_arg(g_plist.arg, unsigned int), 0,
					"0123456789ABCDEF"));
	else if (**format == '%')
		return (ft_type_c((int)'%'));
	return (0);
}

void	ft_get_flag(const char **format)
{
	int		i;

	i = -1;
	//플래그 따라 숫자로 구분
	while (++i < 2)
	{
		//좌측정렬
		if (**format == '-')
			g_plist.flags[i] = 1;
		//선행이 0이 필드 너비에 대한 출력을 채움
		else if (**format == '0')
			g_plist.flags[i] = 2;
		//.뒤에 따라오는 수만큼 소수점 아래를 출력
		else if (**format == '.')
			g_plist.flags[i] = 3;
		// width나 .처럼 숫자가 필요한 옵션에서 숫자를 *로 대채
		else if (**format == '*' || ft_p_isdigit((int)**format))
			g_plist.flags[i] = 4;
		if (g_plist.flags[i])
		{
			//*랑 digit 아니면
			if (g_plist.flags[i] != 4)
				(*format)++;
			//prec 값 넣기
			g_plist.prec[i] = ft_p_atoi(format, 1);
		}
	}
	return ;
}
