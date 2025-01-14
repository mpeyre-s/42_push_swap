/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:10:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/14 15:02:18 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include ".libft/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

// main.c
int		init_stack(t_stack **stack_a, size_t ac, char **av);
int		sort_radix(t_stack **stack_a, t_stack **stack_b);

// utils.c
void	print_stacks(t_stack **stack_a, t_stack **stack_b);
size_t	stack_size(t_stack *stack);
void	fill_stack(t_stack **stack, int value);

// swap.c
int		swap(t_stack **stack);
int		swap_swap(t_stack **stack_a, t_stack **stack_b);

#endif
