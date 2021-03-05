/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:05:44 by kypark            #+#    #+#             */
/*   Updated: 2020/11/05 20:00:18 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*lsttemp;

	if (!lst || !f)
		return (NULL);
	lstnew = NULL;
	while (lst)
	{
		if (!(lsttemp = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&lsttemp, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, lsttemp);
		lst = lst->next;
	}
	return (lstnew);
}
