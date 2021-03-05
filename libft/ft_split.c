/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:52:47 by kypark            #+#    #+#             */
/*   Updated: 2020/11/09 15:46:50 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_getrownum(char const *s, char c, size_t lens)
{
	int		numl;
	size_t	i;

	numl = 0;
	i = 0;
	while (i <= lens)
	{
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			numl++;
			continue ;
		}
		i++;
	}
	return (numl);
}

char		**ft_makestr(char **str, char const *s, char c, size_t lens)
{
	int		j;
	int		k;
	size_t	i;

	i = 0;
	j = 0;
	k = 0;
	while (i <= lens)
	{
		j = 0;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				str[k][j] = s[i];
				j++;
				i++;
			}
			str[k][j] = '\0';
			k++;
			continue ;
		}
		i++;
	}
	return (str);
}

char		**ft_free(char **str, int k)
{
	int		i;

	i = 0;
	while (i <= k)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void		ft_mallocchar(char const *s, char **str, size_t lens, char c)
{
	int		j;
	int		k;
	size_t	i;

	i = 0;
	k = 0;
	while (i <= lens)
	{
		j = 0;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
			{
				i++;
				j++;
			}
			if (!(str[k] = (char *)malloc((j + 1) * sizeof(char))))
				str = ft_free(str, k);
			k++;
		}
		i++;
	}
	str[k] = 0;
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		numl;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	numl = ft_getrownum(s, c, lens);
	if (!(str = (char **)malloc((numl + 1) * sizeof(char *))))
		return (NULL);
	ft_mallocchar(s, str, lens, c);
	return (ft_makestr(str, s, c, lens));
}
