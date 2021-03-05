/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:07:46 by kypark            #+#    #+#             */
/*   Updated: 2020/10/28 18:07:49 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	i = 0;
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	if (new_src <= new_dst)
		while (len--)
			new_dst[len] = new_src[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
