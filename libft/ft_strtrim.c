/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:26:56 by kypark            #+#    #+#             */
/*   Updated: 2020/11/02 17:34:40 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_istrim(char c, char const *set)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	size_t	start;
	size_t	last;
	size_t	len;

	start = 0;
	last = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_istrim(s1[start], set) && s1[start])
		start++;
	while (ft_istrim(s1[len - 1], set) && (len - 1))
		len--;
	if (len < start)
		len = start;
	new_s = malloc(len - start + 1);
	if (!new_s)
		return (NULL);
	while (start < len)
		new_s[last++] = s1[start++];
	new_s[last] = '\0';
	return (new_s);
}
