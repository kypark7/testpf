/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:51:46 by kypark            #+#    #+#             */
/*   Updated: 2020/11/04 21:54:21 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	long int	number;
	char		c;

	c = '0';
	number = n;
	if (number < 0)
	{
		number = number * -1;
		write(fd, "-", 1);
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putchar_fd((number % 10) + c, fd);
	}
	else
		ft_putchar_fd(number + c, fd);
}
