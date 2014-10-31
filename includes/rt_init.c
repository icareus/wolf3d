/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:19:32 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/30 22:25:59 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <libft.h>

void	rt_init(t_env *e)
{
	char	in[PROMPT_BUFF];

	rt_prompt(PROMPT_MAP, in, PROMPT_BUFF);
	rt_check_map(in);
	ft_bzero(in, PROMPT_BUFF);
	rt_prompt(PROMPT_HDR, in, PROMPT_BUFF);
	e->win_h = ft_strdup(in);
	ft_bzero(in, PROMPT_BUFF);
	e->win_x = RES_X;
	e->win_y = RES_Y;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, e->win_h);
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->img_start = mlx_get_data_addr(
		e->img, &e->img_format.z, &e->img_format.x, &e->img_format.y);
}
