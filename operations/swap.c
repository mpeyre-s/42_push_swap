/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:16:58 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/14 15:00:09 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*current;
	int		temp;

	current = *stack;
	if (stack_size(current) < 2)
		return (1);
	temp = current->nb;
	current->nb = current->next->nb;
	current->next->nb = temp;
	return (0);
}

int	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	return (0);
}
