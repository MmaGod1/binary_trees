#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *                          traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	size_t front = 0, rear = 0, size = 0;
	const binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;

	/*
	 * Maximum possible nodes in queue = total size of tree.
	 * Allocate a big array
	 */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return;

	queue[rear++] = tree;
	size++;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
}
