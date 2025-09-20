#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/* Forward declarations */
int binary_tree_is_complete(const binary_tree_t *tree);
int binary_tree_is_heap_helper(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Must be complete AND satisfy heap property */
	if (!binary_tree_is_complete(tree))
		return (0);

	return (binary_tree_is_heap_helper(tree));
}

/**
 * binary_tree_is_heap_helper - Recursively checks Max-Heap property
 * @tree: Pointer to the root node
 *
 * Return: 1 if subtree satisfies heap property, 0 otherwise
 */
int binary_tree_is_heap_helper(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	/* Check left child */
	if (tree->left != NULL)
	{
		if (tree->n < tree->left->n)
			return (0);
	}

	/* Check right child */
	if (tree->right != NULL)
	{
		if (tree->n < tree->right->n)
			return (0);
	}

	/* Recursively check children */
	return (binary_tree_is_heap_helper(tree->left) &&
			binary_tree_is_heap_helper(tree->right));
}
