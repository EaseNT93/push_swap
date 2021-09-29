/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:53:19 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 18:14:39 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_config *cfg)
{
	if (cfg->len_a <= 1)
		return ;
	if (cfg->len_a < 6)
		short_sort(cfg);
	else
		while (cfg->a && cfg->a->next && cfg->len_a-- && cfg->len_b++ > -1)
			push(&cfg->a, &cfg->b, 'b');
	final_sort(cfg);
}

void	short_sort(t_config *cfg)
{
	int	len;
	int	el1;
	int	el2;
	int	el3;

	len = cfg->len_a;
	while (len > 3 && len-- && cfg->len_a-- && cfg->len_b++ >= 0)
		push(&cfg->a, &cfg->b, 'b');
	if (len == 2)
		swap(&cfg->a, 'a');
	else
	{
		el1 = cfg->a->num;
		el2 = cfg->a->next->num;
		el3 = cfg->a->next->next->num;
		if ((el1 > el2) + (el2 > el3) + (el3 > el1) == 2)
			swap(&cfg->a, 'a');
	}
}

void	final_sort(t_config *cfg)
{
	t_stack	*tmp;
	int		step;

	while (cfg->b)
		elem_to_a(cfg);
	check_sort(cfg);
	tmp = cfg->a;
	step = 1;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			break ;
		tmp = tmp->next;
		step++;
	}
	if (step <= cfg->len_a / 2)
		while (step--)
			rotate(&cfg->a, 'a');
	else
		while (step++ < cfg->len_a)
			rev_rotate(&cfg->a, 'a');
}

void	elem_to_a(t_config *cfg)
{
	t_stack	*tmp;
	t_step	tmp_step;

	tmp = cfg->b;
	tmp_step.rb = 0;
	tmp_step.rrb = cfg->len_b;
	cfg->step.sum = 99999999999;
	while (tmp)
	{
		tmp_step.ra = find_place(cfg, tmp->num);
		find_way(cfg, &tmp_step);
		tmp = tmp->next;
		tmp_step.rb++;
		tmp_step.rrb--;
	}
	leadup(cfg);
}
