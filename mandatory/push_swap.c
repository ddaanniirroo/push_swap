/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:53:07 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/02/10 23:18:45 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		*arr;
	int		i = 0;

	list_b = NULL;
	arr = malloc(sizeof(char *) * (argc - 1));
	if (arr == NULL)
		return (0);
	if (argc <= 2)
		exit(1);
	ft_create(arr, &list_a, argc, argv);
	ft_sort_arr(arr, argc);
	ft_double(argc, argv);
	ft_index(arr, argc, &list_a);
	ft_sort_for_three(&list_a, &list_b);
	printf("%d\n", list_a->data);
	printf("%d\n", list_a->next->data);
	printf("%d\n", list_a->next->next->data);
	// while (list_a)
	// {
	// printf("%d\n", list_a->data);
	// list_a=list_a->next;
	// }
	// while (i < argc - 1)
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
}
