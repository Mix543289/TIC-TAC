
#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

typedef void (*t_single_op)(t_stack *);
typedef void (*t_double_op)(t_stack *, t_stack *);

static void add_node(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		exit(EXIT_FAILURE);
	node->value = value;
	node->rank = 0;
	node->next = NULL;
	node->prev = stack->tail;
	if (stack->tail)
		stack->tail->next = node;
	else
		stack->head = node;
	stack->tail = node;
	stack->size++;
}

static void init_stack(t_stack *stack, int *values, int size)
{
	int	i;

	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	i = 0;
	while (i < size)
	{
		add_node(stack, values[i]);
		i++;
	}
}

static void free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	node = stack->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

static int check_stack(t_stack *stack, int *expected, int size)
{
	t_node	*node;
	t_node	*previous;
	int		i;

	node = stack->head;
	previous = NULL;
	i = 0;
	while (node && i < size)
	{
		if (node->value != expected[i] || node->prev != previous)
			return (0);
		previous = node;
		node = node->next;
		i++;
	}
	if (node || i != size || stack->size != size)
		return (0);
	if (stack->tail != previous)
		return (0);
	if (stack->head && stack->head->prev)
		return (0);
	if (stack->tail && stack->tail->next)
		return (0);
	return (1);
}

static void result(char *name, int ok)
{
	if (ok)
		printf("\033[32m[OK]\033[0m %s\n", name);
	else
		printf("\033[31m[KO]\033[0m %s\n", name);
}

static void test_single(char *name, t_single_op op,
	int on_b, int *expected, int size)
{
	int		values_a[] = {1, 2, 3};
	int		values_b[] = {4, 5, 6};
	t_stack	a;
	t_stack	b;
	int		ok;

	init_stack(&a, values_a, 3);
	init_stack(&b, values_b, 3);
	if (on_b)
		op(&b);
	else
		op(&a);
	ok = check_stack(&a, on_b ? values_a : expected,
			on_b ? 3 : size);
	ok = ok && check_stack(&b, on_b ? expected : values_b,
			on_b ? size : 3);
	result(name, ok);
	free_stack(&a);
	free_stack(&b);
}

static void test_double(char *name, t_double_op op,
	int *expected_a, int size_a, int *expected_b, int size_b)
{
	int		values_a[] = {1, 2, 3};
	int		values_b[] = {4, 5, 6};
	t_stack	a;
	t_stack	b;
	int		ok;

	init_stack(&a, values_a, 3);
	init_stack(&b, values_b, 3);
	op(&a, &b);
	ok = check_stack(&a, expected_a, size_a);
	ok = ok && check_stack(&b, expected_b, size_b);
	result(name, ok);
	free_stack(&a);
	free_stack(&b);
}

int	main(void)
{
	int	swap_a[] = {2, 1, 3};
	int	swap_b[] = {5, 4, 6};
	int	both_a[] = {2, 1, 3};
	int	both_b[] = {5, 4, 6};
	int	push_a[] = {4, 1, 2, 3};
	int	push_b[] = {5, 6};
	int	push_b_a[] = {2, 3};
	int	push_b_b[] = {1, 4, 5, 6};
	int	rotate_a[] = {2, 3, 1};
	int	rotate_b[] = {5, 6, 4};
	int	reverse_a[] = {3, 1, 2};
	int	reverse_b[] = {6, 4, 5};

	printf("\n--- SWAP ---\n");
	test_single("sa", sa, 0, swap_a, 3);
	test_single("sb", sb, 1, swap_b, 3);
	test_double("ss", ss, both_a, 3, both_b, 3);

	printf("\n--- PUSH ---\n");
	test_double("pa", pa, push_a, 4, push_b, 2);
	test_double("pb", pb, push_b_a, 2, push_b_b, 4);

	printf("\n--- ROTATE ---\n");
	test_single("ra", ra, 0, rotate_a, 3);
	test_single("rb", rb, 1, rotate_b, 3);
	test_double("rr", rr, rotate_a, 3, rotate_b, 3);

	printf("\n--- REVERSE ROTATE ---\n");
	test_single("rra", rra, 0, reverse_a, 3);
	test_single("rrb", rrb, 1, reverse_b, 3);
	test_double("rrr", rrr, reverse_a, 3, reverse_b, 3);
	return (0);
}
