/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:31:31 by yakhay            #+#    #+#             */
/*   Updated: 2022/11/10 21:08:36 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cheak(char *format)
{
	const char	*set;
	int			i;

	set = "cspdiuxX%%";
	i = 0;
	if (*format == '%')
	{
		while (set[i])
		{
			if (*(format + 1) == set[i])
				return (1);
			i++;
		}
	}
	return (0);
}

int	ft_print(char c)
{
	if (c == '%')
		return (0);
	else
		write(1, &c, 1);
	return (1);
}

int	ft_comp(char *format, va_list args)
{
	int	count;

	count = 0;
	if ((*(format + 1) == 'd' || *(format + 1) == 'i'))
		count = ft_putnbr(va_arg(args, int));
	else if (*(format + 1) == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*(format + 1) == 'u')
		count = ft_putuint(va_arg(args, unsigned int));
	else if (*(format + 1) == 's')
		count = ft_putstr(va_arg(args, char *));
	else if ((*(format + 1) == 'x' || *(format + 1) == 'X'))
		count = ft_putxh(va_arg(args, unsigned int), *(format + 1));
	else if (*(format + 1) == 'p')
		count = ft_putadd(va_arg(args, unsigned long ));
	else if (*(format + 1) == '%')
	{
		write(1, "%%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char	*format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (0);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (ft_cheak((char *)format) == 1)
		{
			count += ft_comp((char *)format, args);
			format += 2;
		}
		else
		{
			ft_print(*format);
			if (*format != '%')
				count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}
