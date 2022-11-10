/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putUint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:31:51 by yakhay            #+#    #+#             */
/*   Updated: 2022/11/01 16:40:45 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_chang(unsigned int nb, int len, char *base)
{
	long			i;
	unsigned int	k;
	int				c;

	c = 1;
	i = 1;
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

int	ft_putuint(unsigned int nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	while (base[i])
		i++;
	return (ft_chang(nb, i, base));
}
