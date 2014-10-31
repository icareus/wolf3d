/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:13:34 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/30 22:29:08 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	rt_prompt(char *out, char *in, unsigned int in_len)
{
	if (out && in)
	{
		ft_putstr(out);
		read(0, in, in_len);
	}
}