#include "binary_trees.h"

/**
 * is_bst_helper - Helper to validate BST using range limits
 * @tree: Pointer to the current node
 * @min: Smallest allowed value
 * @max: Largest allowed value
 *
 * Return: 1 if subtree is a valid BST, otherwise 0
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	/* Node value must be within the allowed range */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Recurse left with updated max, right with updated min */
	return (is_bst_helper(tree->left, min, tree->n) &&
			is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
