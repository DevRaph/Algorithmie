/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:04:59 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/11 16:55:35 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_stack
{
	int				size;
	int				nb;
	char			*name;
	char			*opt;
	int				*tab;
}					t_stack;

void				ft_launch(char **av, int ac);
t_stack				*ft_create_stack(char **av, int ac, char *s);
void				ft_print_stack(t_stack);
void				ft_swaps(t_stack p, char opt);
void				ft_swapss(t_stack p1, t_stack p2, char opt);
void				ft_push(t_stack *pa, t_stack *pb, char o);
void				ft_rotate(t_stack *pa, t_stack *pb, char o, char opt);
void				ft_rotate_r(t_stack *pa, t_stack *pb, char o, char opt);

#endif
