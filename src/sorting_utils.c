/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 22:01:07 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 20:09:14 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_place(t_config *cfg, int num)
{
	t_stack	*tmp;
	int		step;
	int		i;
	int		d;

	tmp = cfg->a;
	i = 0;
	d = 0;
	step = 0;
	while (tmp)
	{
		if ((tmp->num - num < d && d <= 0) || \
		((tmp->num - num <= d || d <= 0) && tmp->num - num > 0))
		{
			step = i;
			d = tmp->num - num;
		}
		tmp = tmp->next;
		i++;
	}
	return (step);
}

void	find_way(t_config *cfg, t_step *step)
{
	int	step_rr;
	int	step_rrr;

	step->rra = cfg->len_a - step->ra;
	step_rr = max_value(step->ra, step->rb);
	step_rrr = max_value(step->rra, step->rrb);
	if (step_rr < cfg->step.sum)
		update_way(cfg, step, step_rr, 0);
	if (step_rrr < cfg->step.sum)
		update_way(cfg, step, step_rrr, 1);
	if (step->ra + step->rrb < cfg->step.sum)
		update_way(cfg, step, step->ra + step->rrb, 2);
	if (step->rra + step->rb < cfg->step.sum)
		update_way(cfg, step, step->rra + step->rb, 3);
}

int	max_value(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

void	update_way(t_config *cfg, t_step *step, int step_sum, int sort_way)
{
	cfg->step.ra = step->ra;
	cfg->step.rb = step->rb;
	cfg->step.rra = step->rra;
	cfg->step.rrb = step->rrb;
	cfg->step.sum = step_sum;
	cfg->sort_way = sort_way;
}

void	leadup(t_config *cfg)
{
	while (cfg->sort_way == 0 && cfg->step.ra > 0 && cfg->step.rb > 0)
	{
		double_rotate(&cfg->a, &cfg->b, 1);
		cfg->step.ra--;
		cfg->step.rb--;
	}
	while (cfg->sort_way == 1 && cfg->step.rra > 0 && cfg->step.rrb > 0)
	{
		doub_rev_rotate(&cfg->a, &cfg->b, 1);
		cfg->step.rra--;
		cfg->step.rrb--;
	}
	while ((cfg->sort_way == 0 || cfg->sort_way == 2) && cfg->step.ra-- > 0)
		rotate(&cfg->a, 'a');
	while ((cfg->sort_way == 1 || cfg->sort_way == 3) && cfg->step.rra-- > 0)
		rev_rotate(&cfg->a, 'a');
	while ((cfg->sort_way == 0 || cfg->sort_way == 3) && cfg->step.rb-- > 0)
		rotate(&cfg->b, 'b');
	while ((cfg->sort_way == 1 || cfg->sort_way == 2) && cfg->step.rrb-- > 0)
		rev_rotate(&cfg->b, 'b');
	push(&cfg->b, &cfg->a, 'a');
	cfg->len_a++;
	cfg->len_b--;
}
