/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 19:03:19 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/19 14:49:40 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

void				ft_checktail(t_stack pa, t_stack pb, int *nb)
{
	int				i;

	i = (pa.opt[REV] == '0') ? pa.tab[0] < pa.tab[1] : pa.tab[0] > pa.tab[1];
	if (pa.nb > 2 && i && pa.nb != 3 && pa.size >= 5)
	{
		*nb += ft_rotate_r(&pa, &pb, 'a');
		*nb += ft_rotate_r(&pa, &pb, 'a');
		*nb += ft_swaps(pa, '1');
		ft_putchar(10 + (!ft_issort(pa, 0) || pb.nb) * 22);
		ft_print(pa, pb, "sa", "not");
		*nb += ft_rotate(&pa, &pb, 'a');
		*nb += ft_rotate(&pa, &pb, 'a');
	}
}

void				ft_checkend(t_stack pa, t_stack pb, int *nb)
{
	int				i;

	i = 0;
	if (pa.nb >= 2 || pb.nb >= 2)
	{
		if (pa.nb >= 2 && (pa.tab[pa.nb - 1] > pa.tab[pa.nb - 2]))
			i += 1;
		if (pb.nb >= 2 && (pb.tab[pb.nb - 1] < pb.tab[pb.nb - 2]))
			i += 2;
	}
	if (i == 3)
		*nb += ft_swapss(pa, pb, '1');
	else if (i == 2)
		*nb += ft_swaps(pb, '1');
	else if (i == 1)
		*nb += ft_swaps(pa, '1');
	if (i == 3)
		ft_print(pa, pb, "ss", "ss");
	else if (i > 0 && i < 3)
	{
		ft_putchar(10 + (!ft_issort(pa, 0) || pb.nb) * 22);
		ft_print(pa, pb, (i == 1) ? "sa" : "not", (i == 1) ? "not" : "sb");
	}
}

static void			ft_first_part(t_stack *pa, t_stack *pb, int *nb)
{
	while (pa->nb > 0 && !ft_issort(*pa, 0))
	{
		if (pa->tab[pa->nb - 2] > pa->tab[pa->nb - 1])
			ft_checkend(*pa, *pb, nb);
		if (ft_maxmin(pa->tab, pa->nb, 1) == (pa->nb - 1))
			*nb += ft_rotate_r(pa, pb, 'a');
		ft_checkend(*pa, *pb, nb);
		if (ft_maxmin(pa->tab, pa->nb, 1) == (pa->nb - 1))
			*nb += ft_rotate(pa, pb, 'a');
		else if (!ft_issort(*pa, 0))
			*nb += ft_push(pa, pb, 'b');
	}
}

void				ft_test(t_stack pa, t_stack pb, int *nb)
{
	int				i;

	if (pa.tab[pa.nb - 1] > pa.tab[0])
		*nb += ft_rotate(&pa, &pb, 'a');
	ft_checktail(pa, pb, nb);
	if (!ft_issort(pa, 0) && pa.nb != 3)
		ft_checkend(pa, pb, nb);
	ft_first_part(&pa, &pb, nb);
	i = 0;
	while (pb.nb > 0)
	{
		ft_checkend(pa, pb, nb);
		i = ft_maxmin(pb.tab, pb.nb, 1);
		if (i < (pb.nb / 2) && pb.nb > 2)
			while (i-- >= 0)
				*nb += ft_rotate_r(&pa, &pb, 'b');
		else
		{
			while (i++ < (pb.nb - 1))
				*nb += ft_rotate(&pa, &pb, 'b');
		}
		*nb += ft_push(&pa, &pb, 'a');
	}
}
