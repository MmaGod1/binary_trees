#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	size_t front = 0, rear = 0;
	int seen_null = 0;

	if (tree == NULL)
		return (0);

	/* Allocate a big queue (for simplicity) */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		if (current == NULL)
		{
			seen_null = 1;
		}
		else
		{
			if (seen_null) /* If we saw NULL earlier, but now see a node */
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	free(queue);
	return (1);
}
