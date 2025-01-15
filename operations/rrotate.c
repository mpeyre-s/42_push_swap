/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:33:39 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/15 10:16:08 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*prev;

	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
	return (0);
}

int	reverse_rotate_a(t_stack **stack_a)
{
	int	result;

	if (!stack_a)
		return (1);
	result = reverse_rotate(stack_a);
	if (!result)
		ft_printf("rra\n");
	return (result);
}

int	reverse_rotate_b(t_stack **stack_b)
{
	int	result;

	if (!stack_b)
		return (1);
	result = reverse_rotate(stack_b);
	if (!result)
		ft_printf("rrb\n");
	return (result);
}

int	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	int	result;

	if (!stack_b || !*stack_b)
		return (1);
	result = reverse_rotate(stack_a) + reverse_rotate(stack_b);
	if (!result)
		ft_printf("rrr\n");
	return (result);
}
