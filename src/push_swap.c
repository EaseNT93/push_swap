/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:22:37 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 20:28:05 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_sort(t_config *cfg)
{	
	t_stack	*tmp;

	tmp = cfg->a;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->num < tmp->next->num)
				tmp = tmp->next;
			else
				return ;
		}
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_config	cfg;
	int			i;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	cfg.a = NULL;
	cfg.b = NULL;
	i = (argc != 2);
	while (argv[i] && check_arg(argv[i]))
	{
		if (check_repeat(cfg.a, ft_atoi(argv[i])))
		{
			write(1, "Repeat in arguments\n", 20);
			exit(0);
		}
		ft_lstadd_back(&cfg.a, ft_lstnew(ft_atoi(argv[i++])));
	}
	check_sort(&cfg);
	cfg.len_a = i - (argc != 2);
	cfg.len_b = 0;
	sort(&cfg);
	return (0);
}
