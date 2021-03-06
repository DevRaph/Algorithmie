/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 18:26:13 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/24 18:49:42 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int b)
{
	if (b >= 2)
	{
		if (n < 0)
		{
			ft_putstr("negatif pas encore geres\n");
			n = -(n);
		}
		if (n >= b)
		{
			ft_putnbr_base(n / b, b);
			ft_putnbr_base(n % b, b);
		}
		else
		{
			if (b < 10)
				ft_putchar('0' + n);
			else
				ft_putchar((n < 10) ? ('0' + n) : ('A' + (n - 10)));
		}
	}
}

void	ft_print_bin(int nb)
{
	ft_putnbr_base(nb, 2);
}

void	ft_print_hex(int nb)
{
	ft_putstr("0x");
	ft_putnbr_base(nb, 16);
}
