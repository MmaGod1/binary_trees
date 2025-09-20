#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root after rotation, or NULL if it fails
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;           /* Step 1: pivot */
	tree->left = pivot->right;    /* Step 2: move pivot’s right child */

	if (pivot->right != NULL)     /* update parent of moved child */
		pivot->right->parent = tree;

	pivot->parent = tree->parent; /* Step 3: pivot takes tree’s parent */

	if (tree->parent != NULL)     /* update parent’s child link */
	{
		if (tree == tree->parent->left)
			tree->parent->left = pivot;
		else
			tree->parent->right = pivot;
	}

	pivot->right = tree;          /* Step 4: tree becomes pivot’s right */
	tree->parent = pivot;

	return (pivot);               /* Step 5: pivot is new root */
}
