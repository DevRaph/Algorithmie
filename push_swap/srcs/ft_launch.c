/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:17:14 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/11 18:26:36 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static int			ft_isint(char *s)
{
	int		i;
	int		j;
	char	*tab;
	int		a;

	tab = ft_strdup("2147483647");
	i = 0;
	a = 0;
	if (s && s[0] == '-' && !a++)
	{
		i++;
		tab[9] = '8';	
	}
	if ((ft_strlen(s) - i) > 10)
		return (0);
	j = -1;
	while (s && s[i] != '\0')
	{
		if ((!ft_isdigit(s[i])) || (s[i] > tab[j++] && ((ft_strlen(s) - a) == 10)))
			return (0);
		i++;
	}
	free (tab);
	return (1);
}

static int 			ft_isdbl(char *s, char **av, int a)
{
	int				i;

	i = 0;
	while (av && av[++i])
	{
		if (!ft_strcmp(s, av[i]) && a != i)
			return (0);
	}
	return (1);
}

int					ft_issort(t_stack p, int m)
{
	int				i;

	i = 0;
	while (i++ < p.size - 1)
	{
		if (m >= 1 && p.tab[i - 1] > p.tab[i])
			return (0);
		if (m <= 0 && p.tab[i - 1] < p.tab[i])
			return (0);
	}
	return (1);
} 

int					ft_maxmin(int *tab, int size, int m)
{ 
	int				i;
	int				val;

	i = 0;
	val = 0;
	while (i++ < size)
	{
		if (m >= 1 && tab[val] < tab[i])
			val = i;
		if (m <= 0 && tab[val] > tab[i])
			val = i;
	}
	return (val);
}
/*
   static void			ft_test(t_stack pa, t_stack pb)
   { 
   int				i;

   ft_print_stack(pa, "not");
   ft_print_stack(pb, "not");
   ft_putstr("\nl'index de la valeur max de la pile a est : ");
   i = ft_maxmin(pa.tab, pa.size, 1);
   ft_putnbr(i);
   if (i < (pa.nb / 2))
   ft_putstr(" partie basse");
   else
   ft_putstr(" partie haute");
   ft_putstr("\nl'index de la valeur min de la pile a est : ");
   i = ft_maxmin(pa.tab, pa.size, 0);	
   ft_putnbr(i);
   if (i < (pa.nb / 2))
   ft_putstr(" partie basse");
   else
   ft_putstr(" partie haute");
   ft_putstr("\nl'index de milieu de la pile est : ");
   ft_putnbr(pa.nb / 2);
   ft_putstr("\nLa pile a est ");
   i = 1;
   if (ft_issort(pa, i))
   ft_putstr("triée ");
   else
   ft_putstr("non triée ");
   if (i >= 1)
   ft_putstr("dans l'ordre croissant");
   else
   ft_putstr("dans l'ordre decroissant");
   ft_putstr("\n\n");
   ft_swaps(pa, '1');
   ft_putstr("\n");
   ft_print_stack(pa, "sa");
   ft_print_stack(pb, "not");
   ft_putstr("\n");
   ft_push(&pa, &pb, 'b');
   ft_push(&pa, &pb, 'b');
   ft_push(&pa, &pb, 'b');
   ft_putstr("\n");	
   ft_print_stack(pa, "pb");
   ft_print_stack(pb, "pb");
   ft_putstr("\n");
//	ft_rotate(&pa, &pb, 'a', '0');
//	ft_rotate(&pa, &pb, 'b', '0');
ft_rotate(&pa, &pb, 'r', '0');
ft_putstr("\n");
ft_print_stack(pa, "rr");
ft_print_stack(pb, "rr");
ft_putstr("\n");
//	ft_rotate_r(&pa, &pb, 'a', '0');
//	ft_rotate_r(&pa, &pb, 'b', '0');	
ft_rotate_r(&pa, &pb, 'r', '0');	
ft_putstr("\n");
ft_print_stack(pa, "rrr");
ft_print_stack(pb, "rrr");
ft_putstr("\n");
ft_swaps(pa, '1');
ft_putstr("\n");
ft_print_stack(pa, "sa");
ft_print_stack(pb, "not");
ft_putstr("\n");
ft_push(&pa, &pb, 'a');
ft_push(&pa, &pb, 'a');
ft_push(&pa, &pb, 'a');
ft_putstr("\n");
ft_print_stack(pa, "pa");
ft_print_stack(pb, "pa");
ft_putstr("\n");
}
*/

static void			ft_exec(t_stack pa, t_stack pb)
{
	//	char			*op;
	int				i;
	int				count;

	count = 2;
	while (count-- > 0)
	{
		if (ft_issort(pa, 0))
			exit (write (1, "\nstack is SORT\n", 15));
		else if (count != 2)
			write (1, "\nstack is NOT sort\n", 19);
		//ft_test(pa, pb);
		ft_print(pa, pb, "not", "not");
		while (pa.nb > 0)
		{
			ft_push(&pa, &pb, 'b');
			ft_print(pa, pb, "not", "pb");
		} 
		i = 0;
		while (pb.nb > 0)
		{
			i = ft_maxmin(pb.tab, pb.nb, 1);
			if (i < (pb.size / 2))
			{
				while (i-- >= 0)
				{
					ft_rotate_r(&pa, &pb, 'b', '0');
					ft_print(pa, pb, "not", "rrb");
				}
			}
			else
			{ 
				while (i++ < (pb.nb - 1))
				{
					ft_rotate(&pa, &pb, 'b', '0');		
					ft_print(pa, pb, "not", "rb");
				}
			} 
			ft_push(&pa, &pb, 'a');
			ft_print(pa, pb, "pa", "not");
		}   
		/*ft_putstr("\n");
		  ft_print_stack(pa, "not");
		  ft_print_stack(pb, "not");
		  ft_putstr("\n");*/
	}
}

static int			ft_check(char **av, int ac)
{
	int				i;

	i = 0;
	while (av && av[++i])
	{
		if (!ft_isint(av[i]))
			return (0);
		if (!ft_isdbl(av[i], av, i))
			return (0);
	}
	(void)ac;
	return (1);
} 

void				ft_launch(char **av, int ac)
{
	t_stack			*pa;
	t_stack			*pb;

	if (ft_check(av, ac))
	{  
		//	ft_putendl("good check");
		pa = ft_create_stack(av, ac, "stack a");
		pb = ft_create_stack(NULL, ac, "stack b");
		ft_exec(*pa, *pb);
	}
	else
		ft_putendl("Error");
}
