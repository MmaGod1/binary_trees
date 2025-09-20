#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new_node = avl_insert_recursive(*tree, value);
	if (new_node == NULL)
		return (NULL);

	/* After recursive insert, rebalance */
	*tree = avl_rebalance(*tree);

	return (new_node);
}

/**
 * avl_insert_recursive - Recursively inserts a value in an AVL tree
 * @root: Pointer to current root
 * @value: Value to insert
 *
 * Return: Pointer to created node or NULL if duplicate
 */
avl_t *avl_insert_recursive(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
	{
		if (root->left)
		{
			return (avl_insert_recursive(root->left, value));
		}
		else
		{
			root->left = binary_tree_node(root, value);
			return (root->left);
		}
	}
	else if (value > root->n)
	{
		if (root->right)
		{
			return (avl_insert_recursive(root->right, value));
		}
		else
		{
			root->right = binary_tree_node(root, value);
			return (root->right);
		}
	}
	/* Duplicates are not allowed */
	return (NULL);
}

/**
 * avl_rebalance - Rebalances an AVL tree after insertion
 * @root: Pointer to root of the subtree
 *
 * Return: Pointer to new root
 */
avl_t *avl_rebalance(avl_t *root)
{
	int balance;

	if (root == NULL)
		return (NULL);

	balance = binary_tree_balance(root);

	/* Left Heavy */
	if (balance > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	/* Right Heavy */
	if (balance < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
