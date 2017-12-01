/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:57:53 by ppatel            #+#    #+#             */
/*   Updated: 2017/02/16 15:58:03 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sa(t_stack *stack, int i)
{
	int		tmp;

	if (!stack->a || !stack->a->next)
		return (-1);
	tmp = stack->a->data;
	stack->a->data = stack->a->next->data;
	stack->a->next->data = tmp;
	if (i != 0)
	{
		ft_putendl("sa");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}

int		sb(t_stack *stack, int i)
{
	int		tmp;

	if (!stack->b || !stack->b->next)
		return (-1);
	tmp = stack->b->data;
	stack->b->data = stack->b->next->data;
	stack->b->next->data = tmp;
	if (i != 0)
	{
		ft_putendl("sb");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}

int		ss(t_stack *stack, int i)
{
	if (sa(stack, 0) == -1 && sb(stack, 0) == -1)
		return (-1);
	if (i != 0)
	{
		ft_putendl("ss");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}

int		pa(t_stack *stack, int i)
{
	t_ilist		*tmp;

	if (!stack->b)
		return (-1);
	tmp = stack->b;
	stack->b = stack->b->next;
	if (!stack->a)
		tmp->next = NULL;
	ft_add_stack_elem(&(stack->a), tmp);
	stack->alarge = ft_lstlarge(stack->a);
	stack->blarge = ft_lstlarge(stack->b);
	if (i != 0)
	{
		ft_putendl("pa");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}

int		pb(t_stack *stack, int i)
{
	t_ilist		*tmp;

	if (!stack->a)
		return (-1);
	tmp = stack->a;
	stack->a = stack->a->next;
	if (!stack->b)
		tmp->next = NULL;
	ft_add_stack_elem(&(stack->b), tmp);
	if (!stack->blast)
		stack->blast = ft_lstlast(stack->b);
	stack->alarge = ft_lstlarge(stack->a);
	stack->blarge = ft_lstlarge(stack->b);
	if (i != 0)
	{
		ft_putendl("pb");
		if (i == 2)
			print_stack(*stack);
	}
	return (0);
}
