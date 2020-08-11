/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:53:56 by tmaarela          #+#    #+#             */
/*   Updated: 2020/07/21 17:57:13 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

/*
** Miniprintf - a lazy mans printf
** only handles strings %s and integer %d
** takes padding width aas arg1-1, the value as arg1-2 and so on
** usage example: miniprintf("Hello %s\nLucky number is %d\n", 0, "World", 0, 8)
*/

static void			write_print(t_print print, va_list ap)
{
	char	*str;
	int		i;

	if (print.spec == 's')
		str = ft_strjoin("", va_arg(ap, char *));
	else
		str = ft_itoa(va_arg(ap, unsigned int));
	i = ft_strlen(str);
	while (i < print.width)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr(str);
	ft_memset(str, '\0', ft_strlen(str));
	free(str);
}

static t_print		parse_format(char *str, t_print print, va_list ap)
{
	print.width = va_arg(ap, unsigned int);
	if (str[0] == 's')
		print.spec = 's';
	else
		print.spec = 'd';
	return (print);
}

void				miniprintf(char *format, ...)
{
	int		i;
	va_list	ap;
	t_print	print;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print = (t_print){0, 0, 0, 0, 0, 0};
			print = parse_format(format, print, ap);
			format++;
			write_print(print, ap);
		}
		if (format[0])
		{
			write(1, &format[0], 1);
			format++;
		}
	}
	va_end(ap);
}
