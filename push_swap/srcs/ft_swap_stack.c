/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 18:58:06 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/19 11:24:33 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int				ft_swaps(t_stack p, char opt)
{
	if (p.nb > 1)
	{
		p.tab[p.nb - 1] = p.tab[p.nb - 1] ^ p.tab[p.nb - 2];
		p.tab[p.nb - 2] = p.tab[p.nb - 1] ^ p.tab[p.nb - 2];
		p.tab[p.nb - 1] = p.tab[p.nb - 1] ^ p.tab[p.nb - 2];
		if (opt == '1')
		{
			if (!ft_strcmp(p.name, "stack a"))
				ft_putstr("sa");
			else
				ft_putstr("sb");
		}
		return (1);
	}
	else
		return (0);
}

int				ft_swapss(t_stack pa, t_stack pb, char opt)
{
	if (pa.nb > 1)
	{
		pa.tab[pa.nb - 1] = pa.tab[pa.nb - 1] ^ pa.tab[pa.nb - 2];
		pa.tab[pa.nb - 2] = pa.tab[pa.nb - 1] ^ pa.tab[pa.nb - 2];
		pa.tab[pa.nb - 1] = pa.tab[pa.nb - 1] ^ pa.tab[pa.nb - 2];
	}
	if (pb.nb > 1)
	{
		pb.tab[pb.nb - 1] = pb.tab[pb.nb - 1] ^ pb.tab[pb.nb - 2];
		pb.tab[pb.nb - 2] = pb.tab[pb.nb - 1] ^ pb.tab[pb.nb - 2];
		pb.tab[pb.nb - 1] = pb.tab[pb.nb - 1] ^ pb.tab[pb.nb - 2];
	}
	if (opt == '1')
		ft_putstr("ss");
	ft_putchar(10 + (!ft_issort(pa, 0) || pb.nb) * 22);
	return (1);
}
