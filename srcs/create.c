/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:38:48 by ppatel            #+#    #+#             */
/*   Updated: 2017/03/14 20:39:01 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ft_stack_lstdel(t_ilist **alst)
{
	t_ilist		*cur;
	t_ilist		*next;

	cur = *alst;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*alst = NULL;
}

void			ft_add_stack_elem(t_ilist **start, t_ilist *new)
{
	if (*start)
		new->next = *start;
	*start = new;
}

t_ilist			*ft_create_stack_elem(int n)
{
	t_ilist		*new;

	if (!(new = (t_ilist *)malloc(sizeof(t_ilist))))
		return (NULL);
	new->data = n;
	new->next = NULL;
	return (new);
}

int				read_int(t_ilist **a, char *str)
{
	int			i;
	char		**tab;
	t_ilist		*new;

	i = 0;
	if (!(tab = ft_strsplit(str, ' ')))
		return (0);
	while (tab[i])
		i++;
	while (--i >= 0)
	{
		if (!check_arg(tab[i], *a))
		{
			ft_putendl("Error");
			return (0);
		}
		new = ft_create_stack_elem(ft_atoi(tab[i]));
		ft_add_stack_elem(a, new);
	}
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (1);
}

int				read_arg(t_ilist **a, int argc, char **argv, int i)
{
	t_ilist		*new;

	while (argc > i)
	{
		if (!check_arg(argv[argc - 1], *a))
		{
			ft_putendl("Error");
			return (0);
		}
		new = ft_create_stack_elem(ft_atoi(argv[argc - 1]));
		ft_add_stack_elem(a, new);
		argc--;
	}
	return (1);
}
