
#include "../includes/push_swap.h"
#include "../libft/libft.h"
int				ft_swaps(t_stack p, char opt)
{
	if (p.nb > 1)
	{ 
		p.tab[p.nb - 1] = p.tab[p.nb - 1] ^ p.tab[p.nb - 2];
		p.tab[p.nb - 2] = p.tab[p.nb - 1] ^ p.tab[p.nb - 2]; 
		p.tab[p.nb - 1] = p.tab[p.nb - 1] ^ p.tab[p.nb - 2];
		if (opt == '1')
		{ 
			if (!ft_strcmp(p.name, "stack a"))
				ft_putstr("sa ");
			else
				ft_putstr("sb ");
		}
		return (1);
	}
	else
		return (0);
}

int				ft_swapss(t_stack pa, t_stack pb, char opt)
{	    
	if (pa.nb > 1)
	{   
		pa.tab[pa.nb - 1] = pa.tab[pa.nb - 1] ^ pa.tab[pa.nb - 2];
		pa.tab[pa.nb - 2] = pa.tab[pa.nb - 1] ^ pa.tab[pa.nb - 2]; 
		pa.tab[pa.nb - 1] = pa.tab[pa.nb - 1] ^ pa.tab[pa.nb - 2];
	}
	if (pb.nb > 1)
	{   
		pb.tab[pb.nb - 1] = pb.tab[pb.nb - 1] ^ pb.tab[pb.nb - 2];
		pb.tab[pb.nb - 2] = pb.tab[pb.nb - 1] ^ pb.tab[pb.nb - 2]; 
		pb.tab[pb.nb - 1] = pb.tab[pb.nb - 1] ^ pb.tab[pb.nb - 2];
	}
	if (opt == '1')
		ft_putstr("ss ");
	return (1);
}
