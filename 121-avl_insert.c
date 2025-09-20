#include "binary_trees.h"

/* Forward declaration */
avl_t *avl_balance(avl_t *node);

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
		node = (*tree)->left ? avl_insert(&(*tree)->left, value) :
			binary_tree_node(*tree, value);
	else if (value > (*tree)->n)
		node = (*tree)->right ? avl_insert(&(*tree)->right, value) :
			binary_tree_node(*tree, value);
	else
		return (NULL); /* duplicate ignored */

	/* Balance this node */
	*tree = avl_balance(*tree);

	return (node);
}


#include "binary_trees.h"

/**
 * avl_balance - Balances an AVL node if unbalanced
 * @node: Pointer to the node to balance
 *
 * Return: New root after rotation
 */
avl_t *avl_balance(avl_t *node)
{
	int balance = binary_tree_balance(node);

	/* Left heavy */
	if (balance > 1)
	{
		if (binary_tree_balance(node->left) >= 0)
			node = binary_tree_rotate_right(node);      /* Left-Left */
		else
		{
			node->left = binary_tree_rotate_left(node->left); /* Left-Right */
			node = binary_tree_rotate_right(node);
		}
	}
	/* Right heavy */
	else if (balance < -1)
	{
		if (binary_tree_balance(node->right) <= 0)
			node = binary_tree_rotate_left(node);       /* Right-Right */
		else
		{
			node->right = binary_tree_rotate_right(node->right); /* Right-Left */
			node = binary_tree_rotate_left(node);
		}
	}

	return (node);
}
