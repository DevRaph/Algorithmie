/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:07:39 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/19 14:45:50 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/libft.h"

int				ft_er(void)
{
	ft_putendl("Error");
	return (0);
}

int				main(int ac, char **av)
{
	if (ac >= 2)
		ft_launch(av, ac);
	else
		write (1, "\n", 1);
	return (0);
}
