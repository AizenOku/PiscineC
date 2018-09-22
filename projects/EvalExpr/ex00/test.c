/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:32:21 by ihuang            #+#    #+#             */
/*   Updated: 2018/07/08 10:25:14 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnbr.h"
#include <stdio.h>
#include <unistd.h>

char	*g_str;
int		g_i;
int		parse_sum(void);

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		parse_atom(void) // essentially atoi for one number
{
	int		result;

	result = 0;
	printf("			went into parse_atom\n");
	while (!is_number(g_str[g_i]))
		g_i++;
	while (is_number(g_str[g_i]))
	{
		result = result * 10 + g_str[g_i] - '0';
		g_i++;
	}
	g_i++;
	printf("			atom result: %d\n", result);
	return (result);
}

int		parse_paren(void)
{
	int	result;
	
	result = 0;
	printf("		went into parse_paren\n");
	while(g_str[g_i] == ' ')
		g_i++;
	if (is_number(g_str[g_i]))
	{
		printf("		no paren found\n");
		return (result = parse_atom());
	}
	else if (g_str[g_i] == '(')
	{
		printf("		(\n");
		g_i++;
		result = parse_sum();
		printf("		)\n");
		g_i++;
		printf("		bracket result: %d\n", result);
		return (result);
	}
	// handle negative cases
	printf("		paren result: %d\n", result);
	g_i++;
	return (0);
}

int		parse_multiply(void)
{
	int		result;

	int 	nbr2;
	
	printf("	went into parse_mult\n");
	result = parse_paren();
	while(g_str[g_i] == ' ')
		g_i++;
	printf("currently reviewing %d position\n", g_i);
	while (g_str[g_i] == '*' || g_str[g_i] == '/' || g_str[g_i] == '%' || g_str[g_i] == ' ')
	{	
		if (g_str[g_i] == '*')
		{
			printf("	*\n");
			g_i++;
			nbr2 = parse_paren();
			/* printf("nbr2 = %d\n", nbr2); */
			result *= nbr2;
			printf("	current result: %d\n", nbr2);
			g_i += 1;
		}
		if (*g_str == '/')
		{
			g_str++;
			return (result /= parse_atom());
		}
		if (*g_str == '%')
		{
			g_str++;
			return (result %= parse_atom());
		}
	}
	printf("	multiply result: %d\n", result);
	return (result);
}

int		parse_sum(void)
{
	int		result;
	int		nbr2;
	char	*ptr;
	printf("went into parse_sum\n");
	result = parse_multiply();
	printf("here we are in main: g_i equals %d\n", g_i);
	while (g_str[g_i] == ' ' && g_str[g_i])
		g_i++;
	while (g_str[g_i] == '+' || g_str[g_i] == '-')
	{
		ptr = g_str;
		if (g_str[g_i] == '+')
		{
			g_i++;
			nbr2 = parse_multiply();
			result += nbr2;
			g_str = ptr;
			g_i += 1;
		}
		if (*(g_str) == '-')
		{
			g_str++;
			return (result -= parse_multiply());
		}
	}
	printf("sum result: %d\n", result);
	return (result);
}

int		eval_expr(char *str)
{
	int	result;
	g_str = str;
	g_i = 0;
	
	printf("g_str = %s\n", g_str);
	result = parse_sum();
	return (result);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		(void)av;
		ft_putnbr(eval_expr("(5 * 3 + 2) * 3"));
		ft_putchar('\n');		
	}
	return (0);
}
