#include "binary_trees.h"

/**
 * binary_tree_height - Measures height of a tree
 * @tree: pointer to root
 *
 * Return: height in edges, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	/* Leaf node has height 0 */
	if (!tree->left && !tree->right)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (1 + (left > right ? left : right));
}

/**
 * binary_tree_balance - Measures balance factor
 * @tree: Pointer to node
 *
 * Return: left_height - right_height
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ( (int)binary_tree_height(tree->left) -
	         (int)binary_tree_height(tree->right) );
}
