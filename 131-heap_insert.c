#include "binary_trees.h"

/* Forward declarations */
heap_t *find_insertion_parent(heap_t *root);
void bubble_up(heap_t *node);

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	/* If heap is empty, new node becomes root */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Find the parent where we should insert the new node */
	parent = find_insertion_parent(*root);
	if (parent == NULL)
		return (NULL);

	/* Insert as left or right child */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Restore heap property */
	bubble_up(new_node);

	return (new_node);
}

/**
 * find_insertion_parent - Finds the parent where next node should be inserted
 * Uses level-order traversal (queue).
 * @root: Pointer to root of heap
 *
 * Return: Pointer to parent node, or NULL on failure
 */
heap_t *find_insertion_parent(heap_t *root)
{
	const heap_t **queue;
	size_t front = 0, rear = 0;
	heap_t *current;

	if (root == NULL)
		return (NULL);

	queue = malloc(sizeof(heap_t *) * 1024);
	if (queue == NULL)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		current = (heap_t *)queue[front++];

		/* If this node has a free spot, return it */
		if (current->left == NULL || current->right == NULL)
		{
			free(queue);
			return (current);
		}

		/* Otherwise enqueue children */
		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}

	free(queue);
	return (NULL);
}

/**
 * bubble_up - Restores heap property by swapping node upwards
 * @node: Newly inserted node
 */
void bubble_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		/* Swap values */
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		/* Move up */
		node = node->parent;
	}
}
