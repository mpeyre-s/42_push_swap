/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:29:06 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/18 16:22:35 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack **stack_a, size_t ac, char **av, char type)
{
	size_t	i;
	int		value;

	i = -1;
	if (type == 'i')
		i = 0;
	if (ac == 1)
		return (1);
	while (++i < (size_t)ac)
	{
		value = ft_atoi(av[i]);
		if (av[i][0] != '0' && !value)
			return (1);
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

int	print_error(void)
{
	ft_putendl_fd("Error", 2);
	return (EXIT_FAILURE);
}

char	**fill_split(char *type, char **av, int *ac)
{
	char	**args;
	size_t	i;

	i = 0;
	args = ft_split(av[1], ' ');
	while (args[i])
		i++;
	*type = 's';
	*ac = (int)i;
	return (args);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	type;

	stack_a = NULL;
	stack_b = NULL;
	type = 'i';
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = fill_split(&type, av, &ac);
		if (!av)
			exit(print_error());
	}
	if (init_stack(&stack_a, ac, av, type))
		exit(print_error());
	if (check_double(&stack_a))
		exit(print_error());
	//print_stacks(&stack_a, &stack_b);
	sorting(&stack_a, &stack_b, get_order(&stack_a));
	//print_stacks(&stack_a, &stack_b);
	return (0);
}
