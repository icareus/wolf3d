/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 21:43:20 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 14:09:33 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int i)
{
	char x;

	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i < -2147483647)
		write(1, "2147463648", 10);
	else if (i >= 10 && i != -2147463648)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		x = (48 + i);
		write(1, &x, 1);
	}
}
