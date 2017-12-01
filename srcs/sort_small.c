/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:09:19 by ppatel            #+#    #+#             */
/*   Updated: 2017/03/23 18:09:29 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		sort_a(t_stack *stack)
{
	if (!stack->a)
		pa(stack, stack->i);
	else if (!stack->a->next)
		pa(stack, stack->i);
	else if ((stack->b->data < stack->a->data && stack->b->data >
		stack->alast->data) || ((stack->b->data < stack->a->data
			|| stack->b->data > stack->alast->data)
		&& stack->alast->data == stack->alarge->data))
		pa(stack, stack->i);
	else
	{
		rra(stack, stack->i);
		sort_a(stack);
	}
}

static void		sort_last(t_stack *stack)
{
	if (stack->alast == stack->alarge)
		return ;
	else
	{
		if (get_pos(stack->a, stack->alarge) > stack->len / 2)
			rra(stack, stack->i);
		else
			ra(stack, stack->i);
		sort_last(stack);
	}
}

static void		sort_b(t_stack *stack)
{
	if (stack->b->next)
	{
		if (stack->b->data < stack->blast->data)
			rb(stack, stack->i);
		if (stack->b->data < stack->b->next->data)
			sb(stack, stack->i);
	}
}

void			sort_small(t_stack *stack)
{
	while (check_ifsorted(stack->a, 0) == -1)
		if (stack->a->data > stack->a->next->data
			&& stack->a->data > stack->alast->data)
			ra(stack, stack->i);
		else if (stack->a->data < stack->a->next->data
			&& stack->a->data > stack->alast->data)
			rra(stack, stack->i);
		else if (stack->a->data > stack->a->next->data)
			sa(stack, stack->i);
		else
		{
			pb(stack, stack->i);
			sort_b(stack);
		}
	while (stack->b)
		sort_a(stack);
	sort_last(stack);
}
