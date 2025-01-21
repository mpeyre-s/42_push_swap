/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:16:57 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/21 12:00:06 by mathispeyre      ###   ########.fr       */
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
		sorting_five(stack_a, stack_b, max);
	else
		sort_radix(stack_a, stack_b, max);
	free_stacks(stack_a, stack_b);
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

void	sorting_five(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	min;
	int	pushed;

	pushed = 0;
	if (is_decrease(stack_a, stack_b))
		return ;
	while (pushed < 2)
	{
		min = find_min(*stack_a);
		while ((*stack_a)->nb != min)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
		pushed++;
	}
	sorting_three(stack_a, max);
	while (*stack_b)
		push_a(stack_a, stack_b);
}

int	is_decrease(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->next && (*a)->next->next
		&& (*a)->next->next->next && (*a)->next->next->next->next)
	{
		if ((*a)->nb > (*a)->next->nb
			&& (*a)->next->nb > (*a)->next->next->nb
			&& (*a)->next->next->nb > (*a)->next->next->next->nb
			&& (*a)->next->next->next->nb > (*a)->next->next->next->next->nb)
		{
			push_b(a, b);
			push_b(a, b);
			rotate_a(a);
			swap_a(a);
			swap_b(b);
			push_a(a, b);
			push_a(a, b);
			rotate_a(a);
			rotate_a(a);
			return (1);
		}
	}
	return (0);
}

int	is_sorted(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current && current->next)
	{
		if (current->nb > current->next->nb)
			return (0);
		current = current->next;
	}
	return (1);
}
