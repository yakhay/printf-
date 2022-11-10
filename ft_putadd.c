/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:44:47 by yakhay            #+#    #+#             */
/*   Updated: 2022/11/02 12:22:23 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_chang(unsigned long nb, int len, char *base)
{
	long			i;
	unsigned long	k;
	int				c;

	c = 3;
	i = 1;
	write(1, "0x", 2);
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

int	ft_putadd(unsigned long nb)
{	
	char	*base;

	base = "0123456789abcdef";
	return (ft_chang(nb, 16, base));
}
