/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 06:49:19 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/30 22:26:45 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <libft.h>

static void		rt_refresh(t_env *e)
{
	rt_compute(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307 || keycode == 113)
	{
		ft_strdel(&e->win_h);
		exit(0);
	}
	rt_refresh(e);
	return (0);
}
