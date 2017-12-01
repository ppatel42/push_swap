/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:39:18 by ppatel            #+#    #+#             */
/*   Updated: 2017/03/14 20:39:21 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ilist		*ft_lstlast(t_ilist *a)
{
	while (a && a->next)
		a = a->next;
	return (a);
}

t_ilist		*ft_lstlarge(t_ilist *a)
{
	t_ilist		*alarge;

	alarge = a;
	while (a)
	{
		if (a->data > alarge->data)
			alarge = a;
		a = a->next;
	}
	return (alarge);
}

int			get_pos(t_ilist *lst, t_ilist *elem)
{
	int		i;

	i = 1;
	while (lst && lst != elem)
	{
		lst = lst->next;
		i++;
	}
	if (!lst)
		return (0);
	return (i);
}

int			ft_stacksize(t_ilist *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void		print_stack(t_stack stack)
{
	ft_putstr("A :");
	while (stack.a)
	{
		ft_putchar(' ');
		ft_putnbr(stack.a->data);
		stack.a = stack.a->next;
	}
	ft_putstr("\nB :");
	while (stack.b)
	{
		ft_putchar(' ');
		ft_putnbr(stack.b->data);
		stack.b = stack.b->next;
	}
	ft_putstr("\n\n");
}
