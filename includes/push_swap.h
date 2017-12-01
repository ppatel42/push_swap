/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:29:53 by ppatel            #+#    #+#             */
/*   Updated: 2017/03/15 15:16:16 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_ilist
{
	int				data;
	struct s_ilist	*next;
}				t_ilist;
typedef struct	s_stack
{
	t_ilist		*a;
	t_ilist		*b;
	t_ilist		*alast;
	t_ilist		*blast;
	t_ilist		*nlast;
	t_ilist		*alarge;
	t_ilist		*blarge;
	int			*array;
	int			nsize;
	int			i;
	int			len;
}				t_stack;
int				sa(t_stack *stack, int i);
int				sb(t_stack *stack, int i);
int				ss(t_stack *stack, int i);
int				pa(t_stack *stack, int i);
int				pb(t_stack *stack, int i);
int				ra(t_stack *stack, int i);
int				rb(t_stack *stack, int i);
int				rr(t_stack *stack, int i);
int				rra(t_stack *stack, int i);
int				rrb(t_stack *stack, int i);
int				rrr(t_stack *stack, int i);
void			sort_large_b(t_stack *stack, int p, int len);
void			sort_large_a(t_stack *stack, int p, int len);
void			sort_small(t_stack *stack);
int				read_int(t_ilist **a, char *str);
int				read_arg(t_ilist **a, int argc, char **argv, int i);
t_ilist			*ft_create_stack_elem(int n);
void			ft_add_stack_elem(t_ilist **start, t_ilist *new);
void			ft_stack_lstdel(t_ilist **alst);
int				check_arg(char *str, t_ilist *a);
int				check_ifsorted(t_ilist *a, int i);
int				check_ifsorted_n(t_ilist *a, int i, int n);
void			print_stack(t_stack stack);
int				get_pos(t_ilist *lst, t_ilist *elem);
int				ft_stacksize(t_ilist *lst);
t_ilist			*ft_lstlast(t_ilist *a);
t_ilist			*ft_lstlarge(t_ilist *a);

#endif
