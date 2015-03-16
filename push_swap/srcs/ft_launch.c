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
//	ft_rotate(&pa, &pb, 'a');
//	ft_rotate(&pa, &pb, 'b');
ft_rotate(&pa, &pb, 'r');
ft_putstr("\n");
ft_print_stack(pa, "rr");
ft_print_stack(pb, "rr");
ft_putstr("\n");
//	ft_rotate_r(&pa, &pb, 'a');
//	ft_rotate_r(&pa, &pb, 'b');	
ft_rotate_r(&pa, &pb, 'r');	
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
		ft_print(pa, pb, (i == 1) ? "sa" : "not", (i == 1) ? "not" : "sb" );  
}

static void			ft_first_part(t_stack pa, t_stack pb, int *nb)
{
	//while (pa.nb > 0 && !ft_issort(pa, 0))
	while (pa.nb > 0 && !ft_issort(pa, 0))
	{ 
		// voir reglage de checkend
		/*if (pa.tab[pa.nb - 2] > pa.tab[pa.nb - 1])
		  ft_checkend(pa, pb, nb);*/
		if (ft_maxmin(pa.tab, pa.nb, 1) == (pa.nb - 1))
		{
			*nb += ft_rotate(&pa, &pb, 'a');
			ft_print(pa, pb, "ra", "not");
		}	
		ft_checkend(pa, pb, nb);
		if (ft_maxmin(pa.tab, pa.nb, 1) == (pa.nb - 1))
		{
			//	ft_checkend(pa, pb, nb);	
			*nb += ft_rotate(&pa, &pb, 'a');
			ft_print(pa, pb, "ra", "not");
		}
		else if (!ft_issort(pa, 0))
		{ 
			*nb += ft_push(&pa, &pb, 'b');
			ft_print(pa, pb, "not", "pb");
			//ft_checkend(pa, pb, nb);
		}
		//ft_checkend(pa, pb, nb);
	}
}

void				ft_test2(t_stack pa, t_stack pb, int *nb)
{
	int				i;

	ft_first_part(pa, pb, nb);
	//ft_putendl("SECOND PART");
	i = 0;
	while (pb.nb > 0)
	{
		ft_checkend(pa, pb, nb);
		i = ft_maxmin(pb.tab, pb.nb, 1);
		if (i < (pb.nb / 2) && pb.nb > 2)
		{ 
			while (i-- >= 0)
			{
				*nb += ft_rotate_r(&pa, &pb, 'b');
				ft_print(pa, pb, "not", "rrb");
			}
		}
		else
		{  
			while (i++ < (pb.nb - 1))
			{
				*nb += ft_rotate(&pa, &pb, 'b');		
				ft_print(pa, pb, "not", "rb");
			}
		}  
		*nb += ft_push(&pa, &pb, 'a');
		ft_print(pa, pb, "pa", "not");
	}
	//return (nb);
}  

/* algo.c beyond */

static void			ft_checktail(t_stack pa, t_stack pb, int *nb)
{
	int				i;

	if (pa.opt[REV] == '0')
		i = pa.tab[0] < pa.tab[1];
	else
		i = pa.tab[0] > pa.tab[1];
	if (pa.nb >= 2 && i && pa.nb != 3 && pa.nb != 5)
	{ 
		*nb += ft_rotate_r(&pa, &pb, 'a');
		ft_print(pa, pb, "rra", "not");
		*nb += ft_rotate_r(&pa, &pb, 'a');
		ft_print(pa, pb, "rra", "not");
		*nb += ft_swaps(pa, '1');
		ft_print(pa, pb, "sa", "not");
		*nb += ft_rotate(&pa, &pb, 'a');
		ft_print(pa, pb, "ra", "not");
		*nb += ft_rotate(&pa, &pb, 'a');
		ft_print(pa, pb, "ra", "not");
	}
}

static void			ft_exec(t_stack pa, t_stack pb)
{ 
	int				count;
	int				nb;

	nb = 0;
	ft_print(pa, pb, "not", "not");
	ft_checktail(pa, pb, &nb);
	if (!ft_issort(pa, 0) && pa.nb != 3)
		ft_checkend(pa, pb, &nb);
	count = 0;
	//while (count < 2)
	while (1)
	{
		ft_test2(pa, pb, &nb);
		count++;
		if (ft_issort(pa, 0))
		{
			write (1, "\nstack is SORT\n", 15);
			if (pa.opt[END] == '1' && pa.opt[VB] == '0')
			{
				pa.opt[VB] = '1';
				ft_print(pa, pb, "not", "not");
			}
			if (pa.opt[NB] == '1')
			{
				ft_putnbr(nb);
				ft_putstr(" operations used");
			}
			exit (write(1, "\n", 1));
		}
		else if (count > 1)
			write (1, "\nstack is NOT sort\n", 19);
	}
} 

void				ft_init_opt(char *s, char c)
{ 
	// options : -c (color) -v (verbose) -n (number of operation) -r (reverse) -e (end)
	if (c == 'c')
		s[0] = '1';
	else if (c == 'v')
		s[1] = '1';
	else if (c == 'n')
		s[2] = '1';
	else if (c == 'r')
		s[3] = '1';
	else if (c == 'e')
		s[4] = '1';
	else
	{ 
		exit(ft_error("Launch", "illegal options, use -c -v -n -r -e"));
		//ft_print_help()
	}
}


static int			ft_check(char **av, int ac, char *opt)
{
	int				i;
	int				a;

	i = -1;
	while (++i < 5)
		opt[i] = '0';
	i = 0;
	while (++i < ac && av[i][0] == '-' && ft_isalpha(av[i][1]))
		ft_init_opt(opt, av[i][1]);
	a = i;
	while (av && av[i])
	{ 
		if (!ft_isint(av[i]))
			return (0);
		if (!ft_isdbl(av[i], av, i))
			return (0);
		i++;
	}  
	return (a + 1);
}

void				ft_launch(char **av, int ac)
{     
	t_stack			*pa;
	t_stack			*pb;
	char			*opt;
	int				a;

	opt = ft_strdup("00000");
	if ((a = ft_check(av, ac, opt)) > 0)
	{
		if ((ac - a + 1) < 2)
			exit(ft_error("Launch", " 0 operations, give more parameters"));
		pa = ft_create_stack(av, ac - a + 1, "stack a", opt);
		pb = ft_create_stack(NULL, ac - a + 1, "stack b", opt);
		ft_exec(*pa, *pb);
	}   
	else
		ft_putendl("Error");
	free(opt);
}
