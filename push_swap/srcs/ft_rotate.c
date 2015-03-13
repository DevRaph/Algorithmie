
#include "../includes/push_swap.h" 
#include "../libft/libft.h" 

static void			ft_swap_rot(t_stack *p, int i, int a)
{
	*(p->tab + i) = *(p->tab + i) ^ *(p->tab + a);
	*(p->tab + a) = *(p->tab + i) ^ *(p->tab + a);
	*(p->tab + i) = *(p->tab + i) ^ *(p->tab + a);
}

// char opt for color option
void				ft_rotate(t_stack *pa, t_stack *pb, char o, char opt)
{
	int				i;

	if (o == 'a' || o == 'r')
	{
		i = pa->nb - 1;
		while (i-- > 0)
			ft_swap_rot(pa, i, i + 1);
		ft_putstr((o == 'r') ? "rr " : "ra ");
	}
	if (o == 'b' || o == 'r')
	{ 
		i = pb->nb - 1;
		while (i-- > 0)
			ft_swap_rot(pb, i, i + 1);
		if (o != 'r')
			ft_putstr("rb ");
	}
	if (opt == '1')
		ft_putstr(" colors actived ");
}

void				ft_rotate_r(t_stack *pa, t_stack *pb, char o, char opt)
{ 
	int				i;

	if (o == 'a' || o == 'r')
	{
		i = 0;
		while (i++ < (pa->nb - 1))
			ft_swap_rot(pa, i, i - 1);
		ft_putstr((o == 'r') ? "rrr " : "rra ");
	}
	if (o == 'b' || o == 'r')
	{
		i = 0;
		while (i++ < (pb->nb - 1))
			ft_swap_rot(pb, i, i - 1);
		if (o != 'r')
			ft_putstr("rrb ");
	} 
	if (opt == '1')
		ft_putstr(" colors actived ");
}
