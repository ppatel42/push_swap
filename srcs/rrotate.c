/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:57:46 by ppatel            #+#    #+#             */
/*   Updated: 2017/02/16 15:57:48 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rra(t_stack *stack, int i)
{
	t_ilist		*tmp;

	if (!stack->a || !stack->a->next)
		return (-1);
	tmp = stack->a;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = stack->a;
	stack->a = tmp->next;
	tmp->next = NULL;
	stack->alast = tmp;
	if (i != 0)
	{
		ft_putendl("rra");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}

int		rrb(t_stack *stack, int i)
{
	t_ilist		*tmp;

	if (!stack->b || !stack->b->next)
		return (-1);
	tmp = stack->b;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = stack->b;
	stack->b = tmp->next;
	tmp->next = NULL;
	stack->blast = tmp;
	if (i != 0)
	{
		ft_putendl("rrb");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}

int		rrr(t_stack *stack, int i)
{
	if (rra(stack, 0) == -1 && rrb(stack, 0) == -1)
		return (-1);
	if (i != 0)
	{
		ft_putendl("rrr");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}
