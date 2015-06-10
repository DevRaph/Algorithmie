/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 18:39:04 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/19 11:56:34 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

int				ft_push(t_stack *pa, t_stack *pb, char o)
{
	char		*s;

	if (o == 'a' && pb->nb != 0)
	{
		pa->tab[pa->nb] = pb->tab[pb->nb - 1];
		pb->tab[pb->nb - 1] = -1234;
		pa->nb++;
		pb->nb--;
	}
	else if (o == 'b' && pa->nb != 0)
	{
		pb->tab[pb->nb] = pa->tab[pa->nb - 1];
		pa->tab[pa->nb - 1] = -1234;
		pb->nb++;
		pa->nb--;
	}
	ft_putstr((o == 'a') ? "pa" : "pb");
	ft_putchar(10 + (!ft_issort(*pa, 0) || pb->nb) * 22);
	s = (o == 'a') ? "pa" : "not";
	if (pa->opt[VB] == '1')
		ft_print(*pa, *pb, s, (o == 'b') ? "pb" : "not");
	return (1);
}
