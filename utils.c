/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeyre-s <mpeyre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:56:46 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/20 14:31:05 by mpeyre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->nb = value;
	new_node->order = 0;
	new_node->seen = 0;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

size_t	stack_size(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	check_double(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*checker;

	current = *stack_a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->nb == checker->nb)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->nb;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}
