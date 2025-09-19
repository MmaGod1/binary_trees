#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* A leaf node has height 0 */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	/* Recursively get height of left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Take the larger height and add 1 for the edge to the child */
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
