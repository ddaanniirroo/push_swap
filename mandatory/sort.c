/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:03:43 by cprester          #+#    #+#             */
/*   Updated: 2022/02/10 23:25:30 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}
