/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:51:45 by ppatel            #+#    #+#             */
/*   Updated: 2017/03/23 17:51:51 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	partition_b(t_stack *stack, int p, int len, int *i)
{
	int		j;

	j = 0;
	while (*i != len / 2)
	{
		if (stack->b->data > stack->array[p - 1])
		{
			pa(stack, stack->i);
			(*i)++;
		}
		else if (stack->b->data <= stack->array[p - 1])
		{
			rb(stack, stack->i);
			j++;
		}
	}
	if (len != stack->len / 2)
		while (j > 0)
		{
			rrb(stack, stack->i);
			j--;
		}
}

void	sort_large_b(t_stack *stack, int p, int len)
{
	int		i;

	i = 0;
	partition_b(stack, p, len, &i);
	if (check_ifsorted_n(stack->b, 1, len - i) == -1)
	{
		if (len - i > 2)
			sort_large_b(stack, p - ((len - i) / 2), len - i);
		else if (len - i == 2)
			sb(stack, stack->i);
	}
	if (check_ifsorted_n(stack->a, 0, i) == -1)
	{
		if (i > 2)
			sort_large_a(stack, p + (i / 2), i);
		else if (i == 2)
			sa(stack, stack->i);
	}
	while (i > 0)
	{
		pb(stack, stack->i);
		i--;
	}
}

void	partition_a(t_stack *stack, int p, int len, int *i)
{
	int		j;

	j = 0;
	while (*i != len / 2)
	{
		if (stack->a->data <= stack->array[p - 1])
		{
			pb(stack, stack->i);
			(*i)++;
		}
		else if (stack->a->data > stack->array[p - 1])
		{
			ra(stack, stack->i);
			j++;
		}
	}
	if (len != stack->len && check_ifsorted(stack->a, 0) == -1)
		while (j > 0)
		{
			rra(stack, stack->i);
			j--;
		}
}

void	sort_large_a(t_stack *stack, int p, int len)
{
	int		i;

	i = 0;
	partition_a(stack, p, len, &i);
	if (check_ifsorted_n(stack->b, 1, i) == -1)
	{
		if (i > 2)
			sort_large_b(stack, p - (i / 2), i);
		else if (i == 2)
			sb(stack, stack->i);
	}
	if (check_ifsorted_n(stack->a, 0, len - i) == -1)
	{
		if (len - i > 2)
			sort_large_a(stack, p + ((len - i) / 2), len - i);
		else if (len - i == 2)
			sa(stack, stack->i);
	}
	while (i > 0)
	{
		pa(stack, stack->i);
		i--;
	}
}
