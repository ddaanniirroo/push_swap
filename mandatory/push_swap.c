/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:53:07 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/02/15 20:49:32 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_arr(int *arr, int argc)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 0;
	while (j < argc - 2)
	{
		while (i < (argc - 1) - j - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				nb = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = nb;
			}
			i++;
		}
		j++;
		i = 0;
	}
}

t_list	*create_list(long int i)
{
	t_list	*el;

	el = malloc(sizeof(t_list));
	if (el == NULL)
		return (0);
	el->data = i;
	el->next = NULL;
	return (el);
}

void	put_back(t_list **list, long int i)
{
	t_list	*new_el;
	t_list	*tmp;

	if (*list)
	{
		new_el = create_list(i);
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_el;
	}
	else
		*list = create_list(i);
}

void	ft_create(int *arr, t_list **list_a, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		arr[i] = ft_atoi(argv[j]);
		put_back(list_a, arr[i]);
		i++;
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		*arr;

	if (argc <= 2)
		exit(1);
	list_b = NULL;
	arr = malloc(sizeof(char *) * (argc - 1));
	if (arr == NULL)
		return (0);
	ft_create(arr, &list_a, argc, argv);
	ft_sort_arr(arr, argc);
	ft_double(argc, argv, &list_a);
	ft_check_sort(&list_a, argc);
	ft_index(arr, argc, &list_a);
	ft_sort(&list_a, &list_b, argc);
	free(arr);
	ft_free_list(&list_a);
}
