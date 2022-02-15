/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:07:16 by cprester          #+#    #+#             */
/*   Updated: 2022/02/15 19:57:42 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list)
{
	t_list	*head;
	t_list	*tmp;

	head = (*list)->next;
	tmp = head->next;
	head->next = *list;
	(*list)->next = tmp;
	(*list) = head;
}

void	ft_sa_sb_ss(t_list **list_a, t_list **list_b, char c)
{
	if (c == 'a')
	{
		ft_swap(list_a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		ft_swap(list_b);
		write(1, "sb\n", 3);
	}
	else
	{
		ft_swap(list_a);
		ft_swap(list_b);
		write(1, "ss\n", 3);
	}
}

void	ft_push(t_list **list_out, t_list **list_in)
{
	t_list	*head;
	t_list	*tmp;

	head = (*list_out);
	(*list_out) = (*list_out)->next;
	tmp = (*list_in);
	(*list_in) = head;
	head->next = tmp;
}

void	ft_pa_pb(t_list **list_a, t_list **list_b, char c)
{
	if (c == 'a')
	{
		ft_push(list_b, list_a);
		write(1, "pa\n", 3);
	}
	else
	{
		ft_push(list_a, list_b);
		write(1, "pb\n", 3);
	}
}
