#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root after deletion and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tmp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		/* Node found */
		if (root->left == NULL || root->right == NULL)
		{
			tmp = root->left ? root->left : root->right;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}
		else
		{
			/* Node with 2 children → replace with inorder successor */
			avl_t *succ = root->right;

			while (succ->left)
				succ = succ->left;

			root->n = succ->n;
			root->right = avl_remove(root->right, succ->n);
		}
	}

	/* Rebalance */
	return (avl_rebalance(root));
}

/**
 * avl_rebalance - Rebalances an AVL tree after insertion/removal
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
