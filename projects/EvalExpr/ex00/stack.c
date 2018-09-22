/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 10:11:02 by ihuang            #+#    #+#             */
/*   Updated: 2018/07/07 11:06:56 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_list *begin_list, void *data)
{
	t_list	*new;
	
	new = (t_list*)malloc(sizeof(t_list));
	new->data = data;
	if (begin_list == NULL)
		new->next = NULL;
	else
		new->next = begin_list;
	begin_list = new;
}

void	*pop(t_list *begin_list)
{
	t_list	*temp;
	char	*ret;

	ret = NULL;
	if (begin_list != NULL)
	{
		temp = begin_list;
		ret = temp->data;
		begin_list = temp->next;
		free(temp);
	}
	return (ret);
}

void display(t_list *begin_list)
{
	if (begin_list != NULL)
	{
		t_list	*temp = begin_list;
		while (temp->next != NULL)
		{
			/* printf("%c--->",temp->data); */
			temp = temp -> next;
		}
		/* printf("%c--->NULL",temp->data); */
	}
}
