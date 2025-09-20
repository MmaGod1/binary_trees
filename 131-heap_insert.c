#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to root
 *
 * Return: Number of nodes, 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, **queue, *current;
	size_t front = 0, rear = 0, size = 0;
	int tmp;

	if (!root)
		return (NULL);
	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	size = binary_tree_size(*root);
	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[rear++] = *root;
	while (front < rear)
	{
		current = queue[front++];
		if (!current->left || !current->right)
		{
			new_node = binary_tree_node(current, value);
			if (!current->left)
				current->left = new_node;
			else
				current->right = new_node;
			break;
		}
		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}
	free(queue);

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}
	return (new_node);
}
