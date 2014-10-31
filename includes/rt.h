/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 23:47:25 by abarbaro          #+#    #+#             */
/*   Updated: 2014/05/23 14:27:04 by rcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			W3D_H
# define		W3D_H

# define		MAP_ERROR		"Warning : Map not supported. Ignoring it.\n"
# define		PROMPT_BUFF		128
# define		PROMPT_MAP		"Enter map path (127 chars max) : "
# define		PROMPT_HDR		"Enter window id (127 chars max) : "
# define		RES_X			2048;
# define		RES_Y			1152;

# include		<mlx.h>
# include		<stdlib.h>
# include		<fcntl.h>
# include		<mlx_keys.h>

/*
** SwiX-Army knife : one int per dimension. One makes a point, two a vector,
** three non-colinear make a plan... Enjoy~
*/

typedef struct	s_xyz
{
	int			x;
	int			y;
	int			z;
}				t_xyz;

/*
** Win_h : window title
** win_(x:y) : window(width:height)
** mode : wether the program is running verbose (1) or normal (0)
** img_format.(x:y:z) : Image formatting (width:endian:depth)
** img_start[ pix_xyz.y*win_x + pix_xyz.x ] : Image access array [ pixel index ]
**
*/

typedef struct	s_env
{
	char		*win_h;
	int			fd_cfg;
	int			win_x;
	int			win_y;
	void		*mlx;
	void		*win;
	void		*img;
	t_xyz		img_format;
	char		*img_start;
}				t_env;

/*
**		rt_check_map.c
*/

char			*rt_check_map(const char *map);

/*
**		rt_compute.c
*/

void			rt_compute(t_env *e);

/*
**		rt_init.c
*/

void			rt_init(t_env *e);

/*
**		rt_key_hook.c
*/

int				key_hook(int keycode, t_env *e);

/*
**		rt_prompt.c
*/

void			rt_prompt(char *out, char *in, unsigned int in_len);

#endif
