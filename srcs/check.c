/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:36:55 by ppatel            #+#    #+#             */
/*   Updated: 2017/03/14 20:37:05 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				check_ifsorted_n(t_ilist *a, int i, int n)
{
	if (i == 0)
		while (a && a->next && n > 1)
		{
			if (a->data > a->next->data)
				return (-1);
			a = a->next;
			n--;
		}
	else
		while (a && a->next && n > 1)
		{
			if (a->data < a->next->data)
				return (-1);
			a = a->next;
			n--;
		}
	return (0);
}

int				check_ifsorted(t_ilist *a, int i)
{
	if (i == 0)
		while (a && a->next)
		{
			if (a->data > a->next->data)
				return (-1);
			a = a->next;
		}
	else
		while (a && a->next)
		{
			if (a->data < a->next->data)
				return (-1);
			a = a->next;
		}
	return (0);
}

static long		ft_atol(const char *str)
{
	int		i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg > 0)
		nb = -nb;
	return (nb);
}

int				check_arg(char *str, t_ilist *a)
{
	long	nb;

	nb = ft_atol(str);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	while (a)
	{
		if (a->data == nb)
			return (0);
		a = a->next;
	}
	return (1);
}
