#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	/* Create the new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* If parent already has a left child */
	if (parent->left != NULL)
	{
		/* New node adopts old left child */
		new_node->left = parent->left;

		/* Old left child updates its parent */
		parent->left->parent = new_node;
	}

	/* Attach new node as parent's left child */
	parent->left = new_node;

	return (new_node);
}
