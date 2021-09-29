/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:17:10 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 18:28:43 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	long	n;
	int		s;

	n = 0;
	s = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		str++;
		s = -s;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		n = (*str - '0') + n * 10;
		str++;
	}
	if (n * s > 2147483647 || n * s < -2147483648)
	{
		write(1, "More/less than INT\n", 19);
		exit(0);
	}
	return (n * s);
}
