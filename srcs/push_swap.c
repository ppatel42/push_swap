/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:01:43 by ppatel            #+#    #+#             */
/*   Updated: 2017/03/23 18:50:35 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		part(int *a, int start, int end)
{
	int		i;
	int		j;
	int		tmp;
	int		pivot;

	pivot = a[start];
	i = start;
	j = end;
	while (1)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

void	sort_array(int *a, int start, int end)
{
	int		p;

	if (start < end)
	{
		p = part(a, start, end);
		sort_array(a, start, p);
		sort_array(a, p + 1, end);
	}
}

void	set_array(t_stack *stack)
{
	int		*a;
	int		i;
	t_ilist	*tmp;

	i = 0;
	tmp = stack->a;
	a = (int *)malloc(sizeof(int) * stack->len);
	while (tmp)
	{
		a[i++] = tmp->data;
		tmp = tmp->next;
	}
	sort_array(a, 0, stack->len - 1);
	stack->array = a;
}

void	push_swap(t_ilist *a, int i)
{
	t_stack		stack;

	stack.a = a;
	stack.b = NULL;
	stack.alast = ft_lstlast(stack.a);
	stack.blast = NULL;
	stack.alarge = ft_lstlarge(stack.a);
	stack.blarge = NULL;
	stack.nsize = 0;
	stack.nlast = stack.alast;
	stack.i = i;
	stack.len = ft_stacksize(stack.a);
	set_array(&stack);
	if (check_ifsorted(stack.a, 0) == -1)
	{
		if (stack.len <= 10)
			sort_small(&stack);
		else
			sort_large_a(&stack, stack.len / 2, stack.len);
	}
	ft_stack_lstdel(&stack.a);
	free(stack.array);
}

int		main(int argc, char **argv)
{
	int			i;
	t_ilist		*a;

	if (argc < 2)
		return (0);
	i = 1;
	if (argv[1][0] == '-' && argv[1][1] == 'v' && !argv[1][2])
		i = 2;
	a = NULL;
	if ((i == 1 && argc == 2) || (i == 2 && argc == 3))
	{
		if (read_int(&a, i == 1 ? argv[1] : argv[2]) == 0)
			return (0);
	}
	else if (read_arg(&a, argc, argv, i) == 0)
		return (0);
	push_swap(a, i);
	return (0);
}
