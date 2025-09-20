#include "binary_trees.h"


avl_t *sorted_array_to_avl_recursive(int *array, size_t start, size_t end,
		avl_t *parent);
/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_array_to_avl_recursive(array, 0, size - 1, NULL));
}

/**
 * sorted_array_to_avl_recursive - Recursively builds AVL tree
 * @array: Pointer to array
 * @start: Start index of the current subarray
 * @end: End index of the current subarray
 * @parent: Pointer to parent node
 *
 * Return: Pointer to root of subtree
 */
avl_t *sorted_array_to_avl_recursive(int *array, size_t start, size_t end,
		avl_t *parent)
{
	avl_t *root;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = sorted_array_to_avl_recursive(array, start, mid - 1, root);
	root->right = sorted_array_to_avl_recursive(array, mid + 1, end, root);

	return (root);
}
