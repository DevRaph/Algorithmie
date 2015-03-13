
#include "../libft/libft.h"
#include "../includes/push_swap.h"
#include <stdlib.h>

// voir si p.nb - 1 ou regler taille
void			ft_print_stack(t_stack p)
{
	int			i;

	ft_putstr(p.name);
	ft_putstr(" : ");
	i = -1;
	while (i++ < (p.nb - 1))
	{
		ft_putnbr(p.tab[i]);
		if (i < (p.nb - 1))
			ft_putstr(" > ");
	} 
	ft_putchar(10);
} 

t_stack			*ft_create_stack(char **av, int ac, char *s)
{  
	t_stack		*p;
	int			i;

	if (!(p = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	p->name = s;
	p->size = ac - 1;
	if (!(p->tab = (int *)malloc(sizeof(int) * p-> size)))
		return (NULL);
	p->nb = 0;
	if (av != NULL)
	{ 
		p->nb = ac - 1;
		i = 0;
		while (i++ < p->size)
			p->tab[i - 1] = ft_atoi(av[i]);
	} 
	return (p);
}

