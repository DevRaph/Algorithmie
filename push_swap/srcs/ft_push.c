
#include "../libft/libft.h"
#include "../includes/push_swap.h"

// char c choose pile a or pile b by 'a' or 'b'
void			ft_push(t_stack *pa, t_stack *pb, char o)
{ 
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
	ft_putstr((o == 'a') ? "pa " : "pb ");
}
