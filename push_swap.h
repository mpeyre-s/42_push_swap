/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeyre-s <mpeyre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:10:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/20 14:30:48 by mpeyre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include ".libft/libft.h"

typedef struct s_stack
{
	int				nb;
	size_t			order;
	int				seen;
	struct s_stack	*next;
}				t_stack;

// main.c
int		init_stack(t_stack **stack_a, size_t ac, char **av, char type);
int		get_order(t_stack **stack_a);
int		print_error(t_stack **stack_a, t_stack **stack_b);

// sorting.c
void	sorting(t_stack **stack_a, t_stack **stack_b, int max);
void	sorting_three(t_stack **stack_a, int max);
void	sorting_five(t_stack **stack_a, t_stack **stack_b, int max);
int		is_decrease(t_stack **a, t_stack **b);
int		is_sorted(t_stack **stack_a);

// radix.c
void	sort_radix(t_stack **stack_a, t_stack **stack_b, int max);
int		process_bits(t_stack **stack_a, t_stack **stack_b, int i, int size);
int		check_b(t_stack **stack_a, t_stack **stack_b, int i, int size);

// utils.c
size_t	stack_size(t_stack *stack);
void	fill_stack(t_stack **stack, int value);
int		check_double(t_stack **stack_a);
int		find_min(t_stack *stack);

// swap.c
int		swap_a(t_stack **stack);
int		swap_b(t_stack **stack);
int		swap_swap(t_stack **stack_a, t_stack **stack_b);

// push.c
int		push_a(t_stack **stack_a, t_stack **stack_b);
int		push_b(t_stack **stack_a, t_stack **stack_b);

// rotate.c
int		rotate_a(t_stack **stack_a);
int		rotate_b(t_stack **stack_b);
int		rotate_rotate(t_stack **stack_a, t_stack **stack_b);

// rrotate.c
int		reverse_rotate_a(t_stack **stack_a);
int		reverse_rotate_b(t_stack **stack_b);
int		reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);

// ft_atoi_overflow.c
int		ft_atoi_overflow(char *str);

// iwanttobreakfree.c
int		free_args_stacks(int ac, char **args, t_stack **a, t_stack **b);
int		free_args(int ac, char **args);
void	free_stack(t_stack **stack);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);
#endif
