/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:29:06 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/16 11:22:44 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack **stack_a, size_t ac, char **av)
{
	size_t	i;
	int		value;

	i = 0;
	if (ac == 1)
	{
		ft_printf("Error");
		return (1);
	}
	while (++i < (size_t)ac)
	{
		value = ft_atoi(av[i]);
		if (!value)
		{
			ft_printf("Error");
			return (1);
		}
		fill_stack(stack_a, value);
	}
	return (0);
}

int	get_order(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*min;
	size_t	order;

	order = 0;
	while (order < stack_size(*stack_a))
	{
		current = *stack_a;
		min = NULL;
		while (current)
		{
			if (!current->seen && (!min || current->nb < min->nb))
				min = current;
			current = current->next;
		}
		if (min)
		{
			min->seen = 1;
			min->order = order++;
		}
	}
	return (min->nb);
}
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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int 	max;

	stack_a = NULL;
	stack_b = NULL;
	if (init_stack(&stack_a, ac, av))
		return (1);
	max = get_order(&stack_a);
	sort_radix(&stack_a, &stack_b, max);
	print_stacks(&stack_a, &stack_b);
	return (0);
}
