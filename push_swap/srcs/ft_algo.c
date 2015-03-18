/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 19:03:19 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/18 14:03:41 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

void				ft_checktail(t_stack pa, t_stack pb, int *nb)
{
	int				i;

	i = (pa.opt[REV] == '0') ? pa.tab[0] < pa.tab[1] : pa.tab[0] > pa.tab[1];
	if (pa.nb > 2 && i && pa.nb != 3 && pa.size > 5)
	{
		*nb += ft_rotate_r(&pa, &pb, 'a');
		ft_print(pa, pb, "rra", "not");
		*nb += ft_rotate_r(&pa, &pb, 'a');
		ft_print(pa, pb, "rra", "not");
		*nb += ft_swaps(pa, '1');
		ft_print(pa, pb, "sa", "not");
		ft_putchar(10 + (!ft_issort(pa, 0) || pb.nb) * 22);
		*nb += ft_rotate(&pa, &pb, 'a');
		ft_print(pa, pb, "ra", "not");
		*nb += ft_rotate(&pa, &pb, 'a');
		ft_print(pa, pb, "ra", "not");
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
		ft_print(pa, pb, (i == 1) ? "sa" : "not", (i == 1) ? "not" : "sb");
		ft_putchar(10 + (!ft_issort(pa, 0) || pb.nb) * 22);
	}
}

static void			ft_first_part(t_stack *pa, t_stack *pb, int *nb)
{
	//int				i;

	//i = 0;
	//i = pa->tab[ft_maxmin(pa->tab, pa->size, 0)] >= pb->tab[ft_maxmin(pb->tab, pb->size, 1)];

	while (pa->nb > 0 && !ft_issort(*pa, 0))
	{
		// a voir
		if (pa->tab[pa->nb - 2] > pa->tab[pa->nb - 1] && (pa->size != 5))
			ft_checkend(*pa, *pb, nb);
		if(ft_maxmin(pa->tab, pa->nb, 1) == (pa->nb - 1))
		{
			*nb += ft_rotate(pa, pb, 'a');
			ft_print(*pa, *pb, "ra", "not");
		}
		ft_checkend(*pa, *pb, nb);
		if (ft_maxmin(pa->tab, pa->nb, 1) == (pa->nb - 1))
		{
			*nb += ft_rotate(pa, pb, 'a');
			ft_print(*pa, *pb, "ra", "not");
		}
		else if (!ft_issort(*pa, 0))
		{
			*nb += ft_push(pa, pb, 'b');
			ft_print(*pa, *pb, "not", "pb");
		}
	}
}

void				ft_test(t_stack pa, t_stack pb, int *nb)
{
	int				i;
//	int				g;
//	int				j;

	ft_first_part(&pa, &pb, nb);
	/*g = (pa.nb == 0) ? pb.tab[ft_maxmin(pb.tab, pb.nb, 1)] : pa.tab[ft_maxmin(pa.tab, pa.nb, 0)];
	j = (pb.nb == 0) ? pa.tab[ft_maxmin(pa.tab, pa.nb, 0)] : pb.tab[ft_maxmin(pb.tab, pb.nb, 1)];
	ft_putnbr(g);
	ft_putendl("<< i");
	ft_putnbr(j);
	ft_putendl("<< j");*/
	i = 0;
	while (pb.nb > 0)
	{
		//if (pb.nb == 1)
		//	ft_checkend(pa, pb, nb);
		i = ft_maxmin(pb.tab, pb.nb, 1);
		if (i < (pb.nb / 2) && pb.nb > 2)
			while (i-- >= 0)
			{
				*nb += ft_rotate_r(&pa, &pb, 'b');
				ft_print(pa, pb, "not", "rrb");
			}
		else
		{
			while (i++ < (pb.nb - 1))
			{
				*nb += ft_rotate(&pa, &pb, 'b');
				ft_print(pa, pb, "not", "rb");
			}
		}
		/*g = (pa.nb == 0) ? pb.tab[ft_maxmin(pb.tab, pb.nb, 1)] : pa.tab[ft_maxmin(pa.tab, pa.nb, 0)];
		j = (pb.nb == 0) ? pa.tab[ft_maxmin(pa.tab, pa.nb, 0)] : pb.tab[ft_maxmin(pb.tab, pb.nb, 1)];
		ft_putnbr(g);
		ft_putendl("<< g");
		ft_putnbr(j);
		ft_putendl("<< j");*/
		*nb += ft_push(&pa, &pb, 'a');
		ft_print(pa, pb, "pa", "not");
	}
}
