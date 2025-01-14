/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:08:44 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/14 16:12:00 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_a(t_stack **stack_a, t_stack **stack_b)
{
	return (push(stack_b, stack_a));
}

int	push_b(t_stack **stack_a, t_stack **stack_b)
{
	return (push(stack_a, stack_b));
}

int	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!src || !*src)
		return (1);
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	return (0);
}

