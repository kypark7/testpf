/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <kypark@studen.ft>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:16:47 by kypark            #+#    #+#             */
/*   Updated: 2021/03/08 18:16:57 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_ten_size(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_ten_size(n / 10));
}

int		ft_hex_size(unsigned long n)
{
	if (n < 16)
		return (1);
	return (1 + ft_hex_size(n / 16));
}
