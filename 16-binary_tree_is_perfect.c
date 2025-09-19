#include "binary_trees.h"

/**
 * find_leaf_depth - Finds the depth of the leftmost leaf in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Depth of the leftmost leaf
 */
int find_leaf_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * check_perfect - Recursively checks if a binary tree is perfect
 * @tree: Pointer to the current node being checked
 * @depth: Depth where all leaves should be located
 * @level: Current level of the node
 *
 * Return: 1 if the subtree rooted at this node is perfect, 0 otherwise
 */
int check_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	/* If this is a leaf node */
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	/* If the node has only one child */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Recursively check both subtrees */
	return (check_perfect(tree->left, depth, level + 1) &&
			check_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = find_leaf_depth(tree);
	return (check_perfect(tree, depth, 0));
}
