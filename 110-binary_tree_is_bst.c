#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Recursively checks if tree is a BST using min/max limits
 * @tree: Pointer to the current node
 * @min: Minimum allowed value for current node
 * @max: Maximum allowed value for current node
 *
 * Return: 1 if BST, 0 otherwise
 */
static int is_bst_helper(const binary_tree_t *tree, long min, long max)
{
	if (!tree)
		return (1); /* empty tree is BST */

	if (tree->n <= min || tree->n >= max)
		return (0); /* violates BST property */

	/* check subtrees with updated limits */
	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst_helper(tree, LONG_MIN, LONG_MAX));
}
