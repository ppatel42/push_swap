/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:55:49 by ppatel            #+#    #+#             */
/*   Updated: 2017/02/16 15:57:22 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_opfunc(char *line, t_stack *stack)
{
	if (ft_strcmp(line, "sa") == 0)
		return (sa(stack, 0));
	else if (ft_strcmp(line, "sb") == 0)
		return (sb(stack, 0));
	else if (ft_strcmp(line, "ss") == 0)
		return (ss(stack, 0));
	else if (ft_strcmp(line, "pa") == 0)
		return (pa(stack, 0));
	else if (ft_strcmp(line, "pb") == 0)
		return (pb(stack, 0));
	else if (ft_strcmp(line, "ra") == 0)
		return (ra(stack, 0));
	else if (ft_strcmp(line, "rb") == 0)
		return (rb(stack, 0));
	else if (ft_strcmp(line, "rr") == 0)
		return (rr(stack, 0));
	else if (ft_strcmp(line, "rra") == 0)
		return (rra(stack, 0));
	else if (ft_strcmp(line, "rrb") == 0)
		return (rrb(stack, 0));
	else if (ft_strcmp(line, "rrr") == 0)
		return (rrr(stack, 0));
	else
		return (-2);
}

static void		checker(t_ilist *a)
{
	char		*line;
	t_stack		stack;

	stack.a = a;
	stack.b = NULL;
	while (get_next_line(0, &line))
	{
		if (check_opfunc(line, &stack) == -2)
		{
			ft_putendl("Error");
			ft_strdel(&line);
			return ;
		}
		ft_strdel(&line);
	}
	if (stack.b || (check_ifsorted(stack.a, 0) == -1))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	ft_stack_lstdel(&stack.a);
	ft_stack_lstdel(&stack.b);
}

int				main(int argc, char **argv)
{
	t_ilist		*a;

	a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (read_int(&a, argv[1]) == 0)
			return (0);
	}
	else if (read_arg(&a, argc, argv, 1) == 0)
		return (0);
	checker(a);
	return (0);
}
