/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:04:30 by kypark            #+#    #+#             */
/*   Updated: 2020/10/31 16:49:56 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	if (!*needle)
		return (char *)haystack;
	i = ft_strlen(haystack);
	j = ft_strlen(needle);
	if (j > i)
		return (NULL);
	l = 0;
	i = 0;
	while (haystack[l] && l < len)
	{
		if (haystack[l] == needle[i])
			i++;
		if (i == ft_strlen(needle))
			return ((char*)haystack + l + 1 - ft_strlen(needle));
		if (haystack[l] == ' ')
			i = 0;
		l++;
	}
	return (NULL);
}
