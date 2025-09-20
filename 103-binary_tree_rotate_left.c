#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root after rotation, or NULL if it fails
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;          /* Step 1: pivot */
	tree->right = pivot->left;    /* Step 2: move pivot’s left child */

	if (pivot->left != NULL)      /* update parent of moved child */
		pivot->left->parent = tree;

	pivot->parent = tree->parent; /* Step 3: pivot takes tree’s parent */

	if (tree->parent != NULL)     /* update parent’s child link */
	{
		if (tree == tree->parent->left)
			tree->parent->left = pivot;
		else
			tree->parent->right = pivot;
	}

	pivot->left = tree;           /* Step 4: tree becomes pivot’s left */
	tree->parent = pivot;

	return (pivot);               /* Step 5: pivot is new root */
}
