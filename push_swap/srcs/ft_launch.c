/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:17:14 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/19 14:39:15 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void			ft_exec(t_stack pa, t_stack pb)
{
	int				nb;

	nb = 0;
	if (ft_issort(pa, 0))
		write (1, "\n", 1);
	ft_print(pa, pb, "not", "not");
	while (!ft_issort(pa, 0))
		ft_test(pa, pb, &nb);
	if (ft_issort(pa, 0))
	{
		if (pa.opt[END] == '1' && pa.opt[VB]++ == '0')
			ft_print(pa, pb, "not", "not");
		if (pa.opt[NB] == '1')
			ft_putnbr(nb);
		ft_putstr((pa.opt[NB] == '1') ? " operations\n" : "");
		exit (0);
	}
}

void				ft_init_opt(char *s, char c)
{
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
	while (++i < ac && ((av[i][0] == '-') && ft_isalpha(av[i][1])))
		ft_init_opt(opt, av[i][1]);
	a = i;
	while (av && av[i])
	{
		if (!ft_isint(av[i]))
			return (0);
		if (!ft_isdbl(ft_atoi(av[i]), av, i))
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
		if ((ac - a + 1) < 1)
			exit (write(1, "\n", 1));
		pa = ft_create_stack(av, ac - a + 1, "stack a", opt);
		pb = ft_create_stack(NULL, ac - a + 1, "stack b", opt);
		ft_exec(*pa, *pb);
	}
	else
		ft_putendl("Error");
	free(opt);
}
