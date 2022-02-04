/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:09:48 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/02/04 18:10:11 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_max(unsigned long long int num, int min, const char *str)
{
	int	i;

	i = 0;
	if (*str <= '0' && *str >= '9')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 19 || num > 9223372036854775807)
	{
		if (min == 1)
			return (-1);
		else if (min == -1)
			return (0);
	}
	return (min * num);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		a;

	i = 0;
	res = 0;
	a = 1;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		a = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (min_max(res, a, str));
}
