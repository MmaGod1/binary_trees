#include "binary_trees.h"
#include <limits.h>

/**
 * height - Computes the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree, 0 if NULL
 */
int height(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	return (1 + (left_h > right_h ? left_h : right_h));
}

/**
 * is_bst_util - Helper to check if a tree is a valid BST
 * @tree: Pointer to current node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_util(tree->left, min, tree->n) &&
			is_bst_util(tree->right, tree->n, max));
}

/**
 * is_avl_util - Helper to check if tree is AVL
 * @tree: Pointer to current node
 *
 * Return: 1 if AVL, 0 otherwise
 */
int is_avl_util(const binary_tree_t *tree)
{
	int left_h, right_h, balance;

	if (tree == NULL)
		return (1);

	left_h = height(tree->left);
	right_h = height(tree->right);
	balance = left_h - right_h;

	if (balance < -1 || balance > 1)
		return (0);

	return (is_avl_util(tree->left) && is_avl_util(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_bst_util(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_avl_util(tree));
}
