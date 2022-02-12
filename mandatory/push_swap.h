/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:53:40 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/02/11 01:09:49 by daniilvoron      ###   ########.fr       */
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
}	t_list;

//ft_atoi
int			ft_atoi(const char *str);
static int	min_max(unsigned long long int num, int min, const char *str);
//check
void		ft_double(int argc, char **argv);
//swap and push
void		ft_swap(t_list **list);
void		ft_sa_sb_ss(t_list **list_a, t_list **list_b, char c);
void		ft_push(t_list **list_out, t_list **list_in);
void		ft_pa_pb(t_list **list_a, t_list **list_b, char c);
//reverse and rotate
void		ft_rotate(t_list **list);
void		ft_ra_rb_rr(t_list **list_a, t_list **list_b, char c);
void		ft_reverse_rotate(t_list **list);
void		ft_rra_rrb_rrr(t_list **list_a, t_list **list_b, char c);
//sort
void		ft_sort(t_list **list_a, t_list **list_b, int argc);
void		ft_sort_for_three(t_list **list_a, t_list **list_b);
void		ft_sort_for_two(t_list **list_a, t_list **list_b);
void		ft_sort_for_four(t_list **list_a, t_list **list_b);
void		sort_for_four(t_list **list_a, t_list **list_b, int argc);

#endif
