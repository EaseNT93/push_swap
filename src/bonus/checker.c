/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:59:27 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 20:29:36 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_config	cfg;
	int			i;

	if (argc == 1)
		return (0);
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
	get_command(&cfg);
	if (cfg.b || !sort_check(cfg.a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (0);
}

void	get_command(t_config *cfg)
{
	char	*line;
	int		read_ret;

	read_ret = 1;
	while (read_ret)
	{
		read_ret = get_next_line(&line);
		if (read_ret)
			use_command(cfg, line);
		free(line);
	}
}

void	use_command(t_config *cfg, char *line)
{
	if (!ft_strncmp("sa", line, 3))
		swap(&cfg->a, 0);
	else if (!ft_strncmp("sb", line, 3))
		swap(&cfg->b, 0);
	else if (!ft_strncmp("ss", line, 3))
		double_swap(&cfg->a, &cfg->b, 0);
	else if (!ft_strncmp("pa", line, 3))
		push(&cfg->b, &cfg->a, 0);
	else if (!ft_strncmp("pb", line, 3))
		push(&cfg->a, &cfg->b, 0);
	else if (!ft_strncmp("ra", line, 3))
		rotate(&cfg->a, 0);
	else if (!ft_strncmp("rb", line, 3))
		rotate(&cfg->b, 0);
	else if (!ft_strncmp("rr", line, 3))
		double_rotate(&cfg->a, &cfg->b, 0);
	else if (!ft_strncmp("rra", line, 4))
		rev_rotate(&cfg->a, 0);
	else if (!ft_strncmp("rrb", line, 4))
		rev_rotate(&cfg->b, 0);
	else if (!ft_strncmp("rrr", line, 4))
		doub_rev_rotate(&cfg->a, &cfg->b, 0);
	else
		command_error();
}

void	command_error(void)
{
	write(1, "Wrong command\n", 14);
	exit(0);
}

int	sort_check(t_stack *stack)
{	
	t_stack	*tmp;

	tmp = stack;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->num < tmp->next->num)
				tmp = tmp->next;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
