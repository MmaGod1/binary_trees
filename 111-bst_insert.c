#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert in the BST
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent = NULL, *current = NULL, *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	/* If tree is empty, create root */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;

	/* Traverse the tree to find correct spot */
	while (current != NULL)
	{
		parent = current;

		if (value == current->n)
			return (NULL); /* Ignore duplicates */

		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	/* Create new node with parent link */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* Attach new_node to the correct side of parent */
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
