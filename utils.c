/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:56:46 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/16 14:12:37 by mathispeyre      ###   ########.fr       */
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

void	print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	size_t	i;

	i = 0;
	current_a = *stack_a;
	current_b = *stack_b;
	printf("Stack A : ");
	while (i < stack_size(*stack_a))
	{
		printf("%d -> ", current_a->nb);
		current_a = current_a->next;
		i++;
	}
	i = 0;
	printf("NULL\n");
	printf("Stack B : ");
	while (i < stack_size(*stack_b))
	{
		printf("%d -> ", current_b->nb);
		current_b = current_b->next;
		i++;
	}
	printf("NULL\n--------------------------------------------------\n");
}
