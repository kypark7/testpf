/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:58:56 by kypark            #+#    #+#             */
/*   Updated: 2020/11/04 21:29:15 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	len;
	size_t	n;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(new_s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	n = 0;
	while (s[n])
	{
		new_s[n] = f(n, s[n]);
		n++;
	}
	new_s[n] = '\0';
	return (new_s);
}
