/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:03:43 by cprester          #+#    #+#             */
/*   Updated: 2022/02/14 23:27:58 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **list_a, t_list **list_b, int argc)
{
	if (argc == 3)
		ft_sa_sb_ss(list_a, list_b, 'a');
	else if (argc == 4)
		ft_sort_for_three(list_a, list_b);
	else if (argc == 6)
		ft_sort_for_five(list_a, list_b, argc);
	else if (argc >= 7 && argc <= 101)
		ft_sort_for_100(list_a, list_b, argc);
	else
		ft_sort_for_500(list_a, list_b, argc);
}

void	ft_sort_for_three(t_list **list_a, t_list **list_b)
{
	int	a;
	int	b;
	int	c;

	a = (*list_a)->data;
	b = (*list_a)->next->data;
	c = (*list_a)->next->next->data;
	if (a > b && a > c && c > b)
		ft_ra_rb_rr(list_a, list_b, 'a');
	else if (a > b && a > c && b > c)
	{
		ft_ra_rb_rr(list_a, list_b, 'a');
		ft_sa_sb_ss(list_a, list_b, 'a');
	}
	else if (b > a && b > c && a > c)
		ft_rra_rrb_rrr(list_a, list_b, 'a');
	else if (b > a && b > c && c > a)
	{
		ft_ra_rb_rr(list_a, list_b, 'a');
		ft_sa_sb_ss(list_a, list_b, 'a');
		ft_rra_rrb_rrr(list_a, list_b, 'a');
	}
	else if (c > a && c > b && a > b)
		ft_sa_sb_ss(list_a, list_b, 'a');
}

int	ft_count_n(t_list *list)
{
	int	n;

	n = 0;
	while (list)
	{
		n++;
		list = list->next;
	}
	return (n);
}

void	ft_five_finish(t_list **list_a, t_list **list_b)
{
	ft_sort_for_three(list_a, list_b);
	while (ft_count_n(*list_b) != 0)
	{
		if ((*list_b)->index == 0)
			ft_pa_pb(list_a, list_b, 'a');
		else
		{
			ft_pa_pb(list_a, list_b, 'a');
			ft_ra_rb_rr(list_a, list_b, 'a');
		}
	}
}

void	ft_sort_for_five(t_list **list_a, t_list **list_b, int argc)
{
	t_list	*max_min;

	max_min = *list_a;
	while (ft_count_n(*list_a) != 3)
	{
		if (max_min->index == 0)
		{
			max_min = max_min->next;
			ft_pa_pb(list_a, list_b, 'b');
		}
		else if (max_min->index == argc - 2)
		{
			max_min = max_min->next;
			ft_pa_pb(list_a, list_b, 'b');
		}
		else
		{
			max_min = max_min->next;
			ft_ra_rb_rr(list_a, list_b, 'a');
		}
	}
	ft_five_finish(list_a, list_b);
}
