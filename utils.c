/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:56:46 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/13 15:50:38 by mathispeyre      ###   ########.fr       */
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

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d -> ", stack->nb);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}
