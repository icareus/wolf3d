/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 07:52:02 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/03 15:48:55 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_words(const char *str, char c)
{
	size_t		i;
	size_t		x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		if (i == 0 || str[i - 1] == c)
			x++;
		i++;
	}
	return (x);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		i;
	int		x;
	int		y;

	ret = malloc(sizeof(char *) * ft_count_words(s, c) + 1);
	i = 0;
	y = 0;
	x = 0;
	ret[x] = NULL;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && (i == 0 || (s[i] != c && s[i - 1] == c)))
		{
			x++;
			while (s[i + y] != c)
				y++;
			ret[x - 1] = ft_strsub(s, i, y);
			i += y;
			y = 0;
		}
	}
	return (ret);
}
