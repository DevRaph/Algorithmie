/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:07:39 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/18 14:38:41 by rpinet           ###   ########.fr       */
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
		ft_error("Main", "push_swap need arguments");
	return (0);
}
