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

void				ft_checkend(t_stack pa, t_stack pb)
{  
	int				i;

	i = 0;
	if (pa.nb >= 2 || pb.nb >= 2)
	{
		if (pa.nb >= 2 && (pa.tab[pa.nb - 1] > pa.tab[pa.nb - 2]))
		{
			ft_swaps(pa, '1');
			i += 1;				
		}
		if (pb.nb >= 2 && (pb.tab[pb.nb - 1] < pb.tab[pb.nb - 2]))
		{
			ft_swaps(pb, '1');
			i += 2;				
		}
		//ft_putendl("checkend");
		if (i == 3)
			ft_print(pa, pb, "ss", "ss");
		else if (i > 0 && i < 3)
			ft_print(pa, pb, ((i == 1) ? "sa" : "not"), ((i == 2) ? "sb" : "not"));
	}
} 

void				ft_test2(t_stack pa, t_stack pb)
{
	int				i;

	//ft_putendl("FIRST PART");
	while (pa.nb > 0 && !ft_issort(pa, 0))
	{ 
		// voir reglage de checkend
		/*if (pa.tab[pa.nb - 2] > pa.tab[pa.nb - 1])
		  ft_checkend(pa, pb);*/
		if (ft_maxmin(pa.tab, pa.nb, 1) == (pa.nb - 1))
		{
			ft_rotate(&pa, &pb, 'a', '0');
			ft_print(pa, pb, "ra", "not");
		}	
		ft_checkend(pa, pb);
		if (ft_maxmin(pa.tab, pa.nb, 1) == (pa.nb - 1))
		{
			//	ft_checkend(pa, pb);	
			ft_rotate(&pa, &pb, 'a', '0');
			ft_print(pa, pb, "ra", "not");
		}
		else if (!ft_issort(pa, 0))
		{
			ft_push(&pa, &pb, 'b');
			ft_print(pa, pb, "not", "pb");
			//ft_checkend(pa, pb);
		}
		//ft_checkend(pa, pb);
	}
	ft_putendl("SECOND PART");
	i = 0;
	while (pb.nb > 0)
	{
		ft_checkend(pa, pb);
		i = ft_maxmin(pb.tab, pb.nb, 1);
		if (i < (pb.nb / 2) && pb.nb > 2)
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
}  

static void			ft_exec(t_stack pa, t_stack pb)
{
	int				count;

	ft_print(pa, pb, "not", "not");
	ft_checkend(pa, pb);
	count = 0;
	//while (!ft_issort(pa, 0))
	while (count < 2)
	{
		//ft_test(pa, pb);
		//	ft_putendl("TEST\n");
		ft_test2(pa, pb);

		count++;
		if (ft_issort(pa, 0))
			exit (write (1, "\nstack is SORT\n", 15));
		else if (count > 1)
			write (1, "\nstack is NOT sort\n", 19);
	}
}

void				ft_init_opt(char *s, char c)
{ 
	// options : -c (color) -v (verbose) -n (number of operation) -r (reverse)
	if (c == 'c')
		s[0] = '1';
	else if (c == 'v')
		s[1] = '1';
	else if (c == 'n')
		s[2] = '1';
	else if (c == 'r')
		s[3] = '1';
	//s[4] = '0';
	else
	{
		exit(ft_error("Launch", "illegal options, use -c -v -n -r"));
		//ft_print_help()
	}
	//return (s);
}


static int			ft_check(char **av, int ac, char *opt)
{
	int				i;
	int				a;

	// check if option 
	i = -1;
	while (++i < 5)
		opt[i] = '0';
	i = 0;
	while (++i < ac && av[i][0] == '-' && ft_isalpha(av[i][1]))
		ft_init_opt(opt, av[i][1]);
	a = i;
	ft_putnbr(a);
	ft_putendl("<< a");
	//i = 0;
	while (av && av[++i])
	{  
		if (!ft_isint(av[i]))
			return (0);
		if (!ft_isdbl(av[i], av, i))
			return (0);
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
		ft_putnbr(a);
		ft_putendl("<< a");
		ft_putendl(opt);
		if ((ac - a + 1) < 2)
			exit(ft_error("Launch", " 0 operations, give more parameters"));
		pa = ft_create_stack(av, ac - a + 1, "stack a");
		pb = ft_create_stack(NULL, ac - a + 1, "stack b");
		ft_exec(*pa, *pb);
	} 
	else
		ft_putendl("Error");
	free(opt);
}
