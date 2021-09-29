/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:28:37 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 19:28:53 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_next_line(char **line)
{
	int		i;
	int		read_ret;
	char	buf;

	i = 0;
	*line = malloc(1000000);
	if (*line == NULL && read(0, &buf, 0) < 0)
		return (-1);
	read_ret = read(0, &buf, 1);
	while (read_ret == 1 && buf != '\n')
	{
		(*line)[i++] = buf;
		read_ret = read(0, &buf, 1);
	}
	(*line)[i] = '\0';
	return (read_ret);
}
