/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:10:37 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/16 14:16:39 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_bits(t_stack **stack_a, t_stack **stack_b, int i, int size)
{
	while (size--)
	{
		if ((((*stack_a)->order >> i) & 1) == 0)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	return (0);
}

int	check_b(t_stack **stack_a, t_stack **stack_b, int i, int size)
{
	while (size--)
	{
		if ((((*stack_b)->order >> i) & 1) == 0)
			rotate_b(stack_b);
		else if ((((*stack_b)->order >> i) & 1) == 1)
			push_a(stack_a, stack_b);
	}
	return (0);
}

void	sort_radix(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	nb_bits;
	int	i;
	int	size;

	i = 0;
	nb_bits = 0;
	while (max)
	{
		nb_bits++;
		max >>= 1;
	}
	while (i < nb_bits)
	{
		size = stack_size(*stack_a);
		process_bits(stack_a, stack_b, i, size);
		size = stack_size(*stack_b);
		if (i + 1 < nb_bits)
			check_b(stack_a, stack_b, i + 1, size);
		else
		{
			while (*stack_b)
				push_a(stack_a, stack_b);
		}
		i++;
	}
}
