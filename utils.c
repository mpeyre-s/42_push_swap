/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:56:46 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/14 13:29:20 by mathispeyre      ###   ########.fr       */
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

void	print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	ft_printf("Stack A\n");
	while (current_a)
	{
		ft_printf("%d -> ", current_a->nb);
		current_a = current_a->next;
	}
	ft_printf("NULL\n");
	ft_printf("Stack B\n");
	while (current_b)
	{
		ft_printf("%d -> ", current_b->nb);
		current_b = current_b->next;
	}
	ft_printf("NULL\n--------------------------------------------------\n");
}
