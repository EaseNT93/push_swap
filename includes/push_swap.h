/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:23:43 by dpants            #+#    #+#             */
/*   Updated: 2021/09/28 20:25:44 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //DEL!!!!

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}t_stack;

typedef struct s_step
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	long	sum;
}t_step;

typedef struct s_config
{
	t_stack	*a;
	t_stack	*b;
	t_step	step;
	int		len_a;
	int		len_b;
	int		sort_way;
}t_config;

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_stack	*ft_lstnew(int	num);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

void	swap(t_stack **stack, char c);
void	double_swap(t_stack **a, t_stack **b, int f);
void	push(t_stack **stack_out, t_stack **stack_in, char c);
void	rotate(t_stack **stack, char c);
void	double_rotate(t_stack **a, t_stack **b, int f);
void	rev_rotate(t_stack **stack, char c);
void	doub_rev_rotate(t_stack **a, t_stack **b, int f);

void	sort(t_config *cfg);
int		check_arg(char *argv);
int		check_repeat(t_stack *list, int num);
void	check_sort(t_config *cfg);
void	short_sort(t_config *cfg);
void	final_sort(t_config *cfg);
void	elem_to_a(t_config *cfg);
int		find_place(t_config *cfg, int num);
void	find_way(t_config *cfg, t_step *step);
int		max_value(int num1, int num2);
void	update_way(t_config *cfg, t_step *step, int step_sum, int sort_way);
void	leadup(t_config *cfg);

int		get_next_line(char **line);
void	get_command(t_config *cfg);
void	use_command(t_config *cfg, char *line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	command_error(void);
int		sort_check(t_stack *stack);

#endif