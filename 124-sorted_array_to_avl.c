#include "binary_trees.h"

/**
 * sorted_array_to_avl_helper - Recursively builds a balanced AVL tree
 *                               from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Start index of the current subarray
 * @end: End index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the subtree
 */
avl_t *sorted_array_to_avl_helper(int *array, int start,
		int end, avl_t *parent)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);

	node->left = sorted_array_to_avl_helper(array, start, mid - 1, node);
	node->right = sorted_array_to_avl_helper(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds a balanced AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree,
 *         or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, (int)size - 1, NULL));
}
