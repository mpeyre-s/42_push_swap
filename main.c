/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:29:06 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/15 10:19:57 by mathispeyre      ###   ########.fr       */
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

int	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	reverse_rotate_rotate(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (init_stack(&stack_a, ac, av))
		return (1);
	sort_radix(&stack_a, &stack_b);
	return (0);
}
