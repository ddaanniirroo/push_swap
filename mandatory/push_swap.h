/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:53:40 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/02/04 18:58:52 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
} t_list;

//ft_atoi
int			ft_atoi(const char *str);
static int	min_max(unsigned long long int num, int min, const char *str);

#endif
