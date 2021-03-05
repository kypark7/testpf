/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:32:31 by kypark            #+#    #+#             */
/*   Updated: 2020/11/04 17:40:31 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*s;
	long long	m;
	long long	i;

	m = n;
	i = 1;
	while (m /= 10)
		i++;
	if (n < 0)
		i++;
	if (n == -2147483648)
		return (s = ft_strdup("-2147483648"));
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if ((m = n) < 0)
		m = -n;
	s[i] = '\0';
	while (--i >= 0)
	{
		s[i] = (m % 10) + '0';
		m /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
