/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:57:38 by ppatel            #+#    #+#             */
/*   Updated: 2017/02/16 15:57:42 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ra(t_stack *stack, int i)
{
	t_ilist		*tmp;

	if (!stack->a || !stack->a->next)
		return (-1);
	stack->alast = stack->a;
	tmp = stack->a->next;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = stack->a;
	stack->a = stack->a->next;
	tmp->next->next = NULL;
	tmp = NULL;
	if (i != 0)
	{
		ft_putendl("ra");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}

int		rb(t_stack *stack, int i)
{
	t_ilist		*tmp;

	if (!stack->b || !stack->b->next)
		return (-1);
	stack->blast = stack->b;
	tmp = stack->b->next;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = stack->b;
	stack->b = stack->b->next;
	tmp->next->next = NULL;
	if (i != 0)
	{
		ft_putendl("rb");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}

int		rr(t_stack *stack, int i)
{
	if (ra(stack, 0) == -1 && rb(stack, 0) == -1)
		return (-1);
	if (i != 0)
	{
		ft_putendl("rr");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}
