/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:31:38 by yakhay            #+#    #+#             */
/*   Updated: 2022/11/01 10:51:17 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_chang(int nb, int len, char *base)
{
	long	i;
	long	k;
	int		c;

	c = 1;
	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		c += ft_putchar('-');
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

int	ft_putnbr(int nb)
{
	int		i;
	char	*base;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	base = "0123456789";
	while (base[i])
		i++;
	return (ft_chang(nb, i, base));
}

// #include <stdio.h>
// int main()
// {
// 	//int a, b, c;
// 	// printf("Enter value of a in decimal format:");
//     // scanf("%d", &a);
//    int a = -5;
// 	printf(" %d\n", ft_putnbr(a));
// //printf("memory address = %u\n", -1);
// 	//c = -2147483649;
//      //ft_putnbr_base(c);
//      //printf("%d",c);
// }
