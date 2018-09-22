/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:31:25 by ihuang            #+#    #+#             */
/*   Updated: 2018/07/08 10:56:21 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.putnbr.h>
#include <stdio.h>
#include <unistd.h>

char	*g_str
int		g_i;

int		parse_atom(void)
{
	int result;
	printf("			parse atom\n");
	while (g_str[g_i] == ' ')
		g_i++;
	while (g_str[g_i] <= '9' && g_str[g_i] >= '0')
	{
		result = result * 10 + g_str[g_i] - '0';
		g_i++;
	}
	printf("			atom returns: %d\n", result);
	return (result);
}

int		parse_paren(void)
{
	int result;
	printf("		parse paren\n");
	result = parse_atom();
	while (g_str[g_i] == ' ')
		g_i++;
	while (g_str[g_i] == 
}

int		parse_multiply(void)
{
	int result;
	int nbr2;
	printf("	parse multiply\n");
	result = parse_paren();

}

int		parse_sum(void)
{
	int	result;
	int nbr2;
	printf("parse sum\n");
	result = parse_multiply();

}

int		eval_expr(char *str)
{
	int result;
	
	g_str = str;
	g_i = 0;
	print("g_str = %s\n", g_str);
	result = pares_sum();
	return (result);
}

int		main(int ac, char **av)
{
	if (ac != 0)
	{
	 	(void)av;
		ft_putnbr(eval_expr("(5 * 3 + 2) * 3"));
		ft_putchar('\n');
	}
	return (0);
}
