#include "binary_trees.h"

/**
 * min_value_node - Finds the node with the minimum value in a BST
 * @node: Pointer to the root of the subtree
 *
 * Return: Pointer to the node with minimum value
 */
bst_t *min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @value: Value to remove
 *
 * Return: Pointer to the new root after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n) /* Search left */
		root->left = bst_remove(root->left, value);

	else if (value > root->n) /* Search right */
		root->right = bst_remove(root->right, value);

	else /* Found the node to delete */
	{
		/* Case 1 & 2: one child or none */
		if (root->left == NULL)
		{
			temp = root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		/* Case 3: two children → use in-order successor */
		temp = min_value_node(root->right);

		root->n = temp->n; /* Copy successor value */
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
