/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:03:43 by cprester          #+#    #+#             */
/*   Updated: 2022/02/11 01:09:24 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **list_a, t_list **list_b, int argc)
{
	if (argc == 3)
		ft_sort_for_two(list_a, list_b);
	else if (argc == 4)
		ft_sort_for_three(list_a, list_b);
	else if (argc == 5)
		sort_for_four(list_a, list_b, argc);
}

void	ft_sort_for_two(t_list **list_a, t_list **list_b)
{
	if ((*list_a)->data > (*list_a)->next->data)
		ft_sa_sb_ss(list_a, list_b, 'a');
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

// void	ft_sort_for_four(t_list **list_a, t_list **list_b)
// {
// 	int	a;
// 	int	b;
// 	int	c;
// 	int d;

// 	a = (*list_a)->data;
// 	b = (*list_a)->next->data;
// 	c = (*list_a)->next->next->data;
// 	d = (*list_a)->next->next->next->data;
// 	if (a < b && a < c && a < d)
// 	{
// 		ft_pa_pb(list_a, list_b, 'b');
// 		ft_sort_for_three(list_a, list_b);
// 		ft_pa_pb(list_a, list_b, 'a');
// 	}
// 	else if (b < a && b < c && b < d)
// 	{
// 		ft_sa_sb_ss(list_a, list_b, 'a');
// 		ft_pa_pb(list_a, list_b, 'b');
// 		ft_sort_for_three(list_a, list_b);
// 		ft_pa_pb(list_a, list_b, 'a');
// 	}
// 	else if (c < a && c < b && c < d)
// 	{
// 		ft_rra_rrb_rrr(list_a, list_b, 'a');
// 		ft_rra_rrb_rrr(list_a, list_b, 'a');
// 		ft_pa_pb(list_a, list_b, 'b');
// 		ft_sort_for_three(list_a, list_b);
// 		ft_pa_pb(list_a, list_b, 'a');
// 	}
// 	else if (d < a && d < b && d < c)
// 	{
// 		ft_rra_rrb_rrr(list_a, list_b, 'a');
// 		ft_pa_pb(list_a, list_b, 'b');
// 		ft_sort_for_three(list_a, list_b);
// 		ft_pa_pb(list_a, list_b, 'a');
// 	}
// }

void	help_sort_4_4(t_list **list_a, t_list **list_b, int i)
{
	if (i == 0)
		ft_pa_pb(list_a, list_b, 'b');
	else if (i == 1)
	{
		ft_sa_sb_ss(list_a, list_b, 'a');
		ft_pa_pb(list_a, list_b, 'b');
	}
	else if (i == 2)
	{
		ft_rra_rrb_rrr(list_a, list_b, 'a');
		ft_rra_rrb_rrr(list_a, list_b, 'a');
		ft_pa_pb(list_a, list_b, 'b');
	}
	else if (i == 3)
	{
		ft_rra_rrb_rrr(list_a, list_b, 'a');
		ft_pa_pb(list_a, list_b, 'b');
	}
}

void	sort_for_four(t_list **list_a, t_list **list_b, int argc)
{
	int		i;
	t_list *head;

	i = 0;
	while (head->index != argc - 1)
	{
		head = head->next;
		i++;
	}
	help_sort_4_4(list_a, list_b, i);
	ft_sort_for_three(list_a, list_b);
	ft_pa_pb(list_a, list_b, 'a');
}

