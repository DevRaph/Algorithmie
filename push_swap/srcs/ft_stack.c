
#include "../libft/libft.h"
#include "../includes/push_swap.h"
#include <stdlib.h>

// voir si p.nb - 1 ou regler taille
void			ft_print(t_stack pa, t_stack pb, char *sa, char *sb)
{
	//if (sa != NULL && sb != NULL)
	if (pa.opt[VB] == '1')
	{
		ft_putstr("\n");
		ft_print_stack(pa, sa);
		ft_print_stack(pb, sb);
		ft_putstr("\n");
	} 
}

static void		ft_print_name(char *s)
{
	ft_setbgcolor(235);
	ft_setfgcolor(245);
	ft_putstr(" ");
	ft_putstr(s);
	ft_putstr(" ");
	ft_resetcolor();
	ft_putstr(": ");
}

void			ft_print_stack(t_stack p, char *s)
{
	int			i;
	int			col;

	col = (p.opt[COL] == '1') ? 1 : 0 ; 
	ft_print_name(p.name);
	i = -1;
	if (!ft_strncmp(s, "r", 1) && col)
		ft_setfgcolor(76);
	while (i++ < (p.nb - 1))
	{
		if (!ft_strncmp(s, "ss", 2) && i >= (p.nb - 2) && col)
			ft_setfgcolor(27);
		else if (!ft_strncmp(s, "s", 1) && i >= (p.nb - 2) && col)
			ft_setfgcolor(27);
		if (!ft_strncmp(s, "p", 1) && i >= (p.nb - 1) && col)
			ft_setfgcolor(202);
		ft_putnbr(p.tab[i]);
		if (i < (p.nb - 1))
			ft_putstr(" > ");
	}
	ft_resetcolor();
	ft_putchar(10);
} 

t_stack			*ft_create_stack(char **av, int ac, char *s, char *opt)
{   
	t_stack		*p;
	int			i;

	if (!(p = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	p->name = s;
	p->opt = opt;
	if (!(p->tab = (int *)malloc(sizeof(int) * ac)))
		return (NULL);
	/*i = -1;
	  while (i++ < ac)
	  p->tab[i] =  -1234;*/
	p->size = ac;
	p->nb = 0;
	if (av != NULL)
	{    
		i = 1;
		while (av && av[i] && av[i][0] == '-' && ft_isalpha(av[i][1]))
			i++;
		while (av && av[i++])
			p->tab[p->nb++] = ft_atoi(av[i - 1]);
	} 
	return (p);
}

