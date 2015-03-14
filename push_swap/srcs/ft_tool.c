
#include "../libft/libft.h" 
#include "../includes/push_swap.h" 
#include <stdlib.h>

int					ft_isint(char *s)
{
	int				i;
	char			*tab;
	int				a;

	tab = ft_strdup("2147483647");
	a = (s[0] == '-' && ft_strlen(s) <= 11) ? 1 : 0 ;
	if ((ft_strlen(s) - a) > 10)
		return (0);
	if ((ft_strlen(s) - a) == 10)
		tab[9] = (a == 1) ? '8' : '7'; 
	i = -1 + a;
	while (s && s[++i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		if ((ft_strlen(s) - a) == 10 && (s[i] > tab[i - a]))
			return (0);
		if ((ft_strlen(s) - a) == 10 && (s[i] < tab[i - a]))
			return (1);
	}
	return (1);
}

int					ft_isdbl(char *s, char **av, int a)
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
