/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:41:14 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/02/14 23:35:10 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(1, "Error!\nHas duplicate!\n", 22);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_sort(t_list **list_a, int argc)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *list_a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			i = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (i == 0)
	{
		write(1, "Already sorted!\n", 16);
		exit (1);
	}
}

void	ft_index(int *arr, int argc, t_list **list_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *list_a;
	while (tmp)
	{
		while (i < argc - 1)
		{
			if (tmp->data == arr[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
		i = 0;
	}
}
