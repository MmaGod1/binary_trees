#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the BST
 *
 * Return: Pointer to the node containing the value,
 *         or NULL if not found or tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree); /* Found node */

	if (value < tree->n)
		return (bst_search(tree->left, value));  /* Search left */
	else
		return (bst_search(tree->right, value)); /* Search right */
}
