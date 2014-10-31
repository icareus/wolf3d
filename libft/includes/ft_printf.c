/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 02:47:47 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/03 16:04:47 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int		ft_nbrlen(int i)
{
	int		ret;

	ret = IS_NEG(i) + 1;
	while ((i /= 10))
		ret++;
	return (ret);
}

static int		pr_check_format(char *form)
{
	int		i;

	i = 0;
	while (form[i])
	{
		if (form[i] == '%' && !(form[i + 1] || ft_strchr(PRINT_SET, form[i + 1])))
		{
			ft_putstr("Format error.");
			return (-1);
		}
		i++;
	}
	return (0);
}

static int		pr_print_arg(char c, va_list va_l)
{
	int		ret;

	if (c == 'i' || c == 'd')
	{
		ret = va_arg(va_l, int);
		ft_putnbr(ret);
		ret = ft_nbrlen(ret);
	}
	else if (c == 'c')
	{
		ft_putchar((char)va_arg(va_l, int));
		ret = 1;
	}
	else if (c == 's')
		ret = ft_putstr(va_arg(va_l, char *));
	else if (c == '%')
		ret = write(1, "%", 1);
	return (ret);
}

int				ft_printf(char *form, ...)
{
	int			pos;
	va_list		va_l;
	int			ret;

	pos = 0;
	ret = 0;
	va_start(va_l, form);
	if (pr_check_format(form))
		return (-1);
	while (*form && form[pos] != '\0')
	{
		if (form[pos] == '%')
		{
			write(1, form, pos);
			form += ++pos;
			ret += pos + pr_print_arg(*form, va_l) - 1;
			pos = 0;
			form++;
		}
		pos++;
	}
	write(1, form, pos);
	va_end(va_l);
	return (ret);
}
