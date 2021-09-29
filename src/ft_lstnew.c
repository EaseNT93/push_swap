/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:42:17 by dpants            #+#    #+#             */
/*   Updated: 2021/08/11 16:02:47 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_lstnew(int	num)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (NULL == elem)
		return (NULL);
	elem->num = num;
	elem->next = NULL;
	return (elem);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}
