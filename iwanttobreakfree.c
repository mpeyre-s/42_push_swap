/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iwanttobreakfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeyre-s <mpeyre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:30:16 by mpeyre-s          #+#    #+#             */
/*   Updated: 2025/01/20 14:34:31 by mpeyre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_args_stacks(int ac, char **args, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		free(args[i]);
		i++;
	}
	free(args);
	print_error(a, b);
	return (0);
}

int	free_args(int ac, char **args)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
