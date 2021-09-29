/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:39:31 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 20:35:24 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack **stack, char c)
{
	int	tmp_num;

	if (*stack && (*stack)->next)
	{
		tmp_num = (*stack)->next->num;
		(*stack)->next->num = (*stack)->num;
		(*stack)->num = tmp_num;
	}
	if (c)
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	double_swap(t_stack **a, t_stack **b, int f)
{
	swap(a, 0);
	swap(b, 0);
	if (f)
		write(1, "ss\n", 3);
}

void	push(t_stack **stack_out, t_stack **stack_in, char c)
{
	t_stack	*tmp_num;

	if (*stack_out)
	{
		tmp_num = (*stack_out);
		(*stack_out) = tmp_num->next;
		tmp_num->next = NULL;
		ft_lstadd_front(stack_in, tmp_num);
	}
	if (c)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
