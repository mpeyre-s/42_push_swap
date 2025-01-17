/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:16:57 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/17 17:19:35 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		rotate_a(stack_a);
	else if (size == 3)
		sorting_three(stack_a, max);
	else if (size > 3 && size <= 5)
		sorting_five(stack_a, stack_b, size, max);
	else
		sort_radix(stack_a, stack_b, max);
}

void	sorting_three(t_stack **stack_a, int max)
{
	if ((*stack_a)->nb == max)
		rotate_a(stack_a);
	else if ((*stack_a)->next->nb == max)
		reverse_rotate_a(stack_a);
	if (((*stack_a)->nb > (*stack_a)->next->nb))
		swap_a(stack_a);
}

void	sorting_five(t_stack **stack_a, t_stack **stack_b, int size, int max)
{
	while (size > 3)
	{
		if ((*stack_a)->nb == max || (*stack_a)->nb == max - 1)
			rotate_a(stack_a);
		else
		{
			push_b(stack_a, stack_b);
			size--;
		}
	}
	sorting_three(stack_a, max - 2);
	while (*stack_b)
	{
		push_a(stack_a, stack_b);
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			swap_a(stack_a);
	}
}
