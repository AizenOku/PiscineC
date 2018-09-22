/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:10:21 by ihuang            #+#    #+#             */
/*   Updated: 2018/07/07 11:07:22 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnbr.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		eval_expr(char *str)
{
	int		ret;
	int		i;

	i = 0;
	write(1, &str[i], 1);
	ret = 0;
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
