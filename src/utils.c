/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:27:50 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 20:28:09 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] && (argv[0] == '-' || ft_isdigit(argv[i])))
		i++;
	if (argv[i])
	{
		write(1, "Wrong argument\n", 15);
		exit(0);
	}
	return (1);
}

int	check_repeat(t_stack *list, int num)
{
	while (list)
	{
		if (list->num == num)
			return (1);
		list = list->next;
	}
	return (0);
}
