/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:10:02 by yakhay            #+#    #+#             */
/*   Updated: 2022/11/01 10:35:51 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_chang(long nb, int len, char *base)
{
	long	i;
	long	k;
	int		c;

	c = 1;
	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	k = nb;
	while (k / len != 0)
	{
		k /= len;
		i *= len;
		c++;
	}
	while (i >= 1)
	{
		ft_putchar(base[nb / i]);
		nb %= i;
		i /= len;
	}
	return (c);
}

int	ft_putxh(unsigned int nb, char c)
{
	int		i;
	char	*base;

	i = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (ft_chang(nb, 16, base));
}
