/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:10:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/16 14:11:38 by mathispeyre      ###   ########.fr       */
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
int		init_stack(t_stack **stack_a, size_t ac, char **av);
int		get_order(t_stack **stack_a);
void	free_args(int ac, int i, char **args);
int		print_error(void);

//radix.c
void	sort_radix(t_stack **stack_a, t_stack **stack_b, int max);
int		process_bits(t_stack **stack_a, t_stack **stack_b, int i, int size);
int		check_b(t_stack **stack_a, t_stack **stack_b, int i, int size);

// utils.c
void	print_stacks(t_stack **stack_a, t_stack **stack_b);
size_t	stack_size(t_stack *stack);
void	fill_stack(t_stack **stack, int value);
int		empty_b(t_stack **stack_a, t_stack **stack_b);

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
#endif
