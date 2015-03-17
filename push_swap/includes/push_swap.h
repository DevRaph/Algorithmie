/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:04:59 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/17 18:38:00 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define COL 0
# define VB 1
# define NB 2
# define REV 3
# define END 4

typedef struct		s_stack
{
	int				size;
	int				nb;
	char			*name;
	char			*opt;
	int				*tab;
}					t_stack;

void				ft_launch(char **av, int ac);
t_stack				*ft_create_stack(char **av, int ac, char *s, char *opt);
void				ft_print_stack(t_stack p, char *s);
void				ft_print(t_stack pa, t_stack pb, char *sa, char *sb);
int					ft_swaps(t_stack p, char opt);
int					ft_swapss(t_stack p1, t_stack p2, char opt);
int					ft_push(t_stack *pa, t_stack *pb, char o);
int					ft_rotate(t_stack *pa, t_stack *pb, char o);
int					ft_rotate_r(t_stack *pa, t_stack *pb, char o);
int					ft_isint(char *s);
int					ft_isdbl(int s, char **av, int a);
int					ft_issort(t_stack p, int m);
int					ft_maxmin(int *tab, int size, int m);
int					ft_issplit(t_stack pa, t_stack pb, int m);

#endif
