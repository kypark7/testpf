/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:16:22 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:16:33 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_p_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_p_atoi(const char **str, int sign)
{
	unsigned long long int	num2;
	unsigned long long int	num;

	num = 0;
	while (*(*str) == '-' || *(*str) == '0')
	{
		if (*(*str) == '-')
			sign = -1;
		(*str)++;
	}
	if (*(*str) == '*')
	{
		num = va_arg(g_plist.arg, int);
		(*str)++;
	}
	else
		while (*(*str) >= '0' && *(*str) <= '9')
		{
			num2 = num;
			num = num * 10 + (*(*str) - '0');
			if (num >= LLONG_MAX || num < num2)
				return (sign == 1 ? -1 : 0);
			(*str)++;
		}
	return (num * sign);
}

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	if (!s || n < 0)
		return ;
	ptr = (char *)s;
	if (n == 0)
		return ;
	while (n--)
		ptr[n] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (!(dst = malloc(sizeof(void) * size * count)))
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}
