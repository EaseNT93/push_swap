/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:10:49 by dpants            #+#    #+#             */
/*   Updated: 2021/08/11 14:07:58 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_str_len(char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * len + 1);
	if (NULL == new_str)
		return (NULL);
	while (i < len && start < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_str_count(char *s, char c)
{
	int	i;
	int	f;

	i = 0;
	f = 1;
	while (*s && *s == c)
		s++;
	while (*s)
	{	
		if (f)
		{
			i++;
			f = 0;
		}
		if (*s == c)
		{	
			f = 1;
			while (*s && *s == c)
				s++;
		}
		if (!f)
			s++;
	}
	return (i);
}

char	**ft_free_arr(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		str_count;
	int		i;

	if (!s)
		return (NULL);
	str_count = ft_str_count((char *)s, c);
	array = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (NULL == array)
		return (NULL);
	i = 0;
	while (str_count--)
	{
		while (*s && *s == c)
			s++;
		array[i] = ft_substr(s, 0, ft_str_len((char *)s, c));
		if (NULL == array[i])
			return (ft_free_arr(array));
		s += ft_str_len((char *)s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
