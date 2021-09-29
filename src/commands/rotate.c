/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:10:38 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 20:08:19 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack **stack, char c)
{
	t_stack	*tmp_num;

	if (*stack && (*stack)->next)
	{
		tmp_num = (*stack);
		(*stack) = tmp_num->next;
		tmp_num->next = NULL;
		ft_lstadd_back(stack, tmp_num);
	}
	if (c)
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	double_rotate(t_stack **a, t_stack **b, int f)
{
	rotate(a, 0);
	rotate(b, 0);
	if (f)
		write(1, "rr\n", 3);
}

void	rev_rotate(t_stack **stack, char c)
{
	t_stack	*tmp_stack;

	if ((*stack) && (*stack)->next)
	{
		tmp_stack = (*stack);
		while (tmp_stack->next->next)
			tmp_stack = tmp_stack->next;
		ft_lstadd_front(stack, tmp_stack->next);
		tmp_stack->next = NULL;
	}
	if (c)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	doub_rev_rotate(t_stack **a, t_stack **b, int f)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	if (f)
		write(1, "rrr\n", 4);
}
