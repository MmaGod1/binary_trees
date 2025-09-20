#include "binary_trees.h"

/**
 * heapify_down - Rebuilds the heap property after extraction
 * @node: Pointer to the current node
 *
 * Return: Nothing
 */
void heapify_down(heap_t *node)
{
	heap_t *largest;
	int temp;

	while (node && node->left)
	{
		largest = node->left;
		if (node->right && node->right->n > node->left->n)
			largest = node->right;

		if (largest->n > node->n)
		{
			/* swap values */
			temp = node->n;
			node->n = largest->n;
			largest->n = temp;

			node = largest;
		}
		else
			break;
	}
}

/**
 * get_last_node - Finds the last node in level-order
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *last = NULL;
	queue_t *q = NULL, *tmp;

	if (!root)
		return (NULL);

	/* simple queue with linked list */
	q = malloc(sizeof(*q));
	if (!q)
		return (NULL);
	q->node = root;
	q->next = NULL;

	while (q)
	{
		last = q->node;
		if (last->left)
		{
			tmp = malloc(sizeof(*tmp));
			tmp->node = last->left;
			tmp->next = NULL;
			queue_push(&q, tmp);
		}
		if (last->right)
		{
			tmp = malloc(sizeof(*tmp));
			tmp->node = last->right;
			tmp->next = NULL;
			queue_push(&q, tmp);
		}
		queue_pop(&q);
	}
	return (last);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root of the heap
 *
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *parent;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	/* If only one node */
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Find last node in level-order */
	last = get_last_node(*root);

	/* Replace root value with last node’s value */
	(*root)->n = last->n;

	/* Disconnect last node from its parent */
	parent = last->parent;
	if (parent->right == last)
		parent->right = NULL;
	else
		parent->left = NULL;

	free(last);

	/* Restore heap property */
	heapify_down(*root);

	return (value);
}
