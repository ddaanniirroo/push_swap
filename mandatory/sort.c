/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:03:43 by cprester          #+#    #+#             */
/*   Updated: 2022/02/12 17:09:19 by cprester         ###   ########.fr       */
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
		ft_sort_for_four(list_a, list_b);
	else if (argc == 6)
		ft_sort_for_five(list_a, list_b);
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

void	ft_sort_for_four(t_list **list_a, t_list **list_b)
{
	while ((*list_a) != NULL)
	{
		if ((*list_a)->index == 0)
		{
			ft_pa_pb(list_a, list_b, 'b');
			break ;
		}
		else
			ft_ra_rb_rr(list_a, list_b, 'a');
	}
	ft_sort_for_three(list_a, list_b);
	ft_pa_pb(list_a, list_b, 'a');
}

// void	ft_sort_for_five(t_list **list_a, t_list **list_b)
// {
// 	while ((*list_a) != NULL)
// 	{
// 		if ((*list_a)->index == 0 || (*list_a)->index == 4)
// 		{
// 			ft_pa_pb(list_a, list_b, 'b');
// 			break ;
// 		}
// 		else
// 			ft_ra_rb_rr(list_a, list_b, 'a');
// 	}
// 	ft_sort_for_three(list_a, list_b);
// 	ft_pa_pb(list_a, list_b, 'a');
// 	ft_ra_rb_rr(list_a, list_b, 'a');
// 	ft_pa_pb(list_a, list_b, 'a');
// }
