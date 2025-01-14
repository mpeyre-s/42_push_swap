/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:16:58 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/14 17:03:31 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*current;
	int		temp;

	if (!stack)
		return (1);
	current = *stack;
	if (stack_size(current) < 2)
		return (1);
	temp = current->nb;
	current->nb = current->next->nb;
	current->next->nb = temp;
	return (0);
}

int	swap_a(t_stack **stack_a)
{
	int	result;

	result = swap(stack_a);
	if (!result)
		ft_printf("sa\n");
	return (result);
}

int	swap_b(t_stack **stack_b)
{
	int	result;

	result = swap(stack_b);
	if (!result)
		ft_printf("sb\n");
	return (result);
}

int	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	result;

	if (!stack_b || !*stack_b)
		return (1);
	result = swap(stack_a) + swap(stack_b);
	if (!result)
		ft_printf("ss\n");
	return (result);
}
