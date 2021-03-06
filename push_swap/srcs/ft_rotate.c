/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 18:57:34 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/19 14:35:10 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void			ft_swap_rot(t_stack *p, int i, int a)
{
	*(p->tab + i) = *(p->tab + i) ^ *(p->tab + a);
	*(p->tab + a) = *(p->tab + i) ^ *(p->tab + a);
	*(p->tab + i) = *(p->tab + i) ^ *(p->tab + a);
}

int					ft_rotate(t_stack *pa, t_stack *pb, char o)
{
	int				i;
	char			*s;

	if (o == 'a' || o == 'r')
	{
		i = pa->nb - 1;
		while (i-- > 0)
			ft_swap_rot(pa, i, i + 1);
		ft_putstr((o == 'r') ? "rr" : "ra");
	}
	if (o == 'b' || o == 'r')
	{
		i = pb->nb - 1;
		while (i-- > 0)
			ft_swap_rot(pb, i, i + 1);
		if (o != 'r')
			ft_putstr((o == 'r') ? "" : "rb");
	}
	ft_putchar(10 + (!ft_issort(*pa, 0) || pb->nb) * 22);
	s = (o == 'a') ? "ra" : "not";
	if (pa->opt[VB] == '1' && o == 'r')
		ft_print(*pa, *pb, "rrr", "rrr");
	else if (pa->opt[VB] == '1')
		ft_print(*pa, *pb, s, (o == 'b') ? "rb" : "not");
	return (1);
}

int					ft_rotate_r(t_stack *pa, t_stack *pb, char o)
{
	int				i;
	char			*s;

	if (o == 'a' || o == 'r')
	{
		i = 0;
		while (i++ < (pa->nb - 1))
			ft_swap_rot(pa, i, i - 1);
		ft_putstr((o == 'r') ? "rrr" : "rra");
	}
	if (o == 'b' || o == 'r')
	{
		i = 0;
		while (i++ < (pb->nb - 1))
			ft_swap_rot(pb, i, i - 1);
		if (o != 'r')
			ft_putstr((o == 'r') ? "" : "rrb");
	}
	ft_putchar(10 + (!ft_issort(*pa, 0) || pb->nb) * 22);
	s = (o == 'a') ? "rra" : "not";
	if (pa->opt[VB] == '1' && o == 'r')
		ft_print(*pa, *pb, "rrr", "rrr");
	else if (pa->opt[VB] == '1')
		ft_print(*pa, *pb, s, (o == 'b') ? "rrb" : "not");
	return (1);
}
