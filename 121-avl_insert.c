#include "binary_trees.h"

/**
 * avl_rebalance - Rebalances a subtree if unbalanced
 * @node: Pointer to the root of the subtree
 * @value: Value just inserted (used to determine rotation case)
 *
 * Return: Pointer to the new root of the subtree
 */
avl_t *avl_rebalance(avl_t *node, int value)
{
	int balance;

	balance = binary_tree_balance(node);

	/* Left heavy */
	if (balance > 1)
	{
		if (value < node->left->n)
			node = binary_tree_rotate_right(node);       /* Left-Left case */
		else
		{
			node->left = binary_tree_rotate_left(node->left); /* Left-Right case */
			node = binary_tree_rotate_right(node);
		}
	}
	/* Right heavy */
	if (balance < -1)
	{
		if (value > node->right->n)
			node = binary_tree_rotate_left(node);        /* Right-Right case */
		else
		{
			node->right = binary_tree_rotate_right(node->right); /* Right-Left case */
			node = binary_tree_rotate_left(node);
		}
	}
	return (node);
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* BST insertion */
	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			node = avl_insert(&(*tree)->left, value);
		else
			node = (*tree)->left = binary_tree_node(*tree, value);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			node = avl_insert(&(*tree)->right, value);
		else
			node = (*tree)->right = binary_tree_node(*tree, value);
	}
	else
		return (NULL); /* Ignore duplicates */

	/* Rebalance the tree if necessary */
	*tree = avl_rebalance(*tree, value);

	return (node);
}
